FROM debian:bullseye

RUN apt update && \
    apt install -y redis-server && \
    apt clean && rm -rf /var/lib/apt/lists/*

CMD ["redis-server", "--protected-mode", "no"]
