/*
** EPITECH PROJECT, 2020
** AI_ACTION_REGULAR_G
** File description:
** handle ai regular turn
*/

#include <stdlib.h>
#include "my.h"
#include "my_ms.h"
#include "struct.h"

static int random_number(int range)
{
    int number = 0;

    number = random() % range + 1;
    if (number == 0)
        return (1);
    return (number);
}

void ai_action_regular_g(nfo_t *game_d)
{
    int line = 0;
    int match = 0;

    do {
        line = random_number(game_d->size);
    } while (line == 0 || line > game_d->size \
    || game_d->tab_stick[line - 1] == 0);
    do {
        match = random_number(game_d->max_take);
    } while (game_d->tab_stick[line - 1] - match < 0);
    game_d->ai_choice.line = line;
    game_d->ai_choice.match = match;
    game_d->tab_stick[line - 1] = game_d->tab_stick[line - 1] - match;
    game_d->total_stick = game_d->total_stick - match;
}