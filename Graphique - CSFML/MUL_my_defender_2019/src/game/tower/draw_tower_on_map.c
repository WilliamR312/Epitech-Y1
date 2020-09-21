/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** shop
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void draw_tower(scene_game_t *game, sfRenderWindow *window)
{
    tower_on_map_t *element = NULL;

    element = game->tower_on_map;
    for (int i = 0; i < game->nb_tower_map; i++) {
        sfRenderWindow_drawSprite(window, element->tower.sprite, NULL);
        if (game->wave_data.nb_enemy > 0)
            check_tower_attack(game, &element->tower);
        element = element->next;
    }
}

void draw_tower_on_map(core_t *core_d)
{
    if (core_d->game_scene.nb_tower_map != 0)
        draw_tower(&core_d->game_scene, core_d->window_d.window);
}