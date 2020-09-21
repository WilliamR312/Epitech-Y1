/*
** EPITECH PROJECT, 2019
** GAME_EVENTS
** File description:
** game events manage
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/my_hunter.h"
#include "../include/my.h"

void enemy_01(sfMouseButtonEvent event, ennemis_t *ennemis_d,\
game_01_t *game_01_d)
{
    int x = event.x;
    int y = event.y;

    if (ennemis_d->x_wing_01.state == 1 &&\
    (x > ennemis_d->x_wing_01.g_vessel_p.position.x &&\
    x < (ennemis_d->x_wing_01.g_vessel_p.position.x + 110))\
    && (y > ennemis_d->x_wing_01.g_vessel_p.position.y && y <\
    (ennemis_d->x_wing_01.g_vessel_p.position.y + 110))) {
        ennemis_d->x_wing_01.state = 2;
        sfSound_play(game_01_d->explosion_p.interract_sound);
        sfSprite_setTextureRect(game_01_d->rebel_score.sprite,\
        game_01_d->rebel_score.rect);
        score_rebel_mangement(game_01_d);
    }
}

void enemy_02(sfMouseButtonEvent event, ennemis_t *ennemis_d,\
game_01_t *game_01_d)
{
    int x = event.x;
    int y = event.y;

    if (ennemis_d->x_wing_02.state == 1 &&\
    (x > ennemis_d->x_wing_02.g_vessel_p.position.x &&\
    x < (ennemis_d->x_wing_02.g_vessel_p.position.x + 110)) &&\
    (y > ennemis_d->x_wing_02.g_vessel_p.position.y && y <\
    (ennemis_d->x_wing_02.g_vessel_p.position.y + 110))) {
        ennemis_d->x_wing_02.state = 2;
        sfSound_play(game_01_d->explosion_p.interract_sound);
        sfSprite_setTextureRect(game_01_d->rebel_score.sprite,\
        game_01_d->rebel_score.rect);
        score_rebel_mangement(game_01_d);
    }
}

void shoot_event(sfMouseButtonEvent event, ennemis_t *ennemis_d,\
game_01_t *game_01_d)
{
    enemy_01(event, ennemis_d, game_01_d);
    enemy_02(event, ennemis_d, game_01_d);
}

void shoot_management(all_t *all_sd)
{
    if (sfRenderWindow_pollEvent(all_sd->window_p.window,\
    &all_sd->window_p.event)) {
        if (all_sd->window_p.event.type == sfEvtMouseButtonPressed) {
            sfSound_play(all_sd->game_01_p.shoot_p.interract_sound);
            shoot_event(all_sd->window_p.event.mouseButton,\
            &all_sd->game_01_p.ennemis_p, &all_sd->game_01_p);
        }
        if (all_sd->window_p.event.type == sfEvtMouseMoved) {
            cursor(all_sd->window_p.event.mouseMove,\
            all_sd->game_01_p.cursor_p);
        }
        if (all_sd->window_p.event.type == sfEvtClosed)
            sfRenderWindow_close(all_sd->window_p.window);
    }
}