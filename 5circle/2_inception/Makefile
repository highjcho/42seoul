all: 
	mkdir -p ./hyunjcho/data
	mkdir -p ./hyunjcho/data/mariadb
	mkdir -p ./hyunjcho/data/wordpress
	docker-compose -f ./srcs/docker-compose.yml up -d --build

clean:
	docker-compose -f ./srcs/docker-compose.yml down


fclean:
	docker-compose -f ./srcs/docker-compose.yml down --rmi all
	docker volume rm $$(docker volume ls -f dangling=true -q)
	rm -rf ./hyunjcho

re:
	@make fclean
	make all

.PHONY: all re clean fclean