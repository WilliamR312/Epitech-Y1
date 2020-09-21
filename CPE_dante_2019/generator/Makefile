##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## Compiles my library and puts in in lib, moves my header in include
##

SRC		=	generator.c \
			generate_empty_maze.c \
			toolbox.c \
			check_group.c \
			kruskal_algorithm.c \
			random_direction.c \
			update_ways.c \
			random_direction_imperfect.c \
			imperfect.c \
			wanted_group.c

NAME	=		generator

OBJ		=		$(SRC:.c=.o)

CFLAGS	+=		-Wextra -Wall -pedantic -W -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc $(OBJ) -o $(NAME) $(CFLAGS)

gdb:
	gcc $(CFLAG) -g3 $(SRC) -o$(NAME); gdb $(NAME)

clean:
		rm -f $(OBJ)
		rm -f *~
		rm -f *\#
		rm -f *.o

fclean:	clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: clean fclean re all
