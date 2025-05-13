FROM debian:latest

RUN apt update && apt upgrade -y && \
    apt install -y mariadb-server

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/

COPY tools/script.sh /docker-entrypoint-initdb.d/script.sh

RUN chmod +x /docker-entrypoint-initdb.d/script.sh

RUN mkdir -p /run/mysqld

CMD ["mysqld"]
