/*
** EPITECH PROJECT, 2019
** GAME_RES_02
** File description:
** game element resources
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/my_hunter.h"
#include "../include/my.h"

void game_xwing_02_res(ennemis_t *ennemis_d)
{
    ennemis_d->x_wing_02.g_vessel_p.texture =\
    sfTexture_createFromFile("res/x_wing_01.png", NULL);
    ennemis_d->x_wing_02.g_vessel_p.sprite = sfSprite_create();
    ennemis_d->x_wing_02.g_vessel_p.rect = (sfIntRect){0, 0, 125, 50};
    sfSprite_setTexture(ennemis_d->x_wing_02.g_vessel_p.sprite,\
    ennemis_d->x_wing_02.g_vessel_p.texture, sfTrue);
    sfSprite_setTextureRect(ennemis_d->x_wing_02.g_vessel_p.sprite,\
    ennemis_d->x_wing_02.g_vessel_p.rect);
    ennemis_d->x_wing_02.clock = sfClock_create();
    ennemis_d->x_wing_02.offset = (sfVector2f){0.3, 0.1};
    ennemis_d->x_wing_02.state = 1;
}

void game_destroy_xwing(ennemis_t *ennemis_d)
{
    ennemis_d->destroy_x_wing.texture = sfTexture_createFromFile\
    ("res/destroy_xwing.png", NULL);
    ennemis_d->destroy_x_wing.sprite = sfSprite_create();
    ennemis_d->destroy_x_wing.rect = (sfIntRect){0, 0, 90, 125};
    sfSprite_setTexture(ennemis_d->destroy_x_wing.sprite,\
    ennemis_d->destroy_x_wing.texture, sfTrue);
    sfSprite_setTextureRect(ennemis_d->destroy_x_wing.sprite,\
    ennemis_d->destroy_x_wing.rect);
}

void game_xwing_01_res(ennemis_t *ennemis_d)
{
    ennemis_d->x_wing_01.g_vessel_p.texture = sfTexture_createFromFile\
    ("res/x_wing_01.png", NULL);
    ennemis_d->x_wing_01.g_vessel_p.sprite = sfSprite_create();
    ennemis_d->x_wing_01.g_vessel_p.rect = (sfIntRect){0, 0, 125, 50};
    sfSprite_setTexture(ennemis_d->x_wing_01.g_vessel_p.sprite,\
    ennemis_d->x_wing_01.g_vessel_p.texture, sfTrue);
    sfSprite_setTextureRect(ennemis_d->x_wing_01.g_vessel_p.sprite,\
    ennemis_d->x_wing_01.g_vessel_p.rect);
    ennemis_d->x_wing_01.clock = sfClock_create();
    ennemis_d->x_wing_01.state = 1;
    ennemis_d->x_wing_01.offset = (sfVector2f){0.5, 0.5};
}