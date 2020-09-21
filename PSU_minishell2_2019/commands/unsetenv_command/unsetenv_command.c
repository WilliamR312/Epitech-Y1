/*
** EPITECH PROJECT, 2020
** ENV
** File description:
** env commmand
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

static int get_size_env(char **env)
{
    int count = 0;

    for (; env[count]; count++);
    return (count);
}

static void unsetenv_apply(env_t *env_d, char *path_name)
{
    char **new_env = NULL;
    int size_actual_env = get_size_env(env_d->tab);
    int deleted_path = find_path(env_d->tab, path_name);
    int line_size = 0;

    if (deleted_path == -1)
        return;
    new_env = malloc(sizeof(char *) * (size_actual_env));
    new_env[size_actual_env - 1] = NULL;
    for (int i = 0, cursor = 0; env_d->tab[i]; i++) {
        if (i != deleted_path) {
            line_size = my_strlen(env_d->tab[i]);
            new_env[cursor] = malloc(sizeof(char) * (line_size + 1));
            new_env[cursor][line_size] = '\0';
            my_strcpy(new_env[cursor], env_d->tab[i]);
            cursor++;
        }
    }
    my_free_strtab(env_d->tab);
    env_d->tab = new_env;
}

void unsetenv_command(shell_t *shell_d)
{
    if (unsetenv_cmd_error(shell_d) == 1) {
        return;
    } else {
        for (int i = 1; shell_d->command.tab[i]; i++)
            unsetenv_apply(&shell_d->env, shell_d->command.tab[i]);
    }
}