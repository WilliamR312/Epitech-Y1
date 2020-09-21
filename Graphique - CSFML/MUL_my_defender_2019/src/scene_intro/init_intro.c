/*
** EPITECH PROJECT, 2020
** init_intro.c
** File description:
** init intro resources
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_intro_ressources(scene_intro_t *intro)
{
    intro->sprite = sfSprite_create();
    intro->texture = \
        sfTexture_createFromFile("./src/res/backgrounds/intro.png", NULL);
    intro->music = sfMusic_createFromFile("./src/res/sounds/intro_music.ogg");
    sfMusic_setVolume(intro->music, 100);
    sfMusic_play(intro->music);
    sfSprite_setTexture(intro->sprite, intro->texture, sfTrue);
}

static void skip_intro(core_t *core_d)
{
    core_d->id_prev_scene = 2;
    core_d->id_scene = 3;
}

static void events_intro(core_t *core_d)
{
    if (sfRenderWindow_pollEvent(core_d->window_d.window, \
    &core_d->window_d.event)) {
        if (core_d->window_d.event.type == sfEvtClosed) {
            sfRenderWindow_close(core_d->window_d.window);
            core_d->id_scene = 0;
        }
        if (core_d->window_d.event.key.code == sfKeyEscape)
            skip_intro(core_d);
    }
}

static void free_intro(scene_intro_t *intro)
{
    sfSprite_destroy(intro->sprite);
    sfTexture_destroy(intro->texture);
    if (sfMusic_getStatus(intro->music) != sfStopped)
        sfMusic_stop(intro->music);
    sfMusic_destroy(intro->music);
}

void intro_scene(core_t *core_d)
{
    init_intro_ressources(&core_d->intro);
    while (sfRenderWindow_isOpen(core_d->window_d.window) && \
    core_d->id_scene == 2) {
        sfRenderWindow_clear(core_d->window_d.window, sfBlue);
        sfRenderWindow_drawSprite(core_d->window_d.window, \
        core_d->intro.sprite, NULL);
        sfRenderWindow_display(core_d->window_d.window);
        events_intro(core_d);
    }
    free_intro(&core_d->intro);
}
