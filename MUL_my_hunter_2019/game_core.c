/*
** EPITECH PROJECT, 2019
** GAME_CORE_MY_HUNTER
** File description:
** game core for my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "./include/struct.h"
#include "./include/tab_state_game.h"
#include "./include/my_hunter.h"
#include "./include/my.h"

void createMyWindow(window_t *window_d)
{
    sfVideoMode video_mode;

    window_d->width = 1280;
    window_d->height = 800;
    video_mode.width = window_d->width;
    video_mode.height = window_d->height;
    video_mode.bitsPerPixel = 32;
    window_d->window = sfRenderWindow_create(video_mode,\
    "Star Wars : Repression", sfClose, NULL);
}

void ressource_load(all_t *all_sd)
{
    createMyWindow(&all_sd->window_p);
    menu_res_load(&all_sd->menu_p, all_sd->window_p, &all_sd->game_p);
    game_res_load(&all_sd->game_01_p, all_sd->window_p);
}

void game_state(all_t *all_sd)
{
    for (int cursor = 0; tab_game_statut[cursor].statut < 3; cursor++) {
        if (tab_game_statut[cursor].statut == all_sd->game_p.game_statut)
            tab_game_statut[cursor].f(all_sd);
    }
}

void help_display(void) {
        my_putstr("DESCRIPTION :\n");
        my_putstr("    Star Wars : Repression is a Duck Hunt like on the\
        universe of Star Wars\n\n");
        my_putstr("MANUAL :\n");
        my_putstr("    Clic on the Rebel's enemies (x_wing) to destroy them\
        and stop their defenses ! [Right and Left button is possible]\n");
}

void game_loop(void)
{
    all_t all_sd;

    ressource_load(&all_sd);
    while (sfRenderWindow_isOpen(all_sd.window_p.window)) {
        sfRenderWindow_clear(all_sd.window_p.window, sfBlue);
        game_state(&all_sd);
        sfRenderWindow_display(all_sd.window_p.window);
    }
    sfRenderWindow_destroy(all_sd.window_p.window);
}