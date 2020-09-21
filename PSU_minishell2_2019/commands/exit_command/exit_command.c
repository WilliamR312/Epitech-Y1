/*
** EPITECH PROJECT, 2020
** IS_SPACE
** File description:
** if is space char
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static void free_exit(shell_t *shell_d)
{
    my_free_strtab(shell_d->env.tab);
    for (int i = 0; shell_d->command.general_tab[i]; i++)
        my_free_strtab(shell_d->command.general_tab[i]);
    free(shell_d->command.general_tab);
    if (shell_d->builtins.old_pwd != NULL)
        free(shell_d->builtins.old_pwd);
}

static void error_syntax(void)
{
    write(2, "exit: Expression Syntax.\n", 25);
}

static void exit_and_one_other(shell_t *shell_d)
{
    int exit_value = 0;

    if (my_str_isnum(shell_d->command.tab[1]) == 0) {
        error_syntax();
    } else {
        exit_value = my_getnbr(shell_d->command.tab[1]);
        free_exit(shell_d);
        exit(exit_value);
    }
}

void exit_command(shell_t *shell_d)
{
    if (my_strcmp("exit", shell_d->command.tab[0]) == 1) {
        if (shell_d->command.nbr == 1) {
            my_putstr("exit\n");
            free_exit(shell_d);
            exit(0);
        }
        else if (shell_d->command.nbr == 2)
            exit_and_one_other(shell_d);
        else
            error_syntax();
    }
}