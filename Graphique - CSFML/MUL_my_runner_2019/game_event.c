/*
** EPITECH PROJECT, 2020
** GAME_EVENT
** File description:
** manage game event
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void event_char_jump(char_t *char_d, sfKeyEvent key, sound_t *sound_d)
{
    if (key.code == sfKeySpace) {
        char_d->clock_jump = sfClock_create();
        char_d->state = 2;
        sound_d->state = 1;
    }
}

void analysis_events(core_t *core_d)
{
    if (sfRenderWindow_pollEvent(core_d->window_p.window,\
    &core_d->window_p.event)) {
        if (core_d->window_p.event.type == sfEvtClosed)
            sfRenderWindow_close(core_d->window_p.window);
        if (core_d->window_p.event.type == sfEvtKeyPressed &&\
        core_d->character_data.state == 1)
            event_char_jump(&core_d->character_data,\
            core_d->window_p.event.key, &core_d->all_sounds_d.sound_data);
        if (core_d->window_p.event.type == sfEvtKeyPressed &&\
        (core_d->game_state == 2 || core_d->game_state == 5))
            restart_key_game(core_d, core_d->window_p.event.key);
    }
}