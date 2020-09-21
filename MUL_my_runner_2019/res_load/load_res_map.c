/*
** EPITECH PROJECT, 2020
** LOAD_RES_MAP
** File description:
** loading of ressource used by map
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void load_block_1(map_t *map_d)
{
    map_d->block_1.texture = sfTexture_createFromFile\
    ("./res/block_1.png", NULL);
    map_d->block_1.sprite = sfSprite_create();
    sfSprite_setTexture(map_d->block_1.sprite,\
    map_d->block_1.texture,sfTrue);
    map_d->block_1.rect = (sfIntRect){0, 0, 50, 50};
    sfSprite_setTextureRect(map_d->block_1.sprite,\
    map_d->block_1.rect);
    map_d->block_1.position = (sfVector2f){0, 0};
}

static void load_block_2(map_t *map_d)
{
    map_d->block_2.texture = sfTexture_createFromFile\
    ("./res/block_2.png", NULL);
    map_d->block_2.sprite = sfSprite_create();
    sfSprite_setTexture(map_d->block_2.sprite,\
    map_d->block_2.texture,sfTrue);
    map_d->block_2.rect = (sfIntRect){0, 0, 50, 50};
    sfSprite_setTextureRect(map_d->block_2.sprite,\
    map_d->block_2.rect);
    map_d->block_2.position = (sfVector2f){0, 0};
}

void load_map_res(map_t *map_d)
{
    load_block_1(map_d);
    load_block_2(map_d);
    map_d->cursor = (sfVector2f){0, 750};
    map_d->cursor_move = (sfVector2f){0, 750};
    map_d->clock = sfClock_create();
}