/*
** EPITECH PROJECT, 2020
** GAME_CORE_MY_RUNNER
** File description:
** game core for my_runner
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

void game_core(core_t *core_d)
{
    load_ressource(core_d);
    core_d->game_state = 1;
    while (sfRenderWindow_isOpen(core_d->window_p.window) &&\
    core_d->game_state != 0) {
        sfRenderWindow_clear(core_d->window_p.window, sfBlue);
        analysis_events(core_d);
        draw_background_core(core_d);
        core_d->character_data.ground = 0;
        map_display(core_d);
        character_management(core_d);
        score_management(core_d);
        sfRenderWindow_display(core_d->window_p.window);
    }
    exit_free_res(core_d);
}