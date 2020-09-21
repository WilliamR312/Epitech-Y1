/*
** EPITECH PROJECT, 2020
** EXECVE_CORE
** File description:
** manage execve
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

static void make_args_exec(shell_t *shell_d)
{
    int size_command = 0;

    shell_d->args_exec.args = malloc(sizeof(char *) * \
    (shell_d->command.nbr + 1));
    for (int i = 0; i < shell_d->command.nbr; i++) {
        size_command = my_strlen(shell_d->command.tab[i]);
        shell_d->args_exec.args[i] = malloc(sizeof(char) * (size_command + 1));
        shell_d->args_exec.args[i][size_command] = '\0';
        shell_d->args_exec.args[i] = \
        my_strcpy(shell_d->args_exec.args[i], shell_d->command.tab[i]);
    }
    shell_d->args_exec.args[shell_d->command.nbr] = NULL;
}

static int is_binary(char *command)
{
    if (command[0] == '.' && \
    command[1] == '/')
        return (1);
    return (0);
}

void execve_core(shell_t *shell_d)
{
    make_args_exec(shell_d);
    if (is_binary(shell_d->command.tab[0]) == 1)
        execve_binary(shell_d);
    else if (find_path(shell_d->env.tab, "PATH") > 0)
        execve_command(shell_d);
    else {
        for (int i = 0; shell_d->command.tab[0][i]; i++)
            write(2, &shell_d->command.tab[0][i], 1);
        write(2, ": Command not found.\n", 21);
    }
}