#!/bin/bash

mkdir -p /etc/nginx/ssl

openssl req -x509 -nodes -days 365 \
  -newkey rsa:2048 \
  -keyout ${CERTS_KEY} \
  -out ${CERTS_CRT} \
  -subj "/C=AT/ST=Vienna/L=Vienna/O=42Vienna/CN=${DOMAIN_NAME}"

cat <<EOF > /etc/nginx/sites-available/default
server {
	listen 443 ssl;
	root /var/www/html;

	index index.php index.html index.htm index.nginx-debian.html;

	server_name ${DOMAIN_NAME};

	ssl_certificate ${CERTS_CRT};
	ssl_certificate_key ${CERTS_KEY};
	ssl_protocols TLSv1.2 TLSv1.3;

	location / {
		try_files \$uri \$uri/ =404;
	}

	location ~ \.php\$ {
		include snippets/fastcgi-php.conf;
		fastcgi_pass ${PHP_HOST}:${PHP_PORT};
	}
}
EOF

nginx -g "daemon off;"
