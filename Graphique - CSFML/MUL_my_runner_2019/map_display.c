/*
** EPITECH PROJECT, 2020
** MAP_DISPLAY
** File description:
** Display map
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void display_space(core_t *core_d, int y, int x)
{
    if (core_d->map_d.map[y][x] == ' ')
        core_d->map_d.cursor_move.x = core_d->map_d.cursor_move.x + 50;
}

static void move_map(core_t *core_d)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(core_d->map_d.clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.002) {
        core_d->map_d.cursor.x = core_d->map_d.cursor.x - 1;
        core_d->map_d.cursor_move.x = core_d->map_d.cursor.x;
        sfClock_restart(core_d->map_d.clock);
    }
}

int map_display(core_t *core_d)
{
    if (core_d->character_data.state != 4 && core_d->character_data.state != 5)
        move_map(core_d);
    for (int i = core_d->map_d.nb_line - 1; i >= 0; i--) {
        for (int j = 0; j < core_d->map_d.map_size; j++) {
            block_1(core_d, i, j);
            block_2(core_d, i, j);
            display_space(core_d, i, j);
        }
        if (core_d->character_data.state != 4 &&\
        core_d->character_data.state != 5)
            win_game(core_d);
        core_d->map_d.cursor_move.x = core_d->map_d.cursor.x;
        core_d->map_d.cursor_move.y = core_d->map_d.cursor_move.y - 50;
    }
    core_d->map_d.cursor_move.y = 750;
    return (1);
}