/*
** EPITECH PROJECT, 2020
** DRAW_GAME_SHOP
** File description:
** manage display of game shop
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

void draw_shop(core_t *core_d)
{
    sfRenderWindow_drawRectangleShape(core_d->window_d.window, \
        core_d->game_scene.shop.bar, NULL);
    for (int i = 0; i < core_d->game_scene.shop.nb_towers; i++) {
        sfRenderWindow_drawSprite(core_d->window_d.window, \
        core_d->game_scene.shop.tower_on_shop[i].sprite, NULL);
        sfRenderWindow_drawText(core_d->window_d.window, \
        core_d->game_scene.shop.tower_on_shop[i].text_price, NULL);
    }
    if (core_d->game_scene.shop.on_hand != 0)
        draw_hand_tower(core_d->window_d.window, \
        &core_d->game_scene.shop.tower_hand, &core_d->game_scene);
}