/*
** EPITECH PROJECT, 2019
** MOVE_PLAYER_MORE_H
** File description:
** functions used by player move management
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void over_hole(char **map, map_data_t *map_d, int y, int x)
{
    if (map_d->over == 1) {
        map[map_d->pos_player_y][map_d->pos_player_x] = 'O';
        map_d->over = 0;
    }
    if (map[map_d->pos_player_y + y][map_d->pos_player_x + x] == 'O') {
        map_d->over = 1;
    }
}