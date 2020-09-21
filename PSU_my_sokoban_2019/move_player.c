/*
** EPITECH PROJECT, 2019
** MOVE_PLAYER_H
** File description:
** move management of player with functions used by him
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

static void move_up(map_data_t *map_d, char **map_2d)
{
    if (map_2d[map_d->pos_player_y - 1][map_d->pos_player_x] != '#' \
    && map_2d[map_d->pos_player_y - 1][map_d->pos_player_x] == 'X' \
    && map_2d[map_d->pos_player_y - 2][map_d->pos_player_x] != '#' \
    && map_2d[map_d->pos_player_y - 2][map_d->pos_player_x] != 'X') {
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = ' ';
        over_hole(map_2d, map_d, -1, 0);
        map_d->pos_player_y = map_d->pos_player_y - 1;
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = 'P';
        map_2d[map_d->pos_player_y - 1][map_d->pos_player_x] = 'X';
    }
    if (map_2d[map_d->pos_player_y - 1][map_d->pos_player_x] != '#' \
    && map_2d[map_d->pos_player_y - 1][map_d->pos_player_x] != 'X') {
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = ' ';
        over_hole(map_2d, map_d, -1, 0);
        map_d->pos_player_y = map_d->pos_player_y - 1;
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = 'P';
    }
}

static void move_down(map_data_t *map_d, char **map_2d)
{
    if (map_2d[map_d->pos_player_y + 1][map_d->pos_player_x] != '#' \
    && map_2d[map_d->pos_player_y + 1][map_d->pos_player_x] == 'X' \
    && map_2d[map_d->pos_player_y + 2][map_d->pos_player_x] != '#' \
    && map_2d[map_d->pos_player_y + 2][map_d->pos_player_x] != 'X') {
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = ' ';
        over_hole(map_2d, map_d, 1, 0);
        map_d->pos_player_y = map_d->pos_player_y + 1;
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = 'P';
        map_2d[map_d->pos_player_y + 1][map_d->pos_player_x] = 'X';
    }
    if (map_2d[map_d->pos_player_y + 1][map_d->pos_player_x] != '#' \
    && map_2d[map_d->pos_player_y + 1][map_d->pos_player_x] != 'X') {
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = ' ';
        over_hole(map_2d, map_d, 1, 0);
        map_d->pos_player_y = map_d->pos_player_y + 1;
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = 'P';
    }
}

static void move_left(map_data_t *map_d, char **map_2d)
{
    if (map_2d[map_d->pos_player_y][map_d->pos_player_x - 1] != '#' \
    && map_2d[map_d->pos_player_y][map_d->pos_player_x - 1] == 'X' \
    && map_2d[map_d->pos_player_y][map_d->pos_player_x - 2] != '#' \
    && map_2d[map_d->pos_player_y][map_d->pos_player_x - 2] != 'X') {
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = ' ';
        over_hole(map_2d, map_d, 0, -1);
        map_d->pos_player_x = map_d->pos_player_x - 1;
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = 'P';
        map_2d[map_d->pos_player_y][map_d->pos_player_x - 1] = 'X';
    }
    if (map_2d[map_d->pos_player_y][map_d->pos_player_x - 1] != '#' \
    && map_2d[map_d->pos_player_y][map_d->pos_player_x - 1] != 'X') {
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = ' ';
        over_hole(map_2d, map_d, 0, -1);
        map_d->pos_player_x = map_d->pos_player_x - 1;
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = 'P';
    }
}

static void move_right(map_data_t *map_d, char **map_2d)
{
    if (map_2d[map_d->pos_player_y][map_d->pos_player_x + 1] != '#' \
    && map_2d[map_d->pos_player_y][map_d->pos_player_x + 1] == 'X' \
    && map_2d[map_d->pos_player_y][map_d->pos_player_x + 2] != '#' \
    && map_2d[map_d->pos_player_y][map_d->pos_player_x + 2] != 'X') {
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = ' ';
        over_hole(map_2d, map_d, 0, 1);
        map_d->pos_player_x = map_d->pos_player_x + 1;
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = 'P';
        map_2d[map_d->pos_player_y][map_d->pos_player_x + 1] = 'X';
    }
    if (map_2d[map_d->pos_player_y][map_d->pos_player_x + 1] != '#' \
    && map_2d[map_d->pos_player_y][map_d->pos_player_x + 1] != 'X') {
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = ' ';
        over_hole(map_2d, map_d, 0, 1);
        map_d->pos_player_x = map_d->pos_player_x + 1;
        map_2d[map_d->pos_player_y][map_d->pos_player_x] = 'P';
    }
}

void move_player(int key, map_data_t *map_d, char **map_2d)
{
    int x = 0;
    int y = 0;

    switch (key) {
        case KEY_UP :
            move_up(map_d, map_2d);
            break;
        case KEY_DOWN :
            move_down(map_d, map_2d);
            break;
        case KEY_LEFT :
            move_left(map_d, map_2d);
            break;
        case KEY_RIGHT :
            move_right(map_d, map_2d);
            break;
    }
}