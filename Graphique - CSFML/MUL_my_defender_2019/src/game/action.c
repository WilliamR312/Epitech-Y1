/*
** EPITECH PROJECT, 2020
** ACTION
** File description:
** Manage game actions
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void game_menu_action_buttons(button_t *button, \
sfVector2f click_position, core_t *core_d)
{
    sfVector2f button_pos = button->pos;
    sfVector2f button_size = {button->text_rect.width, \
        button->text_rect.height};

    if ((click_position.x >= button_pos.x && click_position.y >= \
    button_pos.y) && ((click_position.x <= button_pos.x + button_size.x) \
    && (click_position.y <= button_pos.y + button_size.y)))
        button->callback(core_d);
}

static void play_pause_button(core_t *core_d)
{
    if (core_d->game_scene.pause == 1) {
        core_d->game_scene.pause_b.text_rect.left = 80;
        sfRectangleShape_setTextureRect(core_d->game_scene.pause_b.rect, \
        core_d->game_scene.pause_b.text_rect);
        core_d->game_scene.pause = 0;
    }
    else if (core_d->game_scene.pause == 0) {
        core_d->game_scene.pause_b.text_rect.left = 0;
        sfRectangleShape_setTextureRect(core_d->game_scene.pause_b.rect, \
            core_d->game_scene.pause_b.text_rect);
        core_d->game_scene.pause = 1;
    }
}

static void click_management(core_t *core_d, sfMouseButtonEvent event)
{
    sfFloatRect float_rect = {0, 0, 0, 0};
    sfVector2f click_pos = {event.x, event.y};

    float_rect = sfRectangleShape_getGlobalBounds \
    (core_d->game_scene.pause_b.rect);
    if (sfFloatRect_contains(&float_rect, event.x, event.y) == sfTrue)
        play_pause_button(core_d);
    if (core_d->game_scene.pause == 1) {
        for (int i = 0; i < core_d->game_scene.game_menu.nb_buttons; i++) {
            game_menu_action_buttons \
            (&core_d->game_scene.game_menu.button_tab[i], click_pos, core_d);
        }
    }
}

static void handling_escape(core_t *core_d)
{
    if (core_d->window_d.event.key.code == sfKeyEscape) {
        if (core_d->game_scene.pause == 1) {
            core_d->game_scene.pause_b.text_rect.left = 80;
            sfRectangleShape_setTextureRect(core_d->game_scene.pause_b.rect, \
            core_d->game_scene.pause_b.text_rect);
            core_d->game_scene.pause = 0;
        } else {
            core_d->game_scene.pause_b.text_rect.left = 0;
            sfRectangleShape_setTextureRect(core_d->game_scene.pause_b.rect, \
            core_d->game_scene.pause_b.text_rect);
            core_d->game_scene.pause = 1;
        }
    }
}

void game_analysis_events(core_t *core_d)
{
    if (sfRenderWindow_pollEvent(core_d->window_d.window, \
    &core_d->window_d.event)) {
        if (core_d->window_d.event.type == sfEvtClosed) {
            sfRenderWindow_close(core_d->window_d.window);
            core_d->id_scene = 0;
        }
        if (core_d->window_d.event.type == sfEvtMouseButtonPressed) {
            click_management(core_d, core_d->window_d.event.mouseButton);
            check_shop_actions(&core_d->game_scene, \
                core_d->window_d.event.mouseButton);
        }
        if (core_d->window_d.event.type == sfEvtKeyPressed)
            handling_escape(core_d);
    }
}