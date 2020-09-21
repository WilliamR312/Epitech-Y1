/*
** EPITECH PROJECT, 2019
** MENU_RES
** File description:
** menu resources loading
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/my_hunter.h"
#include "../include/my.h"

void menu_button_play_res(menu_t *menu_d)
{
    menu_d->menu_b_p.button_play_p.position = (sfVector2f){710, 645};
    menu_d->menu_b_p.button_play_p.rect = (sfIntRect){0, 0, 240, 70};
    menu_d->menu_b_p.button_play_p.texture = sfTexture_createFromFile\
    ("res/play_button.png", NULL);
    menu_d->menu_b_p.button_play_p.sprite = sfSprite_create();
    sfSprite_setTexture(menu_d->menu_b_p.button_play_p.sprite,\
    menu_d->menu_b_p.button_play_p.texture, sfTrue);
    sfSprite_setTextureRect(menu_d->menu_b_p.button_play_p.sprite,\
    menu_d->menu_b_p.button_play_p.rect);
    sfSprite_setPosition(menu_d->menu_b_p.button_play_p.sprite,\
    menu_d->menu_b_p.button_play_p.position);
    menu_d->menu_b_p.button_play_red = sfTexture_createFromFile\
    ("res/play_button_red.png", NULL);
}

void menu_button_quit_res(menu_t *menu_d)
{
    menu_d->menu_b_p.button_quit_p.position = (sfVector2f){300, 645};
    menu_d->menu_b_p.button_quit_p.rect = (sfIntRect){0, 0, 240, 70};
    menu_d->menu_b_p.button_quit_p.texture = sfTexture_createFromFile\
    ("res/quit_button.png", NULL);
    menu_d->menu_b_p.button_quit_p.sprite = sfSprite_create();
    sfSprite_setTexture(menu_d->menu_b_p.button_quit_p.sprite,\
    menu_d->menu_b_p.button_quit_p.texture, sfTrue);
    sfSprite_setTextureRect(menu_d->menu_b_p.button_quit_p.sprite,\
    menu_d->menu_b_p.button_quit_p.rect);
    sfSprite_setPosition(menu_d->menu_b_p.button_quit_p.sprite,\
    menu_d->menu_b_p.button_quit_p.position);
    menu_d->menu_b_p.button_quit_red = sfTexture_createFromFile\
    ("res/quit_button_red.png", NULL);
}

void menu_title_res(menu_t *menu_d)
{
    menu_d->title_p.position = (sfVector2f){630, 0};
    menu_d->title_p.rect = (sfIntRect){0, 0, 650, 180};
    menu_d->title_p.texture = sfTexture_createFromFile("res/title.png", NULL);
    menu_d->title_p.sprite = sfSprite_create();
    sfSprite_setTexture(menu_d->title_p.sprite,\
    menu_d->title_p.texture, sfTrue);
    sfSprite_setTextureRect(menu_d->title_p.sprite, menu_d->title_p.rect);
    sfSprite_setPosition(menu_d->title_p.sprite, menu_d->title_p.position);
}

void menu_empire_logo_res(menu_t *menu_d)
{
    menu_d->empire_logo_p.position = (sfVector2f){505, 560};
    menu_d->empire_logo_p.rect = (sfIntRect){0, 0, 240, 240};
    menu_d->empire_logo_p.texture = sfTexture_createFromFile\
    ("res/empire_logo.png", NULL);
    menu_d->empire_logo_p.sprite = sfSprite_create();
    sfSprite_setTexture(menu_d->empire_logo_p.sprite,\
    menu_d->empire_logo_p.texture, sfTrue);
    sfSprite_setTextureRect(menu_d->empire_logo_p.sprite,\
    menu_d->empire_logo_p.rect);
    sfSprite_setPosition(menu_d->empire_logo_p.sprite,\
    menu_d->empire_logo_p.position);
}

void menu_background_res(menu_t *menu_d, window_t window_d)
{
    menu_d->background_p.texture = sfTexture_createFromFile\
    ("res/menu_background.png", NULL);
    menu_d->background_p.sprite = sfSprite_create();
    menu_d->background_p.rect = (sfIntRect)\
    {0, 0, window_d.width,window_d.height};
    menu_d->background_p.position = (sfVector2f){0, 0};
    sfSprite_setTexture(menu_d->background_p.sprite,\
    menu_d->background_p.texture, sfTrue);
    sfSprite_setTextureRect(menu_d->background_p.sprite,\
    menu_d->background_p.rect);
}