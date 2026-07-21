FROM debian:bookworm

# Install ONLY Python 3
RUN apt-get update && apt-get install -y \
    python3 \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/html/website

# Copy your website files
COPY ./html /var/www/html/website

# Navigate directly inside the website folder 
# (This ensures the server finds index.html immediately)
WORKDIR /var/www/html

EXPOSE 3000

# Run Python's built-in HTTP server on port 3000
ENTRYPOINT ["python3", "-m", "http.server", "3000"]
