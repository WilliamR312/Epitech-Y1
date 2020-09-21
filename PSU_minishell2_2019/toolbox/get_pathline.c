/*
** EPITECH PROJECT, 2020
** PATH_FINDER
** File description:
** search path on env
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

static int get_pathline_size(char *pathline)
{
    int i = 0;
    int count = 0;

    for (; pathline[i] != '='; i++);
    i++;
    for (; pathline[i] != '\0'; i++, count++);
    return (count);
}

char *get_pathline(char **env, char *path)
{
    int cursor = 0;
    int pathline_size = 0;
    int path_pos = 0;
    char *pathline = NULL;

    path_pos = find_path(env, path);
    if (path_pos == -1)
        return (NULL);
    pathline_size = get_pathline_size(env[path_pos]);
    pathline = malloc(sizeof(char) * (pathline_size + 1));
    for (; env[path_pos][cursor] != '='; cursor++);
    cursor++;
    for (int i = 0; env[path_pos][cursor] != '\0'; i++, cursor++)
        pathline[i] = env[path_pos][cursor];
    pathline[pathline_size] = '\0';
    return (pathline);
}