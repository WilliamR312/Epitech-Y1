/*
** EPITECH PROJECT, 2020
** WIN_GAME
** File description:
** manage win ingame
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

void win_game(core_t *core_d)
{
    if (core_d->map_d.cursor_move.x == 200) {
        core_d->game_state = 5;
        core_d->character_data.state = 5;
    }
}