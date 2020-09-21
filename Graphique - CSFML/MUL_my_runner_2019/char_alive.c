/*
** EPITECH PROJECT, 2020
** CHAR_MANAGEMENT
** File description:
** manage character
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void run_animation(char_t *char_d)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(char_d->clock_anim);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.08) {
        char_d->character.rect.left = char_d->character.rect.left + 92;
        if (char_d->character.rect.left > 660)
            char_d->character.rect.left = 0;
        sfSprite_setTextureRect(char_d->character.sprite,\
        char_d->character.rect);
        sfClock_restart(char_d->clock_anim);
    }
}

static void char_fly(float seconds, char_t *char_d, all_sounds_t *all_sounds_d)
{
    if (seconds < 0.5) {
        sfSprite_move(char_d->character.sprite,\
        (sfVector2f){0, -0.60 + char_d->attenuation});
        char_d->attenuation = char_d->attenuation + 0.001;
    }
    else {
        char_d->land_level.y = 1000;
        char_d->state = 3;
        sfClock_destroy(char_d->clock_jump);
    }
}

static void char_land(char_t *char_d, all_sounds_t *all_sounds_d)
{
    if (char_d->character.position.y > char_d->land_level.y) {
        sfSprite_setPosition(char_d->character.sprite, char_d->land_level);
        sfSound_stop(all_sounds_d->sound_data.sound);
        char_d->state = 1;
        char_d->attenuation = 0;
    }
}

static void jump_animation(char_t *char_d, all_sounds_t *all_sounds_d)
{
    sfTime time;
    float seconds;

    char_d->character.position = sfSprite_getPosition\
    (char_d->character.sprite);
    time = sfClock_getElapsedTime(char_d->clock_jump);
    seconds = time.microseconds / 1000000.0;
    char_d->character.rect.left = 368;
    sfSprite_setTextureRect(char_d->character.sprite,\
    char_d->character.rect);
    char_fly(seconds, char_d, all_sounds_d);
}

static void fall_animation(char_t *char_d, all_sounds_t *all_sounds_d)
{
    char_d->character.position = sfSprite_getPosition\
    (char_d->character.sprite);
    if (all_sounds_d->sound_data.state == 1) {
        sfSound_play(all_sounds_d->sound_data.sound);
        all_sounds_d->sound_data.state = 0;
        char_d->attenuation = 0;
    }
    sfSprite_move(char_d->character.sprite,\
    (sfVector2f){0, 0.05 + char_d->attenuation});
    char_d->attenuation = char_d->attenuation + 0.002;
    char_land(char_d, all_sounds_d);
}

void character_alive(core_t *core_d)
{
    sfRenderWindow_drawSprite(core_d->window_p.window,\
    core_d->character_data.character.sprite, NULL);
    if (core_d->character_data.state == 1)
        run_animation(&core_d->character_data);
    if (core_d->character_data.state == 2)
        jump_animation(&core_d->character_data, &core_d->all_sounds_d);
    if (core_d->character_data.state == 3)
        fall_animation(&core_d->character_data, &core_d->all_sounds_d);
}