/*
** EPITECH PROJECT, 2020
** MAP_LOAD
** File description:
** load map for map_load
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static int count_lines(map_t *map_d, char *path)
{
    FILE *file;
    size_t size = 0;
    char *line = NULL;
    int line_size = 0;
    int count = 0;
    map_d->map_size = 0;

    if ((file = fopen(path, "r")) == NULL)
        return (0);
    while ((getline(&line, &size ,file) != -1)) {
        count++;
        line_size = my_strlen(line) - 1;
        if (line_size > map_d->map_size)
            map_d->map_size = line_size;
    }
    map_d->nb_line = count;
    free(line);
    fclose(file);
    return (1);
}

static char *fill_tab(char *line, int size)
{
    char *map = malloc(sizeof(char) * size + 1);
    int curs = 0;

    for (curs; curs < my_strlen(line) - 1; curs++) {
        if (line[curs] == '\n')
            line[curs] = ' ';
        else
            map[curs] = line[curs];
    }
    for (curs; curs < size; curs++)
        map[curs] = ' ';
    map[size] = '\0';
    return (map);
}

static char **map_to_tab(map_t *map_d, char **map, char *path)
{
    FILE *file;
    size_t size = 0;
    char *line = NULL;
    int line_size = 0;
    int count = 0;

    map = malloc(sizeof(char*) * map_d->nb_line);
    if ((file = fopen(path, "r")) == NULL)
        return (NULL);
    for (int i = 0; i < map_d->nb_line; i++) {
        getline(&line, &size ,file) != -1;
        map[i] = fill_tab(line, map_d->map_size);
    }
    fclose(file);
    return (map);
}

int map_load(map_t *map_d, char *path)
{
    char **map = NULL;

    if (count_lines(map_d, path) == 0)
        return (0);
    if ((map = map_to_tab(map_d, map, path)) == NULL)
        return (0);
    map_d->map = map;
    return (1);
}