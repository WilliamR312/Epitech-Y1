/*
** EPITECH PROJECT, 2020
** GET_INITIAL_ENV
** File description:
** get initial env
*/

#include <stddef.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"
#include "struct.h"

static int get_env_size(char **env)
{
    int count = 0;

    for (int i = 0; env[i] != NULL; i++)
        count++;
    return (count);
}

static int get_env_line_size(char *env_line)
{
    int count = 0;

    for (int i = 0; env_line[i] != '\0'; i++)
        count++;
    return (count);
}

void get_initial_env(shell_t *shell_d, char **env)
{
    int size_env = get_env_size(env);
    int size_line_env = 0;

    shell_d->env.tab = NULL;
    shell_d->env.tab = malloc(sizeof(char *) * (size_env + 1));
    for (int i = 0; i < size_env; i++) {
        size_line_env = get_env_line_size(env[i]);
        shell_d->env.tab[i] = NULL;
        shell_d->env.tab[i] = malloc(sizeof(char) * (size_line_env + 1));
        shell_d->env.tab[i][size_line_env] = '\0';
        my_strcpy(shell_d->env.tab[i], env[i]);
    }
    shell_d->env.tab[size_env] = NULL;
}