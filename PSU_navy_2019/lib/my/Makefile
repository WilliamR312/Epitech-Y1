##
## EPITECH PROJECT, 2018
## my_printf
## File description:
## Makefile
##

SRC	=	my_putchar.c \
		my_putstr.c \
		my_put_array.c \
		my_putstr_error.c \
		my_put_nbr.c \
		my_put_u_nbr.c \
		my_strlen.c \
		my_getnbr.c \
		verif_if_nbr.c \
		my_get_env.c \
		my_str_to_word_array.c \
		my_strcat_separate.c \
		my_strcmp.c \
		my_atoi.c \
		my_strcat.c \
		clean_str.c \
		my_strcpy_double.c \
		my_realloc_double.c \
		print_base_system.c \
		my_putstr_all.c \
		my_revstr.c

SRC_FOLDER	=	printf/disp_stdarg.c \
				printf/my_printf.c \
				printf/dif_base.c

OBJ	=	$(SRC:.c=.o)

OBJ_FOLDER	=	disp_stdarg.o \
				my_printf.o \
				dif_base.o

NAME	=	libmy.a

all:	NAME

NAME:
	gcc -c $(SRC) $(SRC_FOLDER)
	ar rc $(NAME) $(OBJ) $(OBJ_FOLDER)
	rm *.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re : fclean all
