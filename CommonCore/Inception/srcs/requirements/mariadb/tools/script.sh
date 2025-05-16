#!/bin/sh

DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password | sed -n 1p)
DB_PASSWORD=$(cat /run/secrets/db_passwords | sed -n 1p)
CREDENTIALS=$(cat /run/secrets/wp_credentials)
DB_USER=$(echo "$CREDENTIALS" | sed -n 10p)
DB_DATABASE=$(echo "$CREDENTIALS" | sed -n 12p)

if [ ! -d /var/lib/mysql/mysql ]; then
    mariadb-install-db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
fi

mysqld --skip-networking --user=mysql &
pid="$!"

until mariadb-admin ping --silent; do
  sleep 1
done

mariadb -u root <<EOF
CREATE DATABASE IF NOT EXISTS ${DB_DATABASE};
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DB_DATABASE}.* TO '${DB_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

kill "$pid"
wait "$pid"

exec mysqld
