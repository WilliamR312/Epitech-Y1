##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## Compiles my library and puts in in lib, moves my header in include
##

SRC		=	solver.c \
			astar.c \
			compute_power_distance.c \
			find_best_node.c	\
			open_element.c	\
			close_element.c	\
			create_node.c	\
			create_dir_node.c	\
			open_map.c

NAME	=		solver

OBJ		=		$(SRC:.c=.o)

CFLAGS	+=		-Wextra -Wall -pedantic -W -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f *~
		rm -f *\#
		rm -f *.o

fclean:	clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: clean fclean re all
