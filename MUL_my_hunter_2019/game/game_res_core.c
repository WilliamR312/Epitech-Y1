/*
** EPITECH PROJECT, 2019
** GAME_RES_CORE
** File description:
** Manage game element ressources
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/my_hunter.h"
#include "../include/my.h"

void game_cursor_res(game_01_t *game_01_d)
{
    sfVector2f origin = {15, 10};
    game_01_d->cursor_p.texture =\
    sfTexture_createFromFile("res/cursor.png", NULL);
    game_01_d->cursor_p.sprite = sfSprite_create();
    game_01_d->cursor_p.rect = (sfIntRect){0, 0, 27, 22};
    sfSprite_setTexture(game_01_d->cursor_p.sprite,\
    game_01_d->cursor_p.texture, sfTrue);
    sfSprite_setTextureRect(game_01_d->cursor_p.sprite,\
    game_01_d->cursor_p.rect);
    sfSprite_setOrigin(game_01_d->cursor_p.sprite, origin);
}

void game_res_load(game_01_t *game_01_d, window_t window_d)
{
    game_01_d->clock = sfClock_create();
    game_background_load(game_01_d, window_d);
    game_ennemis_load(&game_01_d->ennemis_p);
    game_cursor_res(game_01_d);
    game_sound_res(game_01_d);
    game_hud_load(game_01_d);
}

void game_hud_load(game_01_t *game_01_d)
{
    game_hud_rebel_score_res(game_01_d);
    game_hud_empire_score_res(game_01_d);
}

void game_background_load(game_01_t *game_01_d, window_t window_d)
{
    game_field_res(game_01_d, window_d);
    game_sky_res(game_01_d, window_d);
}

void game_ennemis_load(ennemis_t *ennemis_d)
{
    game_destroy_xwing(ennemis_d);
    game_xwing_01_res(ennemis_d);
    game_xwing_02_res(ennemis_d);
}