FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    wget \
    php \
    php-mysql \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/html

RUN wget "https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php" -O /var/www/html/index.php

RUN chown -R www-data:www-data /var/www/html

EXPOSE 8080

ENTRYPOINT ["php", "-S", "0.0.0.0:8080", "-t", "/var/www/html"]
