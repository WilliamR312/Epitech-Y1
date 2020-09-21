/*
** EPITECH PROJECT, 2020
** MENU_CORE
** File description:
** Main for menu loop
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void draw_buttons(core_t *core_d)
{
    for (int i = 0; i < core_d->menu_scene.nb_buttons; i++) {
        sfRenderWindow_drawRectangleShape(core_d->window_d.window, \
        core_d->menu_scene.button_tab[i].rect, 0);
    }
}

static void check_button_flyover(button_t *button, sfIntRect *rect, \
sfVector2i pos, scene_menu_t *menu)
{
    sfIntRect new_text_rect = {0, 0, 0, 0};

    if (sfIntRect_contains(rect, pos.x, pos.y) == sfTrue) {
        new_text_rect = (sfIntRect) {360, 0, 360, 110};
        sfRectangleShape_setTextureRect(button->rect, new_text_rect);
        if (button->state == 0)
            sfSound_play(menu->menu_bip.sound);
        button->state = 1;
    }
    else if (button->state == 1) {
        new_text_rect = (sfIntRect) {0, 0, 360, 110};
        sfRectangleShape_setTextureRect(button->rect, new_text_rect);
        button->state = 0;
    }
    button->text_rect = new_text_rect;
}

static void button_flyover(core_t *core_d)
{
    sfVector2i pos = {0, 0};
    sfIntRect rect_int = {0, 0, 0, 0};
    sfFloatRect rect_float = {0, 0, 0, 0};

    pos = sfMouse_getPositionRenderWindow(core_d->window_d.window);
    for (int i = 0; i < core_d->menu_scene.nb_buttons; i++) {
        rect_float = sfRectangleShape_getGlobalBounds \
            (core_d->menu_scene.button_tab[i].rect);
        rect_int = (sfIntRect) {rect_float.left, rect_float.top, \
            rect_float.width, rect_float.height};
        check_button_flyover(&core_d->menu_scene.button_tab[i], \
            &rect_int, pos, &core_d->menu_scene);
    }
}

void menu_core(core_t *core_d)
{
    if (core_d->id_prev_scene != 5) {
        init_menu_ressources(core_d);
        sfMusic_play(core_d->menu_scene.menu_music.music);
    }
    sfRectangleShape_setFillColor(core_d->menu_scene.button_tab[2].rect, \
    (sfColor) {255, 255, 255, 255});
    while (sfRenderWindow_isOpen(core_d->window_d.window) && \
    core_d->id_scene == 1) {
        sfRenderWindow_clear(core_d->window_d.window, sfBlue);
        menu_analysis_events(core_d);
        sfRenderWindow_drawSprite(core_d->window_d.window, \
            core_d->menu_scene.background.sprite, NULL);
        button_flyover(core_d);
        draw_buttons(core_d);
        sfRenderWindow_display(core_d->window_d.window);
    }
    if (core_d->id_scene != 5)
        free_menu(&core_d->menu_scene);
}