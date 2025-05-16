FROM debian:bullseye

RUN apt update && apt upgrade -y && \
    apt install -y mariadb-server

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/script.sh /script.sh

RUN chmod +x /script.sh && \
    mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld

CMD ["/script.sh"]
