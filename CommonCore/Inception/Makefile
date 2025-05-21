
all: up

up:
	sudo mkdir -p /home/dcsicsak/data/web
	sudo mkdir -p /home/dcsicsak/data/mariadb
	docker compose -f srcs/docker-compose.yml up -d

build:
	sudo mkdir -p /home/dcsicsak/data/web
	sudo mkdir -p /home/dcsicsak/data/mariadb
	docker compose -f srcs/docker-compose.yml build wordpress
	docker compose -f srcs/docker-compose.yml up --build -d

down:
	docker compose -f srcs/docker-compose.yml down

re: clean build

stop:
	docker compose -f srcs/docker-compose.yml stop

start:
	docker compose -f srcs/docker-compose.yml start

restart:
	docker compose -f srcs/docker-compose.yml restart

clean: down
	sudo rm -rf /home/dcsicsak/data/web/*
	sudo rm -rf /home/dcsicsak/data/mariadb/*

.PHONY: all up build down re stop start restart clean
