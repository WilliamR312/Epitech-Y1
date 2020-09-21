/*
** EPITECH PROJECT, 2020
** MENU
** File description:
** Main for menu
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_sound(sound_t *sound, char *path, int volume)
{
    sound->sound_b = sfSoundBuffer_createFromFile(path);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->sound_b);
    sfSound_setVolume(sound->sound, volume);
}

static void init_music(music_t *music, char *path, int volume, int loop)
{
    music->music = sfMusic_createFromFile(path);
    sfMusic_setVolume(music->music, volume);
    if (loop == 1)
        sfMusic_setLoop(music->music, sfTrue);
}

void init_menu_sounds(scene_menu_t *menu)
{
    init_sound(&menu->menu_bip, "./src/res/sounds/menu_bip.ogg", 80);
    init_music(&menu->menu_music, "./src/res/sounds/menu_music.ogg", 100, 1);
}