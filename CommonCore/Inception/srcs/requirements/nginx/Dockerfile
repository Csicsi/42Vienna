FROM debian:latest

RUN apt update && \
    apt upgrade -y && \
    apt install -y nginx openssl && \
    mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 365 \
      -subj "/C=AT/ST=Vienna/L=Vienna/O=42Vienna/CN=dcsicsak.42.fr" \
      -newkey rsa:2048 \
      -keyout /etc/nginx/ssl/selfsigned.key \
      -out /etc/nginx/ssl/selfsigned.crt

COPY default /etc/nginx/sites-available

CMD ["nginx", "-g", "daemon off;"]
