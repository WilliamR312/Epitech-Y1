/*
** EPITECH PROJECT, 2020
** AI_ACTION_END_G
** File description:
** handle ai turn when game turn to end
*/

#include <stdlib.h>
#include "my.h"
#include "my_ms.h"
#include "struct.h"

static int one_lines(nfo_t *game_d, int one)
{
    int match = 0;

    if (game_d->tab_stick[one] <= game_d->max_take && \
    game_d->tab_stick[one] > 1) {
        match = game_d->tab_stick[one] - 1;
        game_d->tab_stick[one] = game_d->tab_stick[one] - match;
        game_d->total_stick = game_d->total_stick - match;
        game_d->ai_choice.line = one + 1;
        game_d->ai_choice.match = match;
        return (1);
    }
    else
        ai_action_regular_g(game_d);
    return (0);
}

void ai_action_end_g(nfo_t *game_d)
{
    int filled_lines = count_nbr_line_fill(game_d);
    int one = -1;
    int two = -1;

    for (int i = 0, counter = 0; counter != filled_lines; i++) {
        if (game_d->tab_stick[i] > 0 && one == -1) {
            one = i;
            counter++;
        }
        else if (game_d->tab_stick[i] > 0 && two == -1) {
            two = i;
            counter++;
        }
    }
    if (filled_lines == 1)
        one_lines(game_d, one);
    else if (filled_lines == 2)
        two_lines_core(game_d, one, two);
}