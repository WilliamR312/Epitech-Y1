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

static void two_lines_case_two_inmatch_action(nfo_t *game_d, int line)
{
    int match = game_d->tab_stick[line] - 2;

    game_d->tab_stick[line] = game_d->tab_stick[line] - match;
    game_d->total_stick = game_d->total_stick - match;
    game_d->ai_choice.match = match;
    game_d->ai_choice.line = line + 1;
}

static int two_lines_case_two_inmatch(nfo_t *game_d, int one, int two)
{
    if ((game_d->tab_stick[one] <= game_d->max_take && game_d->tab_stick[two] \
    <= game_d->max_take) && (game_d->tab_stick[one] >= 3 || \
    game_d->tab_stick[two] >= 3)) {
        if (game_d->tab_stick[one] >= 3)
            two_lines_case_two_inmatch_action(game_d, one);
        else
            two_lines_case_two_inmatch_action(game_d, two);
        return (1);
    }
    return (0);
}

static int two_lines_all_cases(nfo_t *game_d, int one, int two)
{
    if ((two_lines_case_one_and_other(game_d, one, two)) == 1)
        return (1);
    if (two_lines_case_two_inmatch(game_d, one, two) == 1)
        return (1);
    return (0);
}

void two_lines_core(nfo_t *game_d, int one, int two)
{
    if (two_lines_all_cases(game_d, one, two) == 0)
        ai_action_regular_g(game_d);
}