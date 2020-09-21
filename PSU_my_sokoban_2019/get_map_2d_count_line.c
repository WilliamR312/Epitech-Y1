/*
** EPITECH PROJECT, 2019
** GET_MAP_2D_COUNT_LINE_H
** File description:
** used to count line with get map 1d
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

static void max_col(map_data_t *map_d, int max_colo)
{
    if (max_colo > map_d->max_col)
        map_d->max_col = max_colo;
}

static void check_char(char src, int y, int x, map_data_t *map_d)
{
    if (src != 'P' && src != '#' && src != 'O' &&\
    src != 'X' && src != '\n' && src != ' ') {
        exit (84);
    }
    if (src == 'P') {
        map_d->pos_player_x = x;
        map_d->pos_player_y = y;
        src == ' ';
    }
}

static void check_char_box(char src, map_data_t *map_d)
{
    if (src == 'X')
        map_d->nbr_box = map_d->nbr_box + 1;
    if (src == 'O')
        map_d->nbr_box_place = map_d->nbr_box_place + 1;
}

static void check_box_error(map_data_t *map_d)
{
    if (map_d->nbr_box != map_d->nbr_box_place || map_d->nbr_box == 0)
        exit (84);
}

int count_line(int size, char *map_1d, map_data_t *map_d)
{
    int count = 0;
    int max_colo = 0;

    map_d->nbr_box = 0;
    map_d->nbr_box_place = 0;
    map_d->max_col = 0;
    for (int i = 0; i < size; i++) {
        check_char(map_1d[i], count, max_colo, map_d);
        check_char_box(map_1d[i], map_d);
        max_colo++;
        if (map_1d[i] == '\n') {
            count++;
            max_col(map_d, max_colo);
            max_colo = 0;
        }
    }
    check_box_error(map_d);
    return (count);
}