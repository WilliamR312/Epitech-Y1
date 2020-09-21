/*
** EPITECH PROJECT, 2020
** CD_CHECK_ERROR
** File description:
** cd check error commmand
*/

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

void cd_check_error(shell_t *shell_d)
{
    if (errno == EACCES) {
        my_putestr(shell_d->command.tab[1]);
        my_putestr(": Permission denied.\n");
        return;
    }
    if (errno == ENOTDIR) {
        my_putestr(shell_d->command.tab[1]);
        my_putestr(": Not a directory.\n");
        return;
    }
    if (errno == ENOENT) {
        my_putestr(shell_d->command.tab[1]);
        my_putestr(": No such file or directory.\n");
        return;
    }
}