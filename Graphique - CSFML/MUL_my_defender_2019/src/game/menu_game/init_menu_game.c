/*
** EPITECH PROJECT, 2020
** INIT_MENU_GAME
** File description:
** initialisation of the game menu ressources
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_button_menu_game(button_t *button, sfVector2f pos, \
char *path, void (* function)(core_t *))
{
    sfIntRect text_rect = {0, 0, 400, 60};
    sfVector2f size = {400, 60};

    button->text_rect = text_rect;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    button->texture = sfTexture_createFromFile(path, NULL);
    sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
    sfRectangleShape_setTextureRect(button->rect, text_rect);
    button->callback = function;
    button->state = 0;
    button->pos = pos;
}

static void init_menu_window(game_menu_t *game_menu)
{
    sfVector2f size = {550, 500};
    sfVector2f pos = {910 - (550 / 2), 540 - 300};
    sfColor color = {100, 100, 255, 100};

    game_menu->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(game_menu->rect, pos);
    sfRectangleShape_setSize(game_menu->rect, size);
    sfRectangleShape_setFillColor(game_menu->rect, color);
}

void init_menu_game(game_menu_t *game_menu)
{
    sfVector2f pos1 = {910 - (500 / 2) + 50, 300};
    sfVector2f pos2 = {910 - (500 / 2) + 50, 400};
    sfVector2f pos3 = {910 - (500 / 2) + 50, 500};
    sfVector2f pos4 = {910 - (500 / 2) + 50, 600};

    game_menu->button_tab = NULL;
    game_menu->nb_buttons = 4;
    game_menu->button_tab = malloc(sizeof(button_t) * game_menu->nb_buttons);
    init_button_menu_game(&game_menu->button_tab[0], pos1, \
    "./src/res/buttons/resume_b_gm.png", &resume_game_action);
    init_button_menu_game(&game_menu->button_tab[1], pos2, \
    "./src/res/buttons/htp_b_gm.png", &action_htp_button);
    init_button_menu_game(&game_menu->button_tab[2], pos3, \
    "./src/res/buttons/return_b_gm.png", &return_to_menu_game_action);
    init_button_menu_game(&game_menu->button_tab[3], pos4, \
    "./src/res/buttons/quit_b_gm.png", &quit_game_action);
    init_menu_window(game_menu);
}