/*
** EPITECH PROJECT, 2020
** PATH_FINDER
** File description:
** search path on env
*/

#include "my.h"
#include "mysh.h"
#include "struct.h"

static int path_cmp(char const *env, char const *path)
{
    int count = 0;
    int size_path = my_strlen(path);

    for (int i = 0; path[i] != '\0'; i++) {
        if (env[i] == path[i])
            count++;
        if (env[i] == '\0')
            return (0);
    }
    if (count == size_path && env[size_path] == '=')
        return (1);
    return (0);
}

int find_path(char **env, char *path)
{
    int i = 0;

    for (; env[i]; i++) {
        if (path_cmp(env[i], path) == 1)
            return (i);
    }
    return (-1);
}