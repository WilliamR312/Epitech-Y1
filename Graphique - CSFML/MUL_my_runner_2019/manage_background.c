/*
** EPITECH PROJECT, 2020
** MANAGE_BACKGROUND
** File description:
** manage background and their parallax
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void move_background(p_element_t *back_d, float time, float offset)
{
    sfTime timer;
    float seconds;

    timer = sfClock_getElapsedTime(back_d->clock);
    seconds = timer.microseconds / 1000000.0;
    if (seconds > time) {
        sfSprite_move(back_d->sprite, (sfVector2f) {-offset, 0});
        sfClock_restart(back_d->clock);
    }
}

static void parallax_system(p_element_t *back_d)
{
    sfVector2f position = {0, 0};

    position = sfSprite_getPosition(back_d->sprite);
    if (position.x == -1280)
        sfSprite_setPosition(back_d->sprite, (sfVector2f) {0, 0});
}

static void draw_background(core_t *core_d, p_element_t *back_d, float time,\
float offset)
{
    if (offset != 0 && (core_d->character_data.state != 4 &&\
    core_d->character_data.state != 5))
        move_background(back_d, time, offset);
    sfRenderWindow_drawSprite(core_d->window_p.window, back_d->sprite, NULL);
    parallax_system(back_d);
}

void draw_background_core(core_t *core_d)
{
    draw_background(core_d, &core_d->background.back_00, 0.1, 0);
    draw_background(core_d, &core_d->background.back_01, 0.09, 1);
    draw_background(core_d, &core_d->background.back_02, 0.01, 1);
    draw_background(core_d, &core_d->background.back_03, 0.008, 2);
}