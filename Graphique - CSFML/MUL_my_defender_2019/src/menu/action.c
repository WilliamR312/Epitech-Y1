/*
** EPITECH PROJECT, 2020
** ACTION
** File description:
** Action
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void button_is_clicked(button_t *button, sfVector2f click_position, \
core_t *core_d)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f button_size = sfRectangleShape_getSize(button->rect);

    if ((click_position.x >= button_pos.x && click_position.y >= \
    button_pos.y) && ((click_position.x <= button_pos.x + button_size.x) \
    && (click_position.y <= button_pos.y + button_size.y)))
        button->callback(core_d);
}

static void click_management(core_t *core_d, sfMouseButtonEvent event)
{
    sfVector2f click_pos = {event.x, event.y};

    for (int i = 0; i < core_d->menu_scene.nb_buttons; i++) {
        button_is_clicked(&core_d->menu_scene.button_tab[i], click_pos, \
        core_d);
    }
}

void menu_analysis_events(core_t *core_d)
{
    if (sfRenderWindow_pollEvent(core_d->window_d.window, \
    &core_d->window_d.event)) {
        if (core_d->window_d.event.type == sfEvtClosed) {
            sfRenderWindow_close(core_d->window_d.window);
            core_d->id_scene = 0;
        }
        if (core_d->window_d.event.type == sfEvtMouseButtonPressed)
            click_management(core_d, core_d->window_d.event.mouseButton);
    }
}