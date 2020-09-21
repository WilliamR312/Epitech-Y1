/*
** EPITECH PROJECT, 2020
** BLOCK_1
** File description:
** manage block of type 1
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static int is_on_plateform(sfVector2f player, sfVector2f block)
{
    float xp = player.x;
    float yp = player.y;
    float xb = block.x;
    float yb = block.y;

    if ((((xp + 8 >= xb) && (xp + 8 <= xb + 50)) &&\
    ((yp + 118 >= yb) && (yp + 118 <= yb + 10))) ||\
    (((xp + 88 >= xb) && (xp + 88 <= xb + 50)) &&\
    ((yp + 118 >= yb) && (yp + 118 <= yb + 10))) ||\
    (((xp + 44 >= xb) && (xp + 44 <= xb + 50)) &&\
    ((yp + 118 >= yb) && (yp + 118 <= yb + 10))))
        return (1);
    if ((((xp + 8 >= xb) && (xp + 8 <= xb + 50)) &&\
    ((yp + 118 > yb + 10) && (yp + 118 <= yb + 50))) ||\
    (((xp + 88 >= xb) && (xp + 88 <= xb + 50)) &&\
    ((yp + 118 > yb + 10) && (yp + 118 <= yb + 50))) ||\
    (((xp + 44 >= xb) && (xp + 44 <= xb + 50)) &&\
    ((yp + 118 > yb + 10) && (yp + 118 <= yb + 50))))
        return (2);
    return (0);
}

static void check_plateform(core_t *core_d)
{
    int collision = 0;
    sfVector2f pos_player = sfSprite_getPosition\
    (core_d->character_data.character.sprite);
    sfVector2f pos_block = sfSprite_getPosition\
    (core_d->map_d.block_1.sprite);

    collision = is_on_plateform(pos_player, pos_block);
    if (collision == 1) {
        core_d->character_data.land_level.y = pos_block.y - 118;
        core_d->character_data.ground = 1;
    }
    if (collision == 2)
        core_d->character_data.state = 4;
}

void block_1(core_t *core_d, int y, int x)
{
    if (core_d->map_d.map[y][x] == '1') {
        sfSprite_setPosition(core_d->map_d.block_1.sprite,\
        core_d->map_d.cursor_move);
        sfRenderWindow_drawSprite(core_d->window_p.window,\
        core_d->map_d.block_1.sprite, NULL);
        core_d->map_d.cursor_move.x = core_d->map_d.cursor_move.x + 50;
        check_plateform(core_d);
    }
}