/*
** EPITECH PROJECT, 2020
** GAME_CORE
** File description:
** Main for game loop
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void objects_management(core_t *core_d)
{
    draw_score_ingame(core_d);
    draw_life(core_d);
    draw_money(core_d);
    draw_wave(core_d->window_d.window, &core_d->game_scene);
    draw_shop(core_d);
    draw_tower_on_map(core_d);
    draw_menu_game(&core_d->game_scene, core_d->window_d.window);
}

static void check_result(core_t *core_d)
{
    if (core_d->game_scene.wave_data.actual_wave == \
        core_d->game_scene.wave_data.max_wave || core_d->game_scene.life <= 0)
        core_d->id_scene = 4;
}

static void waves_system(core_t *core_d)
{
    if (core_d->game_scene.wave_data.nb_enemy == 0 && \
        core_d->game_scene.wave_data.actual_wave != \
        core_d->game_scene.wave_data.max_wave) {
            init_wave(core_d);
            core_d->game_scene.wave_data.actual_wave += 1;
        }
}

void game_core(core_t *core_d)
{
    if (core_d->id_prev_scene == 2)
        init_game_ressources(core_d);
    while (sfRenderWindow_isOpen(core_d->window_d.window) && \
    core_d->id_scene == 3) {
        waves_system(core_d);
        check_result(core_d);
        sfRenderWindow_clear(core_d->window_d.window, sfBlue);
        sfRenderWindow_drawSprite(core_d->window_d.window, \
            core_d->game_scene.background.sprite, NULL);
        sfRenderWindow_drawRectangleShape(core_d->window_d.window, \
            core_d->game_scene.pause_b.rect, NULL);
        objects_management(core_d);
        game_analysis_events(core_d);
        sfRenderWindow_display(core_d->window_d.window);
    }
    if (core_d->id_scene != 5)
        free_game_core(&core_d->game_scene);
}