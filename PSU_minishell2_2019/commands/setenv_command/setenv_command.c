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

static char *make_new_path(shell_t *shell_d)
{
    int size_name = 0;
    int size_value = 0;
    int size_new_path = 0;
    char *new_path = NULL;

    size_name = my_strlen(shell_d->command.tab[1]);
    size_new_path = size_name + 1;
    if (shell_d->command.nbr > 2) {
        size_value = my_strlen(shell_d->command.tab[2]);
        size_new_path += size_value;
    }
    new_path = malloc(sizeof(char) * (size_new_path + 1));
    new_path = my_strcpy(new_path, shell_d->command.tab[1]);
    new_path[size_name] = '=';
    if (shell_d->command.nbr > 2) {
        for (int i = size_name + 1, cpy = 0; i < size_new_path; i++, cpy++)
            new_path[i] = shell_d->command.tab[2][cpy];
    }
    new_path[size_new_path] = '\0';
    return (new_path);
}

static void create_path_env(shell_t *shell_d, char *new_path)
{
    char **new_env = NULL;
    int env_size = 0;
    int size_line_env = 0;

    for (; shell_d->env.tab[env_size] != NULL; env_size++);
    new_env = malloc(sizeof(char *) * (env_size + 2));
    for (int i = 0; i < env_size; i++) {
        size_line_env = my_strlen(shell_d->env.tab[i]);
        new_env[i] = malloc(sizeof(char) * (size_line_env + 1));
        new_env[i][size_line_env] = '\0';
        new_env[i] = my_strcpy(new_env[i], shell_d->env.tab[i]);
    }
    size_line_env = my_strlen(new_path);
    new_env[env_size] = malloc(sizeof(char) * (size_line_env + 1));
    new_env[env_size] = my_strcpy(new_env[env_size], new_path);
    new_env[env_size][size_line_env] = '\0';
    new_env[env_size + 1] = NULL;
    my_free_strtab(shell_d->env.tab);
    shell_d->env.tab = new_env;
}

static void replace_path_env(shell_t *shell_d, int pos, char *new_path)
{
    free(shell_d->env.tab[pos]);
    shell_d->env.tab[pos] = new_path;
}

static void setenv_apply(shell_t *shell_d)
{
    char *new_path = NULL;
    int path_name_position = 0;

    path_name_position = find_path(shell_d->env.tab, shell_d->command.tab[1]);
    new_path = make_new_path(shell_d);
    if (path_name_position == -1) {
        create_path_env(shell_d, new_path);
        free(new_path);
    } else {
        replace_path_env(shell_d, path_name_position, new_path);
    }
}

void setenv_command(shell_t *shell_d)
{
    if (shell_d->command.nbr == 1)
        my_show_str_array(shell_d->env.tab);
    else if (setenv_cmd_error(shell_d) == 0)
        setenv_apply(shell_d);
}