/*
** EPITECH PROJECT, 2020
** RESULT
** File description:
** result events and scene managing
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void click_back_to_menu(core_t *core_d)
{
    if (core_d->window_d.event.key.code == sfKeyEscape) {
        core_d->id_prev_scene = core_d->id_scene;
        core_d->id_scene = 1;
    }
}

static void events_result(core_t *core_d)
{
    if (sfRenderWindow_pollEvent(core_d->window_d.window, \
    &core_d->window_d.event)) {
        if (core_d->window_d.event.type == sfEvtClosed) {
            sfRenderWindow_close(core_d->window_d.window);
            core_d->id_scene = 0;
            core_d->id_prev_scene = 3;
        }
        if (core_d->window_d.event.type == sfEvtKeyPressed)
            click_back_to_menu(core_d);
    }
}

static void free_result(result_scene_t *result)
{
    sfSprite_destroy(result->result_sprite);
    sfTexture_destroy(result->result_text);
    sfText_destroy(result->score_text.valor);
    sfText_destroy(result->score_text.text);
}

static void draw_final_score(core_t *core)
{
    char *str = NULL;

    str = my_atoi(core->result_scene.score);
    sfText_setString(core->result_scene.score_text.valor, str);
    free(str);
    sfRenderWindow_drawText(core->window_d.window, \
    core->result_scene.score_text.valor, NULL);
    sfRenderWindow_drawText(core->window_d.window, \
    core->result_scene.score_text.text, NULL);
}

void result_scene(core_t *core_d)
{
    init_result_ressources(core_d);
    while (sfRenderWindow_isOpen(core_d->window_d.window) && \
    core_d->id_scene == 4) {
        sfRenderWindow_clear(core_d->window_d.window, sfBlue);
        sfRenderWindow_drawSprite(core_d->window_d.window, \
        core_d->result_scene.result_sprite, NULL);
        draw_final_score(core_d);
        events_result(core_d);
        sfRenderWindow_display(core_d->window_d.window);
    }
    free_result(&core_d->result_scene);
}