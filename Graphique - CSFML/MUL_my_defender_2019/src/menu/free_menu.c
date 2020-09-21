/*
** EPITECH PROJECT, 2020
** FREE_MENU
** File description:
** free menu ressources
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void free_sounds(scene_menu_t *menu)
{
    sfMusic_stop(menu->menu_music.music);
    sfMusic_destroy(menu->menu_music.music);
    if (sfSound_getStatus(menu->menu_bip.sound) != sfStopped)
        sfSound_stop(menu->menu_bip.sound);
    sfSound_destroy(menu->menu_bip.sound);
    sfSoundBuffer_destroy(menu->menu_bip.sound_b);
}

static void free_buttons(scene_menu_t *menu)
{
    for (int i = 0; i < menu->nb_buttons; i++) {
        sfRectangleShape_destroy(menu->button_tab[i].rect);
        sfTexture_destroy(menu->button_tab[i].texture);
    }
    free(menu->button_tab);
}

static void free_background(background_t *back)
{
    sfSprite_destroy(back->sprite);
    sfTexture_destroy(back->texture);
}

void free_menu(scene_menu_t *menu)
{
    free_sounds(menu);
    free_buttons(menu);
    free_background(&menu->background);
}
