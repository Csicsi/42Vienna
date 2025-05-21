FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    php-cli php-mbstring php-mysqli php-pdo php-mysql php-json curl \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

RUN curl -L https://www.adminer.org/latest.php -o index.php

COPY ./tools/script.sh .
RUN chmod +x script.sh

CMD ["./script.sh"]
