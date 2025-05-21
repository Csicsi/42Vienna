FROM debian:bullseye

RUN apt update && \
    apt install -y redis-server && \
    apt clean && rm -rf /var/lib/apt/lists/*

EXPOSE 6379

CMD ["redis-server", "--protected-mode", "no"]
