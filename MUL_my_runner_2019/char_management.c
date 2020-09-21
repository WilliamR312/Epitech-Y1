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

static void fall_detector(core_t *core_d)
{
    if (core_d->character_data.ground == 0 &&\
    core_d->character_data.state == 1) {
        core_d->character_data.state = 3;
        core_d->character_data.land_level.y = 1000;
    }
}

void character_management(core_t *core_d)
{
    fall_detector(core_d);
    if (core_d->character_data.state == 4)
        character_dead(core_d);
    else if (core_d->character_data.state == 5)
        character_win(core_d);
    else
        character_alive(core_d);
}