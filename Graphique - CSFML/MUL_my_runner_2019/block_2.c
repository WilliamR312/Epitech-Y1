/*
** EPITECH PROJECT, 2020
** BLOCK_2
** File description:
** manage block of type 2
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static int is_on_collision(sfVector2f player, sfVector2f block)
{
    float xp = player.x;
    float yp = player.y;
    float xb = block.x;
    float yb = block.y;

    if ((((xp + 8 >= xb) && (xp + 8 <= xb + 50)) &&\
    ((yp + 118 >= yb) && (yp + 118 <= yb + 50))) ||\
    (((xp + 88 >= xb) && (xp + 88 <= xb + 50)) &&\
    ((yp + 118 >= yb) && (yp + 118 <= yb + 50))) ||\
    (((xp + 8 >= xb) && (xp + 8 <= xb + 50)) &&\
    ((yp >= yb) && (yp + 118 <= yb + 50))) ||\
    (((xp + 88 >= xb) && (xp + 88 <= xb + 50)) &&\
    ((yp >= yb) && (yp + 118 <= yb + 50))))
        return (1);
    return (0);
}

void block_2(core_t *core_d, int y, int x)
{
    sfVector2f pos_player = sfSprite_getPosition\
    (core_d->character_data.character.sprite);
    sfVector2f pos_block = sfSprite_getPosition(core_d->map_d.block_2.sprite);

    if (core_d->map_d.map[y][x] == '2') {
        sfSprite_setPosition\
        (core_d->map_d.block_2.sprite, core_d->map_d.cursor_move);
        sfRenderWindow_drawSprite\
        (core_d->window_p.window, core_d->map_d.block_2.sprite, NULL);
        core_d->map_d.cursor_move.x = core_d->map_d.cursor_move.x + 50;
    }
    if (is_on_collision(pos_player, pos_block)) {
        core_d->character_data.state = 4;
    }
}