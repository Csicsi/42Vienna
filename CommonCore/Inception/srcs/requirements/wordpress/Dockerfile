FROM debian:bullseye

RUN apt update && apt install -y \
	php7.4-fpm \
	php7.4-mysqli \
	php7.4-redis \
	curl \
	redis-tools \
	ftp

COPY www.conf /etc/php/7.4/fpm/pool.d/

COPY ./tools/script.sh .
RUN chmod +x script.sh

RUN mkdir -p /run/php

CMD ["./script.sh"]
