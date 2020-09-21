##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my makefile
##

SRC     =	main.c	\
			res_load/load_char_res.c\
			res_load/load_sound_res.c\
			res_load/load_text_res.c\
			res_load/manage_load_res.c\
			res_load/load_res_back.c\
			res_load/load_res_map.c\
			res_load/map_load.c\
			game_core.c\
			manage_background.c\
			game_event.c\
			char_management.c\
			map_display.c\
			block_1.c\
			block_2.c\
			exit_free_res.c\
			char_alive.c\
			char_dead.c\
			score_management.c\
			restart_game.c\
			win_game.c\
			character_win.c

NAME        =        my_runner

MAKE_LIB    =        make -C lib/my/

all:
	$(MAKE_LIB)
	gcc -o $(NAME) $(SRC) -l csfml-audio -l csfml-system -l csfml-graphics -L./lib/ -lmy -I./include -g3
clean:
	find -type f -name "*.o" -delete

fclean: clean
	rm -f $(NAME)
	find -type f -name "*.a" -delete

rebuild_lib: fclean
	$(MAKE_LIB)

re:	fclean all