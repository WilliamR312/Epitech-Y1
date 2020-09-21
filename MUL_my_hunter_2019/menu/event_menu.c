/*
** EPITECH PROJECT, 2019
** EVENT_MENU
** File description:
** Manage events on menu
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/my_hunter.h"
#include "../include/my.h"

void manage_click(sfMouseButtonEvent event, all_t *all_sd)
{
    int x = event.x;
    int y = event.y;

    if ((x >= 710 && y >= 645) && ((x <= 710 + 240) && (y <= 645 + 70))) {
        all_sd->game_p.game_statut = 1;
    }
    if ((x >= 300 && y >= 645) && ((x <= 300 + 240) && (y <= 645 + 70))) {
        menu_destroy(all_sd);
        sfRenderWindow_close(all_sd->window_p.window);
    }
}

void analyse_events(all_t *all_sd)
{
    if (sfRenderWindow_pollEvent(all_sd->window_p.window,\
    &all_sd->window_p.event)) {
        if (all_sd->window_p.event.type == sfEvtMouseButtonPressed)
            manage_click(all_sd->window_p.event.mouseButton, all_sd);
        if (all_sd->window_p.event.type == sfEvtClosed)
            sfRenderWindow_close(all_sd->window_p.window);
        if (all_sd->window_p.event.type == sfEvtMouseMoved) {
            button(all_sd->window_p.event.mouseMove ,all_sd->window_p\
            ,&all_sd->menu_p);
        }
    }
}

int button_play(sfMouseMoveEvent event, window_t window_d, menu_t *menu_d)
{
    int x = event.x;
    int y = event.y;

    if ((x >= 710 && y >= 645) && ((x <= 710 + 240) && (y <= 645 + 70))) {
        sfSprite_setTexture(menu_d->menu_b_p.button_play_p.sprite,\
        menu_d->menu_b_p.button_play_red, sfTrue);
        if (menu_d->menu_b_p.button_sound_p.state == 0) {
            sfSound_play(menu_d->menu_b_p.button_sound_p.interract_sound);
            menu_d->menu_b_p.button_sound_p.state = 1;
        }
    } else {
        sfSprite_setTexture(menu_d->menu_b_p.button_play_p.sprite,\
        menu_d->menu_b_p.button_play_p.texture, sfTrue);
        return(1);
    }
    return(0);
}

int button_quit(sfMouseMoveEvent event, window_t window_d, menu_t *menu_d)
{
    int x = event.x;
    int y = event.y;

    if ((x >= 300 && y >= 645) && ((x <= 300 + 240) && (y <= 645 + 70))) {
        sfSprite_setTexture(menu_d->menu_b_p.button_quit_p.sprite,\
         menu_d->menu_b_p.button_quit_red, sfTrue);
        if (menu_d->menu_b_p.button_sound_p.state == 0) {
            sfSound_play(menu_d->menu_b_p.button_sound_p.interract_sound);
            menu_d->menu_b_p.button_sound_p.state = 1;
        }
    } else {
        sfSprite_setTexture(menu_d->menu_b_p.button_quit_p.sprite,\
        menu_d->menu_b_p.button_quit_p.texture, sfTrue);
        return(1);
    }
    return(0);
}

void button(sfMouseMoveEvent event, window_t window_d, menu_t *menu_d)
{
    if (button_play(event, window_d, menu_d) == 1 &&\
    button_quit(event, window_d, menu_d) == 1)
        menu_d->menu_b_p.button_sound_p.state = 0;
}