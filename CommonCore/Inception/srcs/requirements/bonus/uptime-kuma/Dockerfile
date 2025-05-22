FROM debian:bullseye

RUN apt-get update && apt-get install -y curl ca-certificates gnupg && \
    curl -fsSL https://deb.nodesource.com/setup_18.x | bash - && \
    apt-get install -y nodejs git && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

RUN git clone https://github.com/louislam/uptime-kuma.git .

RUN npm install

RUN npm run build

RUN npm prune --omit=dev

RUN mkdir -p /app/data

COPY ./kuma.db /app/data/kuma.db

EXPOSE 3001

CMD ["node", "server/server.js"]
