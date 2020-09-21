##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Create your make file ok
##


all:		make_all

make_all:
			make -C generator/
			make -C solver

demake_all:
			make -C generator fclean
			make -C solver fclean

clean:	demake_all
		rm -f $(OBJ)
		rm -f *~
		rm -f *\#
		rm -f *.o

fclean:	clean
		rm -f

re: 	fclean all

.PHONY: clean fclean re all make_all demake_all
