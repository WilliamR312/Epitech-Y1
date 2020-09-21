/*
** EPITECH PROJECT, 2019
** GAME_01
** File description:
** game 01 manage
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/my_hunter.h"
#include "../include/my.h"

void score_rebel_mangement(game_01_t *game_01_d)
{
    game_01_d->rebel_score.rect.left =\
    game_01_d->rebel_score.rect.left + 430;
    if (game_01_d->rebel_score.rect.left == 1720 &&\
    game_01_d->rebel_score.rect.top != -126) {
        game_01_d->rebel_score.rect.left = 0;
        game_01_d->rebel_score.rect.top =\
        game_01_d->rebel_score.rect.top + 42;
    }
    if (game_01_d->rebel_score.rect.left == 1290 &&\
    game_01_d->rebel_score.rect.top == 84) {
        game_01_d->rebel_score.rect.left = 0;
        game_01_d->rebel_score.rect.top = 0;
    }
    sfSprite_setTextureRect(game_01_d->rebel_score.sprite,\
    game_01_d->rebel_score.rect);
}

void cursor(sfMouseMoveEvent event, cursor_t cursor_d)
{
    sfVector2f pos = {event.x, event.y};

    sfSprite_setPosition(cursor_d.sprite, pos);
}

void enemies_management(all_t *all_sd)
{
    shoot_management(all_sd);
    ennemis_01_management(&all_sd->game_01_p.ennemis_p.x_wing_01, all_sd);
    ennemis_01_management(&all_sd->game_01_p.ennemis_p.x_wing_02, all_sd);
    if (all_sd->game_01_p.ennemis_p.x_wing_02.state == 0 &&\
    all_sd->game_01_p.ennemis_p.x_wing_01.state == 0) {
        enemies_respawn(all_sd);
    }
}

void game_01_display_element(all_t *all_sd)
{
    sfRenderWindow_drawSprite(all_sd->window_p.window,\
    all_sd->game_01_p.sprite_sky, NULL);
    sfRenderWindow_drawSprite(all_sd->window_p.window,\
    all_sd->game_01_p.sprite_field, NULL);
    sfRenderWindow_drawSprite(all_sd->window_p.window,\
    all_sd->game_01_p.rebel_score.sprite, NULL);
    sfRenderWindow_drawSprite(all_sd->window_p.window,\
    all_sd->game_01_p.empire_score.sprite, NULL);
}

void game_01(all_t *all_sd)
{
    game_01_display_element(all_sd);
    enemies_management(all_sd);
    sfRenderWindow_drawSprite(all_sd->window_p.window,\
    all_sd->game_01_p.cursor_p.sprite, NULL);
}