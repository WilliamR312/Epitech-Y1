/*
** EPITECH PROJECT, 2020
** ENV
** File description:
** env commmand
*/

#include <unistd.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

void env_command(shell_t *shell_d)
{
    if (shell_d->command.nbr == 1)
        my_show_str_array(shell_d->env.tab);
    else {
        write(2, "env: Too many arguments.\n", 25);
    }
}