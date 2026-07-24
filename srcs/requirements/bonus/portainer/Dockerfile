FROM debian:bookworm

# 1. Install download and SSL certificates tools
RUN apt-get update && apt-get install -y \
    wget \
    tar \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# 2. Download and extract Portainer binary
RUN wget https://github.com/portainer/portainer/releases/download/2.19.4/portainer-2.19.4-linux-amd64.tar.gz \
    && tar -xvf portainer-2.19.4-linux-amd64.tar.gz \
    && rm portainer-2.19.4-linux-amd64.tar.gz

# 3. Expose Portainer UI port
EXPOSE 9000

# 4. Run the standalone executable
ENTRYPOINT ["/portainer/portainer"]
