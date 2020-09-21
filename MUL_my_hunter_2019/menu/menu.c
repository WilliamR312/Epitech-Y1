/*
** EPITECH PROJECT, 2019
** MENU
** File description:
** Manage menu elements
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/my_hunter.h"
#include "../include/my.h"

void menu_display_elements(window_t window_d, menu_t menu_d)
{
    sfRenderWindow_drawSprite(window_d.window, menu_d.background_p.sprite,\
    NULL);
    sfRenderWindow_drawSprite(window_d.window, menu_d.title_p.sprite, NULL);
    sfRenderWindow_drawSprite(window_d.window, menu_d.empire_logo_p.sprite,\
    NULL);
    sfRenderWindow_drawSprite(window_d.window,\
    menu_d.menu_b_p.button_play_p.sprite, NULL);
    sfRenderWindow_drawSprite(window_d.window,\
    menu_d.menu_b_p.button_quit_p.sprite, NULL);
}

void menu(all_t *all_sd)
{
    menu_display_elements(all_sd->window_p, all_sd->menu_p);
    analyse_events(all_sd);
}