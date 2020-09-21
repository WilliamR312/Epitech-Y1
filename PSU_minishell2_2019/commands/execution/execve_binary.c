/*
** EPITECH PROJECT, 2020
** EXECVE_BINARY
** File description:
** manage execve with binary
*/

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

static void execve_binary_error(shell_t *shell_d)
{
    if (errno == EACCES) {
        my_putestr(shell_d->command.tab[0]);
        my_putestr(": Permission denied.\n");
    } else {
        my_putestr(shell_d->command.tab[0]);
        my_putestr(": Command not found.\n");
    }
}

void execve_binary(shell_t *shell_d)
{
    if (access(shell_d->command.tab[0], R_OK) == 0) {
        execve(shell_d->command.tab[0], shell_d->args_exec.args, \
        shell_d->env.tab);
    }
    free(shell_d->args_exec.args);
    execve_binary_error(shell_d);
}