/*
** EPITECH PROJECT, 2020
** BUTTONS ACTION
** File description:
** manage buttons actions on the menu
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

void action_play_button(core_t *core_d)
{
    core_d->id_prev_scene = 1;
    core_d->id_scene = 2;
    sfRectangleShape_setFillColor(core_d->menu_scene.button_tab[0].rect, \
    (sfColor) {150, 150, 255, 255});
}

void action_quit_button(core_t *core_d)
{
    core_d->id_prev_scene = 1;
    core_d->id_scene = 0;
    sfRenderWindow_close(core_d->window_d.window);
}

void action_htp_button(core_t *core_d)
{
    core_d->id_prev_scene = core_d->id_scene;
    core_d->id_scene = 5;
    if (core_d->id_prev_scene == 1)
        sfRectangleShape_setFillColor(core_d->menu_scene.button_tab[2].rect, \
        (sfColor) {150, 255, 150, 255});
}