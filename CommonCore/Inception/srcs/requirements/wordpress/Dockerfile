FROM debian:bullseye

RUN apt update && apt upgrade -y && \
	apt install -y lsb-release apt-transport-https ca-certificates wget gnupg && \
	wget -qO - https://packages.sury.org/php/apt.gpg | apt-key add - && \
	echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" > /etc/apt/sources.list.d/php.list && \
	apt update && \
	apt install -y php8.2-fpm php8.2-mysqli curl

COPY www.conf /etc/php/8.2/fpm/pool.d

COPY script.sh .
RUN chmod +x script.sh

RUN mkdir -p /run/php

CMD ["./script.sh"]
