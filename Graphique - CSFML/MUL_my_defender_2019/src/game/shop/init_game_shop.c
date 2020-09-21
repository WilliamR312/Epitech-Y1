/*
** EPITECH PROJECT, 2020
** INIT_GAME_SHOP
** File description:
** initialisation of the ressources used by the shop
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_bar(core_t *core_d)
{
    sfVector2f position = {910 - 300, 920};
    sfVector2f  size = {700, 150};
    sfColor color = sfBlack;
    sfColor color2 = sfWhite;

    core_d->game_scene.shop.bar = sfRectangleShape_create();
    sfRectangleShape_setPosition(core_d->game_scene.shop.bar, position);
    sfRectangleShape_setSize(core_d->game_scene.shop.bar, size);
    sfRectangleShape_setFillColor(core_d->game_scene.shop.bar, color);
    sfRectangleShape_setOutlineThickness(core_d->game_scene.shop.bar, 3);
    sfRectangleShape_setOutlineColor(core_d->game_scene.shop.bar, color2);
}

void init_shop(core_t *core_d)
{
    core_d->game_scene.shop.on_hand = 0;
    core_d->game_scene.shop.nb_towers = 4;
    init_bar(core_d);
    core_d->game_scene.shop.tower_on_shop = malloc(sizeof(tower_shop_t) * 4);
    init_tower_01_in_shop(&core_d->game_scene.shop.tower_on_shop[0], core_d);
    init_tower_02_in_shop(&core_d->game_scene.shop.tower_on_shop[1], core_d);
    init_tower_03_in_shop(&core_d->game_scene.shop.tower_on_shop[2], core_d);
    init_tower_04_in_shop(&core_d->game_scene.shop.tower_on_shop[3], core_d);
}