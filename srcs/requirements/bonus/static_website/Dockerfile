FROM debian:bookworm


RUN apt-get update && apt-get install -y \
    nodejs npm \
    && rm -rf /var/lib/apt/lists/*

RUN npm install -g http-server

RUN mkdir -p /var/www/html

COPY ./html /var/www/html/website

WORKDIR /var/www/html

EXPOSE 3000

ENTRYPOINT ["http-server", "-p", "3000"]
