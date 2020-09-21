##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Create your make file ok
##

SRC     =	main.c	\
			get_map_1d.c	\
			get_map_2d.c	\
			get_map_2d_count_line.c	\
			game_loop_core.c	\
			move_player.c	\
			move_player_more.c	\
			toolbox.c

NAME        =        my_sokoban

MAKE_LIB    =        make -C lib/my/

all:
	$(MAKE_LIB)
	gcc -o $(NAME) $(SRC) -L./lib/ -lmy -I./include -lncurses -g3
clean:
	find -type f -name "*.o" -delete

fclean: clean
	rm -f $(NAME)
	find -type f -name "*.a" -delete

rebuild_lib: fclean
	$(MAKE_LIB)

re:	fclean all