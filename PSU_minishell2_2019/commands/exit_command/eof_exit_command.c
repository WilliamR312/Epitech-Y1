/*
** EPITECH PROJECT, 2020
** EOF_EXIT_COMMAND
** File description:
** manage eof exit
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

void eof_exit_command(shell_t *shell_d)
{
    my_putstr("exit\n");
    my_free_strtab(shell_d->env.tab);
    exit(0);
}