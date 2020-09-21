/*
** EPITECH PROJECT, 2020
** DRAW_MENU_GAME
** File description:
** draw menu on game
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

void draw_menu_game(scene_game_t *game, sfRenderWindow *window)
{
    if (game->pause == 0)
        return;
    sfRenderWindow_drawRectangleShape(window, game->game_menu.rect, NULL);
    for (int i = 0; i < game->game_menu.nb_buttons; i++) {
        sfRenderWindow_drawRectangleShape(window, \
        game->game_menu.button_tab[i].rect, NULL);
    }
}