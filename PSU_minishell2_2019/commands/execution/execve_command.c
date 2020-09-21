/*
** EPITECH PROJECT, 2020
** EXECVE_COMMAND
** File description:
** manage execve with command
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

static int execve_cmd_error(shell_t *shell_d)
{
    my_putestr(shell_d->command.tab[0]);
    my_putestr(": Command not found.\n");
    return (1);
}

static void make_path_exec(shell_t *shell_d, char *command, char *path)
{
    int command_size = my_strlen(command);
    int path_size = my_strlen(path);
    int cursor = 0;

    shell_d->args_exec.path = malloc(sizeof(char) * \
    (path_size + command_size + 2));
    for (cursor = 0; path[cursor]; cursor++)
        shell_d->args_exec.path[cursor] = path[cursor];
    shell_d->args_exec.path[cursor] = '/';
    cursor++;
    for (int i = 0; command[i]; i++, cursor++)
        shell_d->args_exec.path[cursor] = command[i];
    shell_d->args_exec.path[cursor] = '\0';
}

void execve_command(shell_t *shell_d)
{
    int i = -1;

    for (int test = 0; shell_d->path_cmd.tab[test] != NULL && i == -1; \
    test++) {
        make_path_exec(shell_d, shell_d->command.tab[0], \
        shell_d->path_cmd.tab[test]);
        if (access(shell_d->args_exec.path, R_OK) == 0) {
            i = test;
        } else {
            free(shell_d->args_exec.path);
            shell_d->args_exec.path = NULL;
        }
    }
    my_free_strtab(shell_d->path_cmd.tab);
    shell_d->path_cmd.tab = NULL;
    if (i != -1)
        execve(shell_d->args_exec.path, shell_d->args_exec.args, \
        shell_d->env.tab);
    my_free_strtab(shell_d->args_exec.args);
    shell_d->args_exec.args = NULL;
    execve_cmd_error(shell_d);
}