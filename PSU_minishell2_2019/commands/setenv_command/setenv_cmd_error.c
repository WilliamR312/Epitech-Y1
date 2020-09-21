/*
** EPITECH PROJECT, 2020
** SETENV_CMD_ERROR
** File description:
** manage setenv commmand error
*/

#include <unistd.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

int setenv_cmd_error(shell_t *shell_d)
{
    if (shell_d->command.nbr > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return (1);
    }
    if (is_alpha(shell_d->command.tab[1][0]) == 0 ) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return (1);
    }
    if (my_str_isalpha(shell_d->command.tab[1]) == 0 || \
    my_str_isnum(shell_d->command.tab[1]) == 0) {
        my_putestr("setenv:");
        my_putestr(" Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    return (0);
}