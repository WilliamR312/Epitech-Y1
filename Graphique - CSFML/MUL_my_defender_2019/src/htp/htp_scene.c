/*
** EPITECH PROJECT, 2020
** HTP_SCENE
** File description:
** how to play scene
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_htp_ressources(scene_htp_t *htp)
{
    htp->htp_sprite = sfSprite_create();
    htp->htp_text = \
        sfTexture_createFromFile("./src/res/backgrounds/how_to_play.png", \
        NULL);
    htp->exit_sprite = sfSprite_create();
    htp->exit_text = \
        sfTexture_createFromFile("./src/res/buttons/arrow.png", NULL);
    sfSprite_setTexture(htp->htp_sprite, htp->htp_text, \
    sfTrue);
    sfSprite_setTexture(htp->exit_sprite, htp->exit_text, sfTrue);
}

static void click_back_to_menu(core_t *core_d, \
sfMouseButtonEvent event)
{
    int x = event.x;
    int y = event.y;
    sfVector2f pos = sfSprite_getPosition(core_d->htp_scene.exit_sprite);

    if (x > pos.x && x < pos.x + 100 && y > pos.y && y < pos.y + 100) {
        core_d->id_scene = core_d->id_prev_scene;
        core_d->id_prev_scene = 5;
    }
}

static void events_htp(core_t *core_d)
{
    if (sfRenderWindow_pollEvent(core_d->window_d.window, \
    &core_d->window_d.event)) {
        if (core_d->window_d.event.type == sfEvtClosed) {
            sfRenderWindow_close(core_d->window_d.window);
            core_d->id_scene = 0;
        }
        if (core_d->window_d.event.type == sfEvtMouseButtonPressed)
            click_back_to_menu(core_d, core_d->window_d.event.mouseButton);
    }
}

static void free_htp(scene_htp_t *htp)
{
    sfSprite_destroy(htp->exit_sprite);
    sfSprite_destroy(htp->htp_sprite);
    sfTexture_destroy(htp->exit_text);
    sfTexture_destroy(htp->htp_text);
}

void htp_scene(core_t *core_d)
{
    init_htp_ressources(&core_d->htp_scene);
    while (sfRenderWindow_isOpen(core_d->window_d.window) && \
    core_d->id_scene == 5) {
        sfRenderWindow_clear(core_d->window_d.window, sfBlue);
        sfRenderWindow_drawSprite(core_d->window_d.window, \
        core_d->htp_scene.htp_sprite, NULL);
        sfRenderWindow_drawSprite(core_d->window_d.window, \
        core_d->htp_scene.exit_sprite, NULL);
        sfRenderWindow_display(core_d->window_d.window);
        events_htp(core_d);
    }
    free_htp(&core_d->htp_scene);
    if (core_d->id_prev_scene == 3)
        free_game_core(&core_d->game_scene);
    else if (core_d->id_prev_scene == 1)
        free_menu(&core_d->menu_scene);
}