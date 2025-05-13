
all: up

up:
	mkdir -p /home/dcsicsak/web
	mkdir -p /home/dcsicsak/mariadb
	docker-compose up -d

down:
	docker-compose down

re: clean up

stop:
	docker-compose stop

start:
	docker-compose start

restart:
	docker-compose restart

clean: down
	sudo rm -rf /home/dcsicsak/data/web/*
	sudo rm -rf /home/dcsicsak/data/mariadb/*

.PHONY: all up down re stop start restart clean
