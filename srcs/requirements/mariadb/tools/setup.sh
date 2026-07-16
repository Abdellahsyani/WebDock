#!/bin/bash

# Start the MariaDB service in the background temporarily
service mariadb start 

# Wait a few seconds for the database to fully boot up
sleep 5

# Check if the database folder already exists on the hard drive
if [ ! -d "/var/lib/mysql/${SQL_DATABASE}" ]; then
    echo "Initializing database for the first time..."
    mariadb -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
    mariadb -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
    mariadb -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
    mariadb -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
    mariadb -e "FLUSH PRIVILEGES;"
    echo "Database initialization complete."
else
    echo "Database already exists. Skipping initialization."
fi

# Shut down the background service cleanly
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown

# Start MariaDB in the foreground (PID 1) to keep the container alive
echo "MariaDB is starting in the foreground..."
exec mysqld_safe
