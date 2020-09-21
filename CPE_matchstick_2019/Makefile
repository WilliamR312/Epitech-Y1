##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Create your make file ok
##

SRC		=		main.c\
				display_matchstick.c\
				player_action/player_turn.c\
				player_action/p_turn_ask_line.c\
				player_action/p_turn_ask_match.c\
				ai_action/ai_turn.c\
				ai_action/ai_action_regular_g.c\
				ai_action/ai_action_end_g.c\
				ai_action/ai_action_two_lines.c\
				ai_action/two_lines_one.c\
				ai_action/ai_analysis.c


NAME	=		matchstick

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-Wextra -Wall -I./include

LDFLAGS	=		-L./lib/my -lmy

MAKE_LIB    =	make -C ./lib/my/

DEMAKE_LIB	=	make -C ./lib/my/ fclean

all:	$(NAME)

$(NAME):	$(OBJ)
			$(MAKE_LIB)
			gcc $(OBJ) -o $(NAME) $(LDFLAGS) -g3

clean:
		$(DEMAKE_LIB)
		rm -f $(OBJ)
		rm -f *~
		rm -f *\#
		rm -f *.o

fclean:	clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: clean fclean re all