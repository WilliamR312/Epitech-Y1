/*
** EPITECH PROJECT, 2020
** INIT_GAME_SHOP_TOWER
** File description:
** initialisation of the towers used by the shop
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

void init_tower_04_in_shop(tower_shop_t *new_tower, core_t *core_d)
{
    new_tower->price = 500;
    new_tower->id_tower = 3;
    new_tower->range = 500;
    new_tower->shoot_speed = 1;
    new_tower->hit_p = 10;
    new_tower->scale = 0.6;
    new_tower->type = 2;
    new_tower->base = (sfVector2f) {50, 50};
    new_tower->pos = (sfVector2f) {960, 930};
    new_tower->rect = (sfIntRect) {0, 0, 100, 86};
    new_tower->texture = \
        sfTexture_createFromFile("./src/res/towers/4.png", NULL);
    new_tower->sprite = sfSprite_create();
    sfSprite_setScale(new_tower->sprite, ((sfVector2f) {new_tower->scale, \
        new_tower->scale}));
    sfSprite_setTexture(new_tower->sprite, new_tower->texture, sfTrue);
    sfSprite_setPosition(new_tower->sprite, new_tower->pos);
    new_tower->text_price = sfText_create();
    sfText_setFont(new_tower->text_price, core_d->fonts_lib.font_01);
    sfText_setString(new_tower->text_price, "500");
    sfText_setPosition(new_tower->text_price, (sfVector2f) {970, 990});
}

void init_tower_03_in_shop(tower_shop_t *new_tower, core_t *core_d)
{
    new_tower->price = 400;
    new_tower->id_tower = 2;
    new_tower->range = 400;
    new_tower->shoot_speed = 1;
    new_tower->hit_p = 10;
    new_tower->scale = 0.6;
    new_tower->type = 1;
    new_tower->base = (sfVector2f) {33, 80};
    new_tower->pos = (sfVector2f) {865, 930};
    new_tower->rect = (sfIntRect) {0, 0, 65, 100};
    new_tower->texture = \
        sfTexture_createFromFile("./src/res/towers/3.png", NULL);
    new_tower->sprite = sfSprite_create();
    sfSprite_setScale(new_tower->sprite, ((sfVector2f) {new_tower->scale, \
        new_tower->scale}));
    sfSprite_setTexture(new_tower->sprite, new_tower->texture, sfTrue);
    sfSprite_setPosition(new_tower->sprite, new_tower->pos);
    new_tower->text_price = sfText_create();
    sfText_setFont(new_tower->text_price, core_d->fonts_lib.font_01);
    sfText_setString(new_tower->text_price, "400");
    sfText_setPosition(new_tower->text_price, (sfVector2f) {870, 990});
}

void init_tower_02_in_shop(tower_shop_t *new_tower, core_t *core_d)
{
    new_tower->price = 300;
    new_tower->id_tower = 1;
    new_tower->range = 150;
    new_tower->shoot_speed = 1;
    new_tower->hit_p = 10;
    new_tower->scale = 0.6;
    new_tower->type = 1;
    new_tower->base = (sfVector2f) {33, 33};
    new_tower->pos = (sfVector2f) {770, 934};
    new_tower->rect = (sfIntRect) {0, 0, 66, 66};
    new_tower->texture = \
        sfTexture_createFromFile("./src/res/towers/2.png", NULL);
    new_tower->sprite = sfSprite_create();
    sfSprite_setScale(new_tower->sprite, ((sfVector2f) {new_tower->scale, \
    new_tower->scale}));
    sfSprite_setTexture(new_tower->sprite, new_tower->texture, sfTrue);
    sfSprite_setPosition(new_tower->sprite, new_tower->pos);
    new_tower->text_price = sfText_create();
    sfText_setFont(new_tower->text_price, core_d->fonts_lib.font_01);
    sfText_setString(new_tower->text_price, "300");
    sfText_setPosition(new_tower->text_price, (sfVector2f) {760, 990});
}

void init_tower_01_in_shop(tower_shop_t *new_tower, core_t *core_d)
{
    new_tower->price = 100;
    new_tower->id_tower = 0;
    new_tower->range = 150;
    new_tower->shoot_speed = 1;
    new_tower->hit_p = 5;
    new_tower->scale = 0.7;
    new_tower->type = 1;
    new_tower->base = (sfVector2f) {50, 45};
    new_tower->pos = (sfVector2f) {650, 930};
    new_tower->rect = (sfIntRect) {0, 0, 100, 89};
    new_tower->texture = \
        sfTexture_createFromFile("./src/res/towers/1.png", NULL);
    new_tower->sprite = sfSprite_create();
    sfSprite_setScale(new_tower->sprite, ((sfVector2f) {new_tower->scale, \
        new_tower->scale}));
    sfSprite_setTexture(new_tower->sprite, new_tower->texture, sfTrue);
    sfSprite_setPosition(new_tower->sprite, new_tower->pos);
    new_tower->text_price = sfText_create();
    sfText_setFont(new_tower->text_price, core_d->fonts_lib.font_01);
    sfText_setString(new_tower->text_price, "100");
    sfText_setPosition(new_tower->text_price, (sfVector2f) {660, 990});
}