/*
** EPITECH PROJECT, 2020
** DRAW TEXTS
** File description:
** draw all texts on the game
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

void draw_life(core_t *core)
{
    char *str = NULL;

    str = my_atoi(core->game_scene.life);
    sfText_setString(core->game_scene.life_text.valor, str);
    free(str);
    sfRenderWindow_drawText(core->window_d.window, \
    core->game_scene.life_text.valor, NULL);
    sfRenderWindow_drawText(core->window_d.window, \
    core->game_scene.life_text.text, NULL);
}

void draw_money(core_t *core)
{
    char *str = NULL;

    str = my_atoi(core->game_scene.money);
    sfText_setString(core->game_scene.money_text.valor, str);
    free(str);
    sfRenderWindow_drawText(core->window_d.window, \
    core->game_scene.money_text.text, NULL);
    sfRenderWindow_drawText(core->window_d.window, \
    core->game_scene.money_text.valor, NULL);
}

void draw_score_ingame(core_t *core)
{
    char *str = NULL;

    str = my_atoi(core->game_scene.score);
    sfText_setString(core->game_scene.score_text.valor, str);
    free(str);
    sfRenderWindow_drawText(core->window_d.window, \
    core->game_scene.score_text.valor, NULL);
    sfRenderWindow_drawText(core->window_d.window, \
    core->game_scene.score_text.text, NULL);
}