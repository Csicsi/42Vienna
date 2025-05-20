FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    nginx \
    && rm -rf /var/lib/apt/lists/*

COPY html/ /var/www/html/
CMD ["nginx", "-g", "daemon off;"]
