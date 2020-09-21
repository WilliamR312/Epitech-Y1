/*
** EPITECH PROJECT, 2020
** RESTART_GAME
** File description:
** restart the game with key SPACE
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

void restart_key_game(core_t *core_d, sfKeyEvent key)
{
    if (key.code == sfKeySpace) {
        core_d->map_d.cursor.x = 0;
        core_d->map_d.cursor_move.x = 0;
        map_display(core_d);
        core_d->game_state = 1;
        core_d->character_data.state = 1;
        core_d->character_data.ground = 0;
        core_d->score_d.score_int = 0;
        core_d->character_data.land_level.y = 700 - 118 - 1;
        sfSprite_setPosition(core_d->character_data.character.sprite,\
        core_d->character_data.land_level);
        core_d->character_data.dead_char.rect.left = 0;
        sfSprite_setTextureRect(core_d->character_data.dead_char.sprite,\
        core_d->character_data.dead_char.rect);
        sfMusic_stop(core_d->all_sounds_d.music_1);
        sfMusic_play(core_d->all_sounds_d.music_1);
        core_d->character_data.clock_jump = sfClock_create();
    }
}