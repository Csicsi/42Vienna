FROM debian:bullseye

RUN apt update && \
    apt install -y vsftpd && \
    mkdir -p /var/run/vsftpd/empty && \
    apt clean && rm -rf /var/lib/apt/lists/*

COPY vsftpd.conf /etc/vsftpd.conf

COPY ./tools/script.sh .
RUN chmod +x script.sh

CMD ["./script.sh"]
