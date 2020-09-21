/*
** EPITECH PROJECT, 2020
** AI_ACTION_TWO_LINES
** File description:
** handle ai turn
*/

#include <stdlib.h>
#include "my.h"
#include "my_ms.h"
#include "struct.h"

static int two_lines_case_one_and_inmatch(nfo_t *game_d, int one, int two)
{
    int match = 0;

    if ((game_d->tab_stick[one] == 1 && game_d->tab_stick[two] \
    <= game_d->max_take) || (game_d->tab_stick[two] == 1 && \
    game_d->tab_stick[one] <= game_d->max_take)) {
        if (game_d->tab_stick[one] == 1) {
            match = game_d->tab_stick[two];
            game_d->tab_stick[two] = game_d->tab_stick[two] - match;
            game_d->total_stick = game_d->total_stick - match;
            game_d->ai_choice.line = two + 1;
        } else {
            match = game_d->tab_stick[one];
            game_d->tab_stick[one] = game_d->tab_stick[one] - match;
            game_d->total_stick = game_d->total_stick - match;
            game_d->ai_choice.line = one + 1;
        }
        game_d->ai_choice.match = match;
        return (1);
    }
    return (0);
}

static int two_lines_case_one_and_outmatch(nfo_t *game_d, int one, int two)
{
    int match = 0;

    if ((game_d->tab_stick[one] == 1 && game_d->tab_stick[two] \
    <= game_d->max_take) || (game_d->tab_stick[two] == 1 && \
    game_d->tab_stick[one] <= game_d->max_take)) {
        if (game_d->tab_stick[one] == 1) {
            match = game_d->tab_stick[two];
            game_d->tab_stick[two] = game_d->tab_stick[two] - match;
            game_d->total_stick = game_d->total_stick - match;
            game_d->ai_choice.line = two + 1;
        } else {
            match = game_d->tab_stick[one];
            game_d->tab_stick[one] = game_d->tab_stick[one] - match;
            game_d->total_stick = game_d->total_stick - match;
            game_d->ai_choice.line = one + 1;
        }
        game_d->ai_choice.match = match;
        return (1);
    }
    return (0);
}

int two_lines_case_one_and_other(nfo_t *game_d, int one, int two)
{
    if (two_lines_case_one_and_inmatch(game_d, one, two) == 1)
        return (1);
    if (two_lines_case_one_and_outmatch(game_d, one, two) == 1)
        return (1);
    return (0);
}