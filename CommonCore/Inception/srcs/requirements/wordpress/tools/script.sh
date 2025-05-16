#!/bin/bash

DB_PASSWORD=$(cat /run/secrets/db_passwords | sed -n 1p)
CREDENTIALS=$(cat /run/secrets/wp_credentials)
ADMIN_NAME=$(echo "$CREDENTIALS" | sed -n 2p)
ADMIN_PASSWORD=$(echo "$CREDENTIALS" | sed -n 4p)
DB_NAME=$(echo "$CREDENTIALS" | sed -n 12p)
DB_USER=$(echo "$CREDENTIALS" | sed -n 10p)
DB_HOST=$(echo "$CREDENTIALS" | sed -n 14p)
WP_USER=$(echo "$CREDENTIALS" | sed -n 6p)
WP_USER_PASSWORD=$(echo "$CREDENTIALS" | sed -n 8p)
WP_USER_EMAIL=$(echo "$CREDENTIALS" | sed -n 16p)

cd /var/www/html

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar

./wp-cli.phar core download --allow-root

./wp-cli.phar config create \
  --dbname="$DB_NAME" \
  --dbuser="$DB_USER" \
  --dbpass="$DB_PASSWORD" \
  --dbhost="$DB_HOST" \
  --allow-root

./wp-cli.phar core install \
  --url="$DOMAIN_NAME" \
  --title="$WP_TITLE" \
  --admin_user="$ADMIN_NAME" \
  --admin_password="$ADMIN_PASSWORD" \
  --admin_email="$WP_EMAIL" \
  --allow-root

./wp-cli.phar user create $WP_USER $WP_USER_EMAIL \
  --role=author \
  --user_pass="$WP_USER_PASSWORD" \
  --display_name="$WP_USER" \
  --allow-root

sed -i "s|^listen = .*|listen = ${PHP_HOST}:${PHP_PORT}|" /etc/php/8.2/fpm/pool.d/www.conf

php-fpm8.2 -F
