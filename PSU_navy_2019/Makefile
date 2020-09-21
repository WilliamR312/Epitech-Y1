##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	./src/main.c \
		./src/first_player.c \
		./src/second_player.c \
		./src/init_map_first_player.c \
		./src/place_boat.c \
		./src/display_map.c \
		./src/game.c \
		./src/signal.c \
		./src/map.c \
		./src/count_signal.c \
		./src/check_result.c \
		./src/free_ressources.c \
		./src/change_all_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

all:	NAME

NAME:
	cd lib/my/ && make
	gcc $(SRC) -o $(NAME) -L./lib/my -lmy -I./include

clean:
	rm -f $(OBJ)
	cd lib/my/

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all
