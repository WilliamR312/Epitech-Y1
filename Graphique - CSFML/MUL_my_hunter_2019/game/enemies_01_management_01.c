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

void enemies_01_colision_left(window_t window_d, v_01_t *vessel_d,\
int x, int y)
{
    if (x < 0) {
        vessel_d->g_vessel_p.position.x = vessel_d->g_vessel_p.position.x + 1;
        sfSprite_setPosition(vessel_d->g_vessel_p.sprite,\
        vessel_d->g_vessel_p.position);
        vessel_d->offset.x = vessel_d->offset.x * (-1);
        vessel_d->g_vessel_p.rect.top = vessel_d->g_vessel_p.rect.top - 50;
        sfSprite_setTextureRect(vessel_d->g_vessel_p.sprite,\
        vessel_d->g_vessel_p.rect);
    }
}

void enemies_01_colision_right(window_t window_d, v_01_t *vessel_d,\
int x, int y)
{
    if (x > 1180) {
        vessel_d->g_vessel_p.position.x = vessel_d->g_vessel_p.position.x - 1;
        sfSprite_setPosition(vessel_d->g_vessel_p.sprite,\
        vessel_d->g_vessel_p.position);
        vessel_d->offset.x = vessel_d->offset.x * (-1);
        vessel_d->g_vessel_p.rect.top = vessel_d->g_vessel_p.rect.top + 50;
        sfSprite_setTextureRect(vessel_d->g_vessel_p.sprite,\
        vessel_d->g_vessel_p.rect);
    }
}

void enemies_01_colision_up(window_t window_d, v_01_t *vessel_d,\
int x, int y)
{
    if (y < -15) {
        vessel_d->g_vessel_p.position.y = vessel_d->g_vessel_p.position.y + 1;
        sfSprite_setPosition(vessel_d->g_vessel_p.sprite,\
        vessel_d->g_vessel_p.position);
        vessel_d->offset.y = vessel_d->offset.y * (-1);
    }
}

void enemies_01_colision_down(window_t window_d, v_01_t *vessel_d,\
int x, int y)
{
    if (y > 700) {
        vessel_d->g_vessel_p.position.y =\
        vessel_d->g_vessel_p.position.y - 1;
        sfSprite_setPosition(vessel_d->g_vessel_p.sprite,\
        vessel_d->g_vessel_p.position);
        vessel_d->offset.y = vessel_d->offset.y * (-1);
    }
}

void enemies_01_colision_management(window_t window_d, v_01_t *vessel_d)
{
    int x = vessel_d->g_vessel_p.position.x;
    int y = vessel_d->g_vessel_p.position.y;

    enemies_01_colision_left(window_d, vessel_d, x, y);
    enemies_01_colision_right(window_d, vessel_d, x, y);
    enemies_01_colision_down(window_d, vessel_d, x, y);
    enemies_01_colision_up(window_d, vessel_d, x, y);
}