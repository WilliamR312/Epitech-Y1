/*
** EPITECH PROJECT, 2020
** initialization
** File description:
** initialize shell
*/

#include "stddef.h"
#include "my.h"
#include "mysh.h"
#include "struct.h"

void initialization(shell_t *shell_d)
{
    shell_d->args_exec.args = NULL;
    shell_d->args_exec.path = NULL;
    shell_d->args_exec.nbr = 0;
    shell_d->command.gtab_size = 0;
    shell_d->command.general_tab = NULL;
    shell_d->command.nbr = 0;
    shell_d->command.tab = NULL;
    shell_d->env.nbr = 0;
    shell_d->env.tab = NULL;
    shell_d->path_cmd.nbr = 0;
    shell_d->path_cmd.tab = NULL;
    shell_d->builtins.old_pwd = NULL;
}