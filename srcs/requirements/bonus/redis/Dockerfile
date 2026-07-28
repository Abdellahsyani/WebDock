FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    redis-server \
    && rm -rf /var/lib/apt/lists/*

# Copy your script into the container
COPY ./conf/redis.conf /etc/redis/redis.conf

EXPOSE 6379

# --protected-mode no :  tells redis I am running you inside a safe networking don't panic \
#   if I don't do that it will listen only on localhost
ENTRYPOINT ["redis-server", "/etc/redis/redis.conf", "--protected-mode", "no"]
