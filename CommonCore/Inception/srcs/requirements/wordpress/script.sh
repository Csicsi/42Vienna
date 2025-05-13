#!/bin/bash

CREDENTIALS=$(cat /run/secrets/wp_credentials)
ADMIN_NAME=$(echo "$CREDENTIALS" | sed -n 2p)

cd /var/www/html

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar

./wp-cli.phar core download --allow-root

./wp-cli.phar config create \
  --dbname=wordpress \
  --dbuser=wpuser \
  --dbpass=password \
  --dbhost=mariadb \
  --allow-root

./wp-cli.phar core install \
  --url=https://dcsicsak.42.fr \
  --title="$ADMIN_NAME" \
  --admin_user=dcsicsak \
  --admin_password=admin \
  --admin_email=admin@admin.com \
  --allow-root

./wp-cli.phar user create newuser newuser@example.com \
  --role=author \
  --user_pass=password \
  --display_name="New User" \
  --allow-root

php-fpm8.2 -F
