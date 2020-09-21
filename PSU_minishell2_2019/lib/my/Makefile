##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## Compiles my library and puts in in lib, moves my header in include
##

SRC		=		*.c

OBJ		=		$(SRC:.c=.o)

NAME	=		libmy.a

all:	$(NAME)

$(NAME):
		cp my.h ../../include/
		gcc -c $(SRC)
		ar rc $(NAME) *.o

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: all, clean, fclean, re