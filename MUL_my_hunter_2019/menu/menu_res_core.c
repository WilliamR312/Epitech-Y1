/*
** EPITECH PROJECT, 2019
** MENU_RES_CORE
** File description:
** Manage menu resources loading
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/my_hunter.h"
#include "../include/my.h"

void menu_sound_res(menu_t *menu_d)
{
    menu_d->music_menu_p.music = sfMusic_createFromFile\
    ("res/sound/menu_music.ogg");
    menu_d->menu_b_p.button_sound_p.interract_mem = \
    sfSoundBuffer_createFromFile("res/sound/menu_bip.ogg");
    menu_d->menu_b_p.button_sound_p.interract_sound = sfSound_create();
    sfSound_setBuffer(menu_d->menu_b_p.button_sound_p.interract_sound,\
    menu_d->menu_b_p.button_sound_p.interract_mem);
    sfSound_setVolume(menu_d->menu_b_p.button_sound_p.interract_sound, 10);
}

void menu_destroy(all_t *all_sd)
{
    sfTexture_destroy(all_sd->menu_p.background_p.texture);
    sfSprite_destroy(all_sd->menu_p.background_p.sprite);
    sfTexture_destroy(all_sd->menu_p.menu_b_p.button_play_p.texture);
    sfSprite_destroy(all_sd->menu_p.menu_b_p.button_play_p.sprite);
    sfTexture_destroy(all_sd->menu_p.menu_b_p.button_quit_p.texture);
    sfSprite_destroy(all_sd->menu_p.menu_b_p.button_quit_p.sprite);
    sfTexture_destroy(all_sd->menu_p.menu_b_p.button_play_red);
    sfTexture_destroy(all_sd->menu_p.menu_b_p.button_quit_red);
    sfMusic_destroy(all_sd->menu_p.music_menu_p.music);
    sfSoundBuffer_destroy\
    (all_sd->menu_p.menu_b_p.button_sound_p.interract_mem);
    sfSound_destroy(all_sd->menu_p.menu_b_p.button_sound_p.interract_sound);
}

void menu_res_load(menu_t *menu_d, window_t window_d, game_t *game)
{
    menu_background_res(menu_d, window_d);
    menu_empire_logo_res(menu_d);
    menu_title_res(menu_d);
    menu_button_play_res(menu_d);
    menu_button_quit_res(menu_d);
    menu_sound_res(menu_d);
    menu_d->menu_b_p.button_sound_p.state = 0;
    game->game_statut = 0;
    sfMusic_play(menu_d->music_menu_p.music);
    sfMusic_setVolume(menu_d->music_menu_p.music, 40);
    sfMusic_setLoop(menu_d->music_menu_p.music, sfTrue);
}