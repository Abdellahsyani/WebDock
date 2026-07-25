COMPOSE_FILE = ./srcs/docker-compose.yml

DATA_PATH = $(HOME)/data

all: setup
	docker compose -f $(COMPOSE_FILE) up -d --build

setup:
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress

down:
	docker compose -f $(COMPOSE_FILE) down

