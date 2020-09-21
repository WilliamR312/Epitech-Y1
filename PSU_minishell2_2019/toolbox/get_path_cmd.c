/*
** EPITECH PROJECT, 2020
** PATHS_TO_TAB_MANAGEMENT
** File description:
** manage paths to 2d tab
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

static int count_nbr_paths(char *paths)
{
    int count = 0;

    for (int i = 0; paths[i]; i++) {
        if (paths[i] == ':')
            count++;
    }
    return (count);
}

static int count_path(char *paths, int cursor)
{
    int count = 0;

    for (int i = cursor; paths[i] != '\0'; i++, count++) {
        if (paths[i] == ':')
            return (count);
    }
    return (count);
}

static int first_path(char *path)
{
    if (path[5] == '\0')
        return (0);
    return (1);
}

static void paths_to_tab(char *paths, shell_t *shell_d)
{
    int nbr_paths = count_nbr_paths(paths) + 1;
    int cursor = 5;
    int size_path = 0;

    if (shell_d->path_cmd.tab != NULL)
        my_free_strtab(shell_d->path_cmd.tab);
    shell_d->path_cmd.tab = malloc(sizeof(char *) * (nbr_paths + 1));
    shell_d->path_cmd.tab[nbr_paths] = NULL;
    size_path = count_path(paths, cursor);
    for (int i = 0; i < nbr_paths; i++) {
        size_path = count_path(paths, cursor);
        shell_d->path_cmd.tab[i] = malloc(sizeof(char) * (size_path + 1));
        for (int j = cursor, k = 0; paths[j] != ':' && paths[j] != '\0'; \
        j++, k++) {
            shell_d->path_cmd.tab[i][k] = paths[j];
        }
        shell_d->path_cmd.tab[i][size_path] = '\0';
        cursor = cursor + size_path + 1;
    }
}

void get_path_cmd(shell_t *shell_d)
{
    int path_pos = 0;

    path_pos = find_path(shell_d->env.tab, "PATH");
    if (path_pos != -1 && first_path(shell_d->env.tab[path_pos]) == 1) {
        paths_to_tab(shell_d->env.tab[path_pos], shell_d);
    } else {
        if (shell_d->path_cmd.tab != NULL || shell_d->path_cmd.nbr != 0) {
            shell_d->path_cmd.tab = NULL;
            shell_d->path_cmd.tab = 0;
        }
    }
}