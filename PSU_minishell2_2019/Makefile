##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Create your make file ok
##

CMD =			commands

EXEC =			$(CMD)/execution

SRC		=		main.c\
				shell_loop.c\
				initialization.c\
				catch_imput.c\
				toolbox/split_args.c\
				toolbox/split_major_args.c\
				toolbox/split_args_limits.c\
				toolbox/is_space_tab.c\
				toolbox/get_path_cmd.c\
				toolbox/get_initial_env.c\
				toolbox/find_path.c\
				toolbox/get_pathline.c\
				$(EXEC)/execve_core.c\
				$(EXEC)/execve_binary.c\
				$(EXEC)/execve_command.c\
				$(EXEC)/custom_commands.c\
				$(CMD)/exit_command/exit_command.c\
				$(CMD)/exit_command/eof_exit_command.c\
				$(CMD)/env_command/env_command.c\
				$(CMD)/cd_command/cd_command.c\
				$(CMD)/cd_command/cd_check_error.c\
				$(CMD)/setenv_command/setenv_command.c\
				$(CMD)/setenv_command/setenv_cmd_error.c\
				$(CMD)/unsetenv_command/unsetenv_command.c\
				$(CMD)/unsetenv_command/unsetenv_cmd_error.c


NAME	=		mysh

OBJ		=		$(SRC:.c=.o)

CFLAGS	+=		-Wextra -Wall -pedantic -I./include

LDFLAGS	=		-L./lib/my -lmy

MAKE_LIB    =	make -C ./lib/my/

DEMAKE_LIB	=	make -C ./lib/my/ fclean

all:	$(NAME)

$(NAME):	$(OBJ)
			$(MAKE_LIB)
			cc $(OBJ) -o $(NAME) $(LDFLAGS)

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