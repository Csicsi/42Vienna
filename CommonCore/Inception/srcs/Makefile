
all: up

up:
	mkdir -p /home/dcsicsak/web
	mkdir -p /home/dcsicsak/mariadb
	docker-compose up -d

build:
	mkdir -p /home/dcsicsak/web
	mkdir -p /home/dcsicsak/mariadb
	docker-compose up --build -d

down:
	docker-compose down

re: clean build

stop:
	docker-compose stop

start:
	docker-compose start

restart:
	docker-compose restart

clean: down
	sudo rm -rf /home/dcsicsak/data/web/*
	sudo rm -rf /home/dcsicsak/data/mariadb/*

.PHONY: all up build down re stop start restart clean
