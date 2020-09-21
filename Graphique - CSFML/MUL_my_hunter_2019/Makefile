##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Create your make file ok
##

SRC     =	main.c	\
			game_core.c\
			./menu/menu.c	\
			./menu/event_menu.c	\
			./menu/menu_res.c	\
			./menu/menu_res_core.c	\
			./game/game_res_core.c\
			./game/game_res_01.c\
			./game/game_res_02.c\
			./game/transition.c\
			./game/game_01.c\
			./game/enemies_01_management_01.c\
			./game/enemies_01_management_02.c\
			./game/game_events.c\


NAME        =        my_hunter

MAKE_LIB    =        make -C lib/my/

all:
	$(MAKE_LIB)
	gcc -o $(NAME) $(SRC) -l csfml-system -l csfml-graphics -l csfml-audio -L./lib/ -lmy -I./include -g3
clean:
	find -type f -name "*.o" -delete

fclean: clean
	rm -f $(NAME)
	find -type f -name "*.a" -delete

rebuild_lib: fclean
	$(MAKE_LIB)

re:	fclean all