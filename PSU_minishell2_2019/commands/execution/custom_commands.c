/*
** EPITECH PROJECT, 2020
** COMMANDS_CORE
** File description:
** manage commands
*/

#include "my.h"
#include "mysh.h"
#include "struct.h"
#include "tab_functions.h"

int custom_commands(shell_t *shell_d)
{
    for (int cursor = 0; tab_commands[cursor].cmd != 0; cursor++) {
        if (my_strcmp(tab_commands[cursor].cmd, shell_d->command.tab[0])) {
            tab_commands[cursor].f(shell_d);
            return (1);
        }
    }
    return (0);
}