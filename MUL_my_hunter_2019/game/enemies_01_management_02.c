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

void ennemis_01_animation(v_01_t *vessel_d)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(vessel_d->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.05) {
        vessel_d->g_vessel_p.rect.left = vessel_d->g_vessel_p.rect.left + 125;
        if (vessel_d->g_vessel_p.rect.left == 250)
            vessel_d->g_vessel_p.rect.left = 0;
        sfClock_restart(vessel_d->clock);
        sfSprite_setTextureRect(vessel_d->g_vessel_p.sprite,\
        vessel_d->g_vessel_p.rect);
    }
}

void ennemis_01_destroy_animation(v_01_t *vessel_d)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(vessel_d->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        vessel_d->g_vessel_p.rect.left = vessel_d->g_vessel_p.rect.left + 90;
        if (vessel_d->g_vessel_p.rect.left == 270)
            vessel_d->g_vessel_p.rect.left = 0;
        sfClock_restart(vessel_d->clock);
        sfSprite_setTextureRect(vessel_d->g_vessel_p.sprite,\
        vessel_d->g_vessel_p.rect);
    }
}

void enemies_01_despawn(all_t *all_sd, v_01_t *vessel_d)
{
    if (vessel_d->g_vessel_p.position.y > 780) {
        sfSound_play(all_sd->game_01_p.explosion_p.interract_sound);
        sfSprite_destroy(vessel_d->g_vessel_p.sprite);
        vessel_d->state = 0;
    }
}

void ennemis_01_destroy(v_01_t *vessel_d, all_t *all_sd)
{
    if (vessel_d->state == 2) {
        vessel_d->g_vessel_p.texture = sfTexture_copy\
        (all_sd->game_01_p.ennemis_p.destroy_x_wing.texture);
        vessel_d->g_vessel_p.rect = sfSprite_getTextureRect\
        (all_sd->game_01_p.ennemis_p.destroy_x_wing.sprite);
        sfSprite_setTexture(vessel_d->g_vessel_p.sprite,\
        vessel_d->g_vessel_p.texture, sfTrue);
        sfSprite_setTextureRect(vessel_d->g_vessel_p.sprite,\
        all_sd->game_01_p.ennemis_p.destroy_x_wing.rect);
        vessel_d->offset.x = vessel_d->offset.x * 0.5;
        vessel_d->offset.y = 0.5;
        vessel_d->state = 3;
    }
    sfRenderWindow_drawSprite(all_sd->window_p.window,\
    vessel_d->g_vessel_p.sprite, NULL);
    sfSprite_move(vessel_d->g_vessel_p.sprite, vessel_d->offset);
    ennemis_01_destroy_animation(vessel_d);
    vessel_d->g_vessel_p.position = sfSprite_getPosition\
    (vessel_d->g_vessel_p.sprite);
    enemies_01_despawn(all_sd, vessel_d);
}

void ennemis_01_management(v_01_t *vessel_d, all_t *all_sd)
{
    if (vessel_d->state != 4) {
        if (vessel_d->state == 1) {
            sfRenderWindow_drawSprite(all_sd->window_p.window,\
            vessel_d->g_vessel_p.sprite, NULL);
            vessel_d->g_vessel_p.position = sfSprite_getPosition\
            (vessel_d->g_vessel_p.sprite);
            ennemis_01_animation(vessel_d);
            sfSprite_move(vessel_d->g_vessel_p.sprite,\
            vessel_d->offset);
            enemies_01_colision_management(all_sd->window_p, vessel_d);
        }
        else if (vessel_d->state == 2 || vessel_d->state == 3) {
            ennemis_01_destroy(vessel_d, all_sd);
        }
    }
}