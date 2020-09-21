/*
** EPITECH PROJECT, 2020
** INIT_MENU_BUTTONS
** File description:
** initialisation of the menu's buttons
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_button_menu(button_t *button, sfVector2f pos, char *path, \
void (* function)(core_t *))
{
    sfIntRect text_rect = {0, 0, 360, 110};
    sfVector2f size = {360, 110};

    button->text_rect = text_rect;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    button->texture = sfTexture_createFromFile(path, NULL);
    sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
    sfRectangleShape_setTextureRect(button->rect, text_rect);
    button->callback = function;
    button->state = 0;
}

void init_menu_buttons(core_t *core_d)
{
    sfVector2f pos1 = {800, 780};
    sfVector2f pos2 = {300, 780};
    sfVector2f pos3 = {1300, 780};

    core_d->menu_scene.nb_buttons = 3;
    core_d->menu_scene.button_tab = NULL;
    core_d->menu_scene.button_tab = malloc(sizeof(button_t) * 3);
    init_button_menu(&core_d->menu_scene.button_tab[0], pos1, \
        "./src/res/buttons/play_button.png", &action_play_button);
    init_button_menu(&core_d->menu_scene.button_tab[1], pos2, \
        "./src/res/buttons/quit_button.png", &action_quit_button);
    init_button_menu(&core_d->menu_scene.button_tab[2], pos3, \
        "./src/res/buttons/htp_button.png", &action_htp_button);
}