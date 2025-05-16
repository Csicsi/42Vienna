#!/bin/sh

MYSQL_ROOT_PASSWORD="password"
MYSQL_PASSWORD="password"
MYSQL_USER="wpuser"
MYSQL_DATABASE="wordpress"

if [ ! -d /var/lib/mysql/mysql ]; then
    mariadb-install-db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
fi

mysqld --skip-networking --user=mysql &
pid="$!"

until mariadb-admin ping --silent; do
  sleep 1
done

mariadb -u root <<EOF
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

kill "$pid"
wait "$pid"

exec mysqld
