FROM debian:bullseye

RUN apt update && \
    apt upgrade -y && \
    apt install -y nginx openssl

COPY ./tools/script.sh /script.sh
RUN chmod +x /script.sh

CMD ["/script.sh"]
