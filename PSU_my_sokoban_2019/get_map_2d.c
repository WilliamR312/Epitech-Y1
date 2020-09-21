/*
** EPITECH PROJECT, 2019
** GET_MAP_2D_H
** File description:
** used to get map 2d from map 1d
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/my_sokoban.h"
#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int count_col(char *src, int i)
{
    int count = 0;

    while (src[i] != '\n') {
        count++;
        i++;
    }
    return (count + 1);
}

static void **make_map_2d(char **map_2d, char *map_1d, map_data_t *map_d)
{
    int i = 0;
    int a = 0;
    int b = 0;
    int col_size = 0;

    while (a < map_d->rows) {
        col_size = count_col(map_1d, i);
        map_2d[a] = malloc(sizeof(char) * col_size);
        for (int count = 0; count < col_size; count++) {
            map_2d[a][b] = map_1d[i];
            i++;
            b++;
        }
        a++;
        b = 0;
    }
}

char **get_map_2d(map_data_t *map_d, char *map_1d, char **map_2d)
{
    map_d->rows = count_line(map_d->size, map_1d, map_d);
    map_2d = malloc(sizeof(char *) * map_d->rows);
    make_map_2d(map_2d, map_1d, map_d);
    return (map_2d);
}