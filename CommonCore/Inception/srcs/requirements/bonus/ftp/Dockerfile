FROM debian:bullseye

RUN apt update && \
    apt install -y vsftpd && \
    mkdir -p /var/run/vsftpd/empty && \
    apt clean && rm -rf /var/lib/apt/lists/*

COPY vsftpd.conf /etc/vsftpd.conf

RUN useradd -m -d /var/www/html -s /bin/bash ftpuser && \
    echo "ftpuser:ftp_password" | chpasswd

RUN chown -R ftpuser:ftpuser /var/www/html

EXPOSE 21
EXPOSE 30000-30009

CMD ["vsftpd", "/etc/vsftpd.conf"]
