/*
** EPITECH PROJECT, 2020
** P_TURN_ASK_MATCH
** File description:
** handle ask match player
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my_ms.h"
#include "struct.h"

static void input_handle(nfo_t *game_d, char *answer)
{
    if (my_str_isnum(answer) && answer[0] != '\0') {
        if ((game_d->player_choice.match >\
        game_d->tab_stick[game_d->player_choice.line - 1]
        && game_d->player_choice.match <= game_d->max_take) && \
        game_d->player_choice.match != 0)
            my_putstr("Error: not enough matches on this line\n");
        if (game_d->player_choice.match > game_d->max_take) {
            my_putstr("Error: you cannot remove more than ");
            my_put_nbr(game_d->max_take);
            my_putstr(" matches per turn\n");
            game_d->player_choice.match = 0;
            return;
        }
        if (game_d->player_choice.match == 0)
            my_putstr("Error: you have to remove at least one match\n");
    } else {
        my_putstr("Error: invalid input (positive number expected)\n");
        game_d->player_choice.match = 0;
    }
}

int ask_match(nfo_t *game_d)
{
    size_t size_answer = 0;
    char *answer = NULL;
    int size = 0;

    game_d->player_choice.match = 0;
    my_putstr("Matches: ");
    if (getline(&answer, &size_answer, stdin) == EOF)
        return (42);
    for (size = 0; answer[size] != '\n'; size++);
    if (answer[size] == '\n')
        answer[size] = '\0';
    if (answer[0] != '\0' && my_str_isnum(answer) == 1) {
        game_d->player_choice.match = my_getnbr(answer);
    }
    input_handle(game_d, answer);
    free(answer);
    return (0);
}