/*
** EPITECH PROJECT, 2020
** SCORE_MANAGEMENT
** File description:
** manage score for my_runner
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void display_score_dead(core_t *core_d)
{
    sfText_setString(core_d->text_d.result, "YOU ARE LOST");
    sfRenderWindow_drawText(core_d->window_p.window,\
    core_d->text_d.result, NULL);
    sfText_setPosition(core_d->text_d.text_1, (sfVector2f){450, 200});
    sfRenderWindow_drawText(core_d->window_p.window,\
    core_d->text_d.text_1, NULL);
    sfText_setPosition(core_d->text_d.text_2, (sfVector2f){700, 200});
    sfRenderWindow_drawText(core_d->window_p.window,\
    core_d->text_d.text_2, NULL);
    sfRenderWindow_drawText(core_d->window_p.window,\
    core_d->text_d.restart, NULL);
}

static void display_score_alive(core_t *core_d)
{
    sfTime time;
    float seconds;

    core_d->score_d.score_str = my_atoi(core_d->score_d.score_int);
    time = sfClock_getElapsedTime(core_d->score_d.clock_score);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 1 && core_d->character_data.state != 4) {
        core_d->score_d.score_int = core_d->score_d.score_int + 10;
        sfClock_restart(core_d->score_d.clock_score);
    }
    sfText_setPosition(core_d->text_d.text_1, (sfVector2f){0, 0});
    sfText_setPosition(core_d->text_d.text_2, (sfVector2f){230, 0});
    sfRenderWindow_drawText(core_d->window_p.window,\
    core_d->text_d.text_1, NULL);
    sfText_setString(core_d->text_d.text_2, core_d->score_d.score_str);
    sfRenderWindow_drawText(core_d->window_p.window,\
    core_d->text_d.text_2, NULL);
    free(core_d->score_d.score_str);
}

static void display_score_win(core_t *core_d)
{
    sfText_setString(core_d->text_d.result, "YOU ARE FREE");
    sfText_setFillColor(core_d->text_d.result, (sfColor){0, 0, 255, 255});
    sfRenderWindow_drawText(core_d->window_p.window,\
    core_d->text_d.result, NULL);
    sfText_setPosition(core_d->text_d.text_1, (sfVector2f){450, 200});
    sfRenderWindow_drawText(core_d->window_p.window,\
    core_d->text_d.text_1, NULL);
    sfText_setPosition(core_d->text_d.text_2, (sfVector2f){700, 200});
    sfRenderWindow_drawText(core_d->window_p.window,\
    core_d->text_d.text_2, NULL);
    sfRenderWindow_drawText(core_d->window_p.window,\
    core_d->text_d.restart, NULL);
}

void score_management(core_t *core_d)
{
    if (core_d->game_state == 1)
        display_score_alive(core_d);
    if (core_d->game_state == 2)
        display_score_dead(core_d);
    if (core_d->game_state == 5)
        display_score_win(core_d);
}