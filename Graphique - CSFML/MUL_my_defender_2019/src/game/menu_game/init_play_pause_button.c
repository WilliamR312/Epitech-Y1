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

void init_play_pause_button(core_t *core_d)
{
    sfVector2f size = {80, 80};
    sfVector2f pos = {1820, 10};
    sfIntRect text_rect = {80, 0, 80, 80};

    core_d->game_scene.pause_b.text_rect = text_rect;
    core_d->game_scene.pause_b.pos = pos;
    core_d->game_scene.pause_b.rect = sfRectangleShape_create();
    sfRectangleShape_setSize(core_d->game_scene.pause_b.rect, size);
    sfRectangleShape_setPosition(core_d->game_scene.pause_b.rect, pos);
    core_d->game_scene.pause_b.texture = sfTexture_createFromFile \
    ("./src/res/buttons/play_pause_button.png", NULL);
    sfRectangleShape_setTexture(core_d->game_scene.pause_b.rect, \
    core_d->game_scene.pause_b.texture, sfTrue);
    sfRectangleShape_setTextureRect(core_d->game_scene.pause_b.rect, \
    text_rect);
}