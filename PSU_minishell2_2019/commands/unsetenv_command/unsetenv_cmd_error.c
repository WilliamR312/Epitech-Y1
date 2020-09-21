/*
** EPITECH PROJECT, 2020
** UNSETENV_CMD_ERROR
** File description:
** manage unsetenv commmand error
*/

#include <unistd.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

int unsetenv_cmd_error(shell_t *shell_d)
{
    if (shell_d->command.nbr == 1) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (1);
    }
    return (0);
}