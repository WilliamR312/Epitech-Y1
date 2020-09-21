/*
** EPITECH PROJECT, 2020
** GAME
** File description:
** Main for game
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_direction_box(dir_box_t *dir_box, sfVector2f pos, \
sfVector2f size, int dir)
{
    sfColor color = sfColor_fromRGBA(150, 100, 0, 0);

    dir_box->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(dir_box->rect, size);
    sfRectangleShape_setPosition(dir_box->rect, pos);
    sfRectangleShape_setFillColor(dir_box->rect, color);
    dir_box->dir = dir;
}

static void init(core_t *core_d)
{
    core_d->game_scene.nb_dir_box = 6;
    core_d->game_scene.dir_box = malloc(sizeof(dir_box_t) * 6);
}

void init_all_direction_box(core_t *core_d)
{
    sfVector2f size = {80, 100};
    sfVector2f pos = {290, 540};

    init(core_d);
    init_direction_box(&core_d->game_scene.dir_box[0], pos, size, 1);
    size = (sfVector2f) {100, 50};
    pos = (sfVector2f) {250, 200};
    init_direction_box(&core_d->game_scene.dir_box[1], pos, size, 2);
    size = (sfVector2f) {80, 100};
    pos = (sfVector2f) {690, 230};
    init_direction_box(&core_d->game_scene.dir_box[2], pos, size, 3);
    size = (sfVector2f) {100, 50};
    pos = (sfVector2f) {650, 660};
    init_direction_box(&core_d->game_scene.dir_box[3], pos, size, 2);
    size = (sfVector2f) {50, 100};
    pos = (sfVector2f) {1200, 630};
    init_direction_box(&core_d->game_scene.dir_box[4], pos, size, 1);
    size = (sfVector2f) {100, 24};
    pos = (sfVector2f) {1170, 440};
    init_direction_box(&core_d->game_scene.dir_box[5], pos, size, 2);
}