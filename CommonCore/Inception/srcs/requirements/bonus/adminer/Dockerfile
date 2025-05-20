FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    php-cli php-mbstring php-mysqli php-pdo php-mysql php-json curl \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

RUN curl -L https://www.adminer.org/latest.php -o index.php

EXPOSE 8080

CMD ["php", "-S", "0.0.0.0:8080"]
