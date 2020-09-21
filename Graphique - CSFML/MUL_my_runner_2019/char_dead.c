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

static void dead_animation(char_t *char_d, int *game_state)
{
    sfTime time;
    float seconds;

    char_d->dead_char.position = sfSprite_getPosition(char_d->character.sprite);
    char_d->dead_char.position.y = char_d->dead_char.position.y + 5;
    sfSprite_setPosition(char_d->dead_char.sprite, char_d->dead_char.position);
    time = sfClock_getElapsedTime(char_d->clock_anim);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.08) {
        char_d->dead_char.rect.left = char_d->dead_char.rect.left + 150;
        if (char_d->dead_char.rect.left > 600) {
            char_d->dead_char.rect.left = 600;
            *game_state = 2;
        }
        sfSprite_setTextureRect(char_d->dead_char.sprite,\
        char_d->dead_char.rect);
        sfClock_restart(char_d->clock_anim);
    }
}

void character_dead(core_t *core_d)
{
    dead_animation(&core_d->character_data, &core_d->game_state);
    sfRenderWindow_drawSprite(core_d->window_p.window,\
    core_d->character_data.dead_char.sprite, NULL);
}