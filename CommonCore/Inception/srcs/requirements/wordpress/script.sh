#!/bin/bash

cd /var/www/html

if [ ! -f wp-cli.phar ]; then
  curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
  chmod +x wp-cli.phar
fi

if [ ! -f index.php ]; then
  ./wp-cli.phar core download --allow-root
fi

if [ ! -f wp-config.php ]; then
  ./wp-cli.phar config create \
    --dbname=wordpress \
    --dbuser=wpuser \
    --dbpass=password \
    --dbhost=mariadb \
    --allow-root
fi

if ! ./wp-cli.phar core is-installed --allow-root; then
  ./wp-cli.phar core install \
    --url=localhost \
    --title=inception \
    --admin_user=admin \
    --admin_password=admin \
    --admin_email=admin@admin.com \
    --allow-root
fi

php-fpm8.2 -F
