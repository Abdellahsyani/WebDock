#!/bin/bash

set -e

SQL_PASSWORD=$(cat /run/secrets/db_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
WP_USER_PASSWORD=$(cat /run/secrets/wp_user_password)

# Navigate to the working directory we set in the Dockerfile
cd /var/www/html/wordpress

# Check if WordPress is already installed to prevent reinstalling on every container restart
if [ ! -f "wp-config.php" ]; then
    echo "WordPress configuration not found. Starting setup..."

    # Download the latest WordPress core files
    # --allow-root: force executing command by using linux user
    wp core download --allow-root

    # 2. Wait for the MariaDB container to be fully ready
    # This prevents the classic Inception race condition where WordPress tries to connect 
    # to the database before MariaDB has finished its own initialization.
    echo "Waiting for MariaDB to start..."
    while ! mariadb -h$SQL_HOST -P 3306 -u$SQL_USER -p$SQL_PASSWORD $SQL_DATABASE &>/dev/null; do
        echo "Database is not ready yet. Retrying in 3 seconds..."
        sleep 3
    done
    echo "MariaDB is up and running!"

    # 3. Create the wp-config.php file using credentials from your .env file
    wp config create --allow-root \
        --dbname=$SQL_DATABASE \
        --dbuser=$SQL_USER \
        --dbpass=$SQL_PASSWORD \
        --dbhost="$SQL_HOST:3306" \

    # wp config set WP_HOME "https://$DOMAIN_NAME:1000" --allow-root
    # wp config set WP_SITEURL "https://$DOMAIN_NAME:1000" --allow-root

    # 4. Install WordPress and set up the admin user
    wp core install --allow-root \
      --url="https://$DOMAIN_NAME" \
        --title="$WP_TITLE" \
        --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL


    # 5. Create a standard second user (This is a strict requirement in the Inception subject)
    wp user create --allow-root \
        $WP_USER \
        $WP_USER_EMAIL \
        --user_pass=$WP_USER_PASSWORD \
        --role=author

    # 6. Cofigure Redis Object Cache
    echo "Starting up Redis caching...."

    # Inject the redis container's hostname and port into wp-config.php
    wp config set WP_REDIS_HOST 'redis' --allow-root
    wp config set WP_REDIS_PORT 6379  --raw --allow-root

    # Download and activate the redis object cache plugins
    wp plugin install  redis-cache --activate --allow-root

    # turn the caching engine on
    wp redis enable --allow-root

    echo "WordPress setup completed successfully!"
else
    echo "WordPress is already configured."
fi

# wp rewrite structure:  this is the specific WP-CLi command to change how wordpress generate URLs
# postname:  tells wordpress to generate a simple URLs
# --allow-root:  force wordpress to apply this even we use linux user
wp rewrite structure '/%postname%/' --allow-root

# apply the changes to wordpress and database
wp rewrite flush --allow-root

# 6. Hand over control to PHP-FPM
# The 'exec' command replaces the current bash process (PID 1) with the php-fpm process
wp option update siteurl "https://$DOMAIN_NAME:1000" --allow-root
wp option update home "https://$DOMAIN_NAME:1000" --allow-root
chown -R www-data:www-data /var/www/html/wordpress
echo "Starting PHP-FPM..."
exec /usr/sbin/php-fpm8.2 -F
