/*
** EPITECH PROJECT, 2020
** CD_COMMAND
** File description:
** cd commmand
*/

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

static void cd_cmd_path(shell_t *shell_d)
{
    char *buf = NULL;
    size_t size = 0;

    shell_d->builtins.old_pwd = getcwd(buf, size);
    free(buf);
    chdir(shell_d->command.tab[1]);
    if (errno != 0)
        cd_check_error(shell_d);
}

static void cd_cmd_prev(shell_t *shell_d)
{
    char *buf = NULL;
    size_t size = 0;

    shell_d->builtins.old_pwd = getcwd(buf, size);
    free(buf);
    buf = getcwd(buf, size);
    chdir("..");
    free(buf);
}

static void cd_cmd_home(shell_t *shell_d)
{
    char *home = NULL;
    size_t size = 0;

    shell_d->builtins.old_pwd = getcwd(home, size);
    free(home);
    home = get_pathline(shell_d->env.tab, "HOME");
    chdir(home);
    free(home);
}

static void cd_cmd_return(shell_t *shell_d)
{
    if (shell_d->builtins.old_pwd != NULL)
        chdir(shell_d->builtins.old_pwd);
    else
        write(2, ": No such file or directory.\n", 29);
}

void cd_command(shell_t *shell_d)
{
    if (shell_d->command.nbr == 1)
        cd_cmd_home(shell_d);
    else if (my_strcmp(shell_d->command.tab[1], "..") == 1)
        cd_cmd_prev(shell_d);
    else {
        if (my_strcmp(shell_d->command.tab[1], "-"))
            cd_cmd_return(shell_d);
        if (my_strcmp(shell_d->command.tab[1], "~"))
            cd_cmd_home(shell_d);
        if (!my_strcmp(shell_d->command.tab[1], "-") && \
        !my_strcmp(shell_d->command.tab[1], "~"))
            cd_cmd_path(shell_d);
    }
}