/*
** EPITECH PROJECT, 2020
** LOAD_CHAR_RES
** File description:
** manage loading of ressources for character
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void dead_res(char_t *char_d)
{
    char_d->dead_char.texture = sfTexture_createFromFile\
    ("./res/char_dead.png", NULL);
    char_d->dead_char.sprite = sfSprite_create();
    sfSprite_setTexture(char_d->dead_char.sprite, char_d->dead_char.texture,\
    sfTrue);
    char_d->dead_char.rect = (sfIntRect){0, 0, 150, 115};
    sfSprite_setTextureRect(char_d->dead_char.sprite, char_d->dead_char.rect);
    char_d->clock_anim = sfClock_create();
    char_d->clock_jump = sfClock_create();
}

static void alive_res(char_t *char_d)
{
    char_d->character.texture = sfTexture_createFromFile\
    ("./res/char_run.png", NULL);
    char_d->character.sprite = sfSprite_create();
    sfSprite_setTexture(char_d->character.sprite, char_d->character.texture,\
    sfTrue);
    char_d->character.rect = (sfIntRect){0, 0, 92, 118};
    sfSprite_setTextureRect(char_d->character.sprite, char_d->character.rect);
}

void load_char_res(char_t *char_d)
{
    dead_res(char_d);
    alive_res(char_d);
    char_d->land_level = (sfVector2f){100, 700 - 118};
    sfSprite_setPosition(char_d->character.sprite, char_d->land_level);
    char_d->state = 1;
    char_d->attenuation = 0;
    char_d->ground = 0;
}