/*
** EPITECH PROJECT, 2019
** GAME_TRANSITION
** File description:
** Transition
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/struct.h"
#include "../include/my_hunter.h"
#include "../include/my.h"

void menu_to_game_01(all_t *all_sd)
{
    sfRenderWindow_setMouseCursorVisible(all_sd->window_p.window,\
    sfFalse);
    menu_destroy(all_sd);
    all_sd->game_p.game_statut = 2;
    sfMusic_play(all_sd->game_01_p.music_p.music);
    sfMusic_setVolume(all_sd->game_01_p.music_p.music, 10);
    sfMusic_setLoop(all_sd->game_01_p.music_p.music, sfTrue);
    ennemies_spawn(&all_sd->game_01_p.ennemis_p);
}

void ennemies_spawn(ennemis_t *enemies_d)
{
    sfVector2f xwing_01 = {0, 750};
    sfVector2f xwing_02 = {0, 750};

    xwing_01.x = (rand() % 1100) + 50;
    srand(time(NULL));
    xwing_02.x = (rand() % 1100) + 100;
    srand(time(NULL));
    sfSprite_setPosition(enemies_d->x_wing_01.g_vessel_p.sprite, xwing_01);
    sfSprite_setPosition(enemies_d->x_wing_02.g_vessel_p.sprite, xwing_02);
}

void enemies_respawn(all_t *all_sd)
{
    sfVector2f xwing_01 = {0, 750};
    sfVector2f xwing_02 = {0, 750};

    game_xwing_01_res(&all_sd->game_01_p.ennemis_p);
    game_xwing_02_res(&all_sd->game_01_p.ennemis_p);
    xwing_01.x = (rand() % 1100) + 50;
    srand(time(NULL));
    xwing_02.x = (rand() % 1100) + 100;
    sfSprite_setPosition\
    (all_sd->game_01_p.ennemis_p.x_wing_01.g_vessel_p.sprite, xwing_01);
    sfSprite_setPosition\
    (all_sd->game_01_p.ennemis_p.x_wing_02.g_vessel_p.sprite, xwing_02);
}