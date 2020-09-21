##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for defender project
##

GAME = ./src/game

MENU = ./src/menu

SRC	=			./src/main.c \
				$(MENU)/action.c \
				$(MENU)/menu_core.c \
				$(MENU)/init_all.c \
				$(MENU)/init_menu_buttons.c \
				$(MENU)/init_menu_sounds.c \
				$(MENU)/free_menu.c \
				$(MENU)/buttons_actions.c \
				$(GAME)/game_core.c \
				$(GAME)/init_all.c \
				$(GAME)/shop/put_tower_on_map.c \
				$(GAME)/shop/init_block_box.c \
				$(GAME)/shop/init_game_shop.c \
				$(GAME)/shop/init_game_shop_tower.c \
				$(GAME)/shop/draw_game_shop.c \
				$(GAME)/shop/check_shop_actions.c \
				$(GAME)/shop/draw_hand_tower.c	\
				$(GAME)/shop/check_hand_tower_collision.c	\
				$(GAME)/menu_game/game_menu_action.c \
				$(GAME)/menu_game/init_play_pause_button.c \
				$(GAME)/menu_game/init_menu_game.c \
				$(GAME)/menu_game/draw_menu_game.c \
				$(GAME)/enemy/init_enemy.c \
				$(GAME)/enemy/init_dir_box.c \
				$(GAME)/enemy/enemy_animation.c \
				$(GAME)/enemy/draw_wave.c \
				$(GAME)/tower/draw_tower_on_map.c	\
				$(GAME)/tower/tower_attack.c	\
				$(GAME)/action.c \
				$(GAME)/text/init_all_texts.c \
				$(GAME)/text/init_life_text.c \
				$(GAME)/text/init_money_text.c \
				$(GAME)/text/init_score_text.c \
				$(GAME)/text/draw_texts.c	\
				$(GAME)/free_exit/free_game_core.c	\
				$(GAME)/free_exit/free_game_all.c	\
				./src/htp/htp_scene.c \
				./src/result/result_scene.c \
				./src/result/init_result.c \
				./src/scene_intro/init_intro.c

NAME	=		my_defender

OBJ		=		$(SRC:.c=.o)

CFLAGS		+=	-Wextra -Wall -pedantic -I./include -W

LDFLAGS		=	-L./lib/my -lmy

CSFMLF		=	-l csfml-audio -l csfml-system -l csfml-graphics

MAKE_LIB	=	make -C ./lib/my/

DEMAKE_LIB	=	make -C ./lib/my/ fclean

all:	$(OBJ)
		$(MAKE_LIB)
		gcc $(OBJ) -o $(NAME) $(LDFLAGS) $(CSFMLF)

clean:
		$(DEMAKE_LIB)
		rm -f $(OBJ)
		rm -f *~
		rm -f *\#
		rm -f *.o

fclean:	clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: clean, fclean, re, all