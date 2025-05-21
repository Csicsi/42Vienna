#!/bin/bash

CREDENTIALS=$(cat /run/secrets/wp_credentials)
FTP_USER=$(echo "$CREDENTIALS" | sed -n 18p)
FTP_PASSWORD=$(echo "$CREDENTIALS" | sed -n 20p)

useradd -m -d /var/www/html -s /bin/bash "$FTP_USER"

echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

mkdir -p /var/www/html/wp-content/uploads

chown -R root:"$FTP_USER" /var/www/html
chmod -R 2775 /var/www/html
chmod -R 2777 /var/www/html/wp-content/uploads

exec vsftpd /etc/vsftpd.conf
