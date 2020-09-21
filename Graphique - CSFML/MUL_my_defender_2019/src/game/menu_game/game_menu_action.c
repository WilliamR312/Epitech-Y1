/*
** EPITECH PROJECT, 2020
** GAME_MENU_ACTION
** File description:
** manage actions for the menu durring the game
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

void resume_game_action(core_t *core_d)
{
    sfIntRect text_rect = {core_d->game_scene.pause_b.text_rect.width, \
        0, core_d->game_scene.pause_b.text_rect.width, \
        core_d->game_scene.pause_b.text_rect.width};

    core_d->game_scene.pause = 0;
    sfRectangleShape_setTextureRect(core_d->game_scene.pause_b.rect, \
    text_rect);
    core_d->game_scene.pause_b.text_rect = text_rect;
}

void return_to_menu_game_action(core_t *core_d)
{
    core_d->id_prev_scene = 1;
    core_d->id_scene = 1;
}

void quit_game_action(core_t *core_d)
{
    core_d->id_prev_scene = 1;
    core_d->id_scene = 0;
    sfRenderWindow_close(core_d->window_d.window);
}