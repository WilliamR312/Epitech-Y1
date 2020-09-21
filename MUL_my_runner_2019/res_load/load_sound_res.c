/*
** EPITECH PROJECT, 2020
** LOAD_SOUND_RES
** File description:
** manage loading of ressources
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

void load_sound_res(all_sounds_t *all_sounds_d)
{
    all_sounds_d->music_1 = sfMusic_createFromFile("./res/sound/music_1.ogg");
    sfMusic_play(all_sounds_d->music_1);
    all_sounds_d->sound_data.sound_b =\
    sfSoundBuffer_createFromFile("./res/sound/sound_1.ogg");
    all_sounds_d->sound_data.sound = sfSound_create();
    sfSound_setBuffer\
    (all_sounds_d->sound_data.sound, all_sounds_d->sound_data.sound_b);
    sfMusic_setLoop(all_sounds_d->music_1, 1);
    sfSound_setVolume(all_sounds_d->sound_data.sound, 100);
    all_sounds_d->sound_data.state = 0;
}