/*
** EPITECH PROJECT, 2020
** INIT_BLOCK_BOX
** File description:
** initialisation of blockage blocs
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_direction_box(block_box_t *block_box, sfVector2f pos, \
sfVector2f size, int type)
{
    sfColor color = sfColor_fromRGBA(255, 100, 100, 0);

    block_box->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(block_box->rect, size);
    sfRectangleShape_setPosition(block_box->rect, pos);
    sfRectangleShape_setFillColor(block_box->rect, color);
    block_box->type = type;
}

static void init_block_on_the_way_2(scene_game_t *game)
{
    sfVector2f size = {105, 220};
    sfVector2f pos = {1165, 440};

    init_direction_box(&game->block_box[7], pos, size, 1);
    size = (sfVector2f) {680, 85};
    pos = (sfVector2f) {1270, 445};
    init_direction_box(&game->block_box[8], pos, size, 1);
}

static void init_block_on_the_way_1(scene_game_t *game)
{
    sfVector2f size = {375, 80};
    sfVector2f pos = {0, 540};

    init_direction_box(&game->block_box[2], pos, size, 1);
    size = (sfVector2f) {105, 350};
    pos = (sfVector2f) {265, 225};
    init_direction_box(&game->block_box[3], pos, size, 1);
    size = (sfVector2f) {390, 85};
    pos = (sfVector2f) {365, 225};
    init_direction_box(&game->block_box[4], pos, size, 1);
    size = (sfVector2f) {100, 435};
    pos = (sfVector2f) {652, 310};
    init_direction_box(&game->block_box[5], pos, size, 1);
    size = (sfVector2f) {520, 90};
    pos = (sfVector2f) {750, 658};
    init_direction_box(&game->block_box[6], pos, size, 1);
}

void init_all_block_box(core_t *core_d)
{
    sfVector2f size = {710, 150};
    sfVector2f pos = {605, 915};

    core_d->game_scene.nb_block_box = 9;
    core_d->game_scene.block_box = malloc(sizeof(block_box_t) * \
    core_d->game_scene.nb_block_box);
    init_direction_box(&core_d->game_scene.block_box[0], pos, size, 1);
    size = (sfVector2f) {90, 90};
    pos = (sfVector2f) {1815, 5};
    init_direction_box(&core_d->game_scene.block_box[1], pos, size, 1);
    init_block_on_the_way_1(&core_d->game_scene);
    init_block_on_the_way_2(&core_d->game_scene);
}