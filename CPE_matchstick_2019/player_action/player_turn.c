/*
** EPITECH PROJECT, 2020
** PLAYER_TURN
** File description:
** handle player turn
*/

#include <stdio.h>
#include "my.h"
#include "my_ms.h"
#include "struct.h"

static int check_p_match(nfo_t *game_d)
{
    if (game_d->player_choice.match <= \
    game_d->tab_stick[game_d->player_choice.line - 1] && \
    game_d->player_choice.match != 0)
        return (1);
    return (0);
}

int player_turn(nfo_t *game_d)
{
    game_d->turn_state = 1;
    my_putstr("\nYour turn:\n");
    do {
        if (ask_line(game_d) == 42)
            return (42);
        if (ask_match(game_d) == 42)
            return (42);
    } while (!(check_p_match(game_d)));
    game_d->tab_stick[game_d->player_choice.line - 1] = \
    game_d->tab_stick[game_d->player_choice.line - 1] -\
    game_d->player_choice.match;
    game_d->total_stick = game_d->total_stick - game_d->player_choice.match;
    my_putstr("Player removed ");
    my_put_nbr(game_d->player_choice.match);
    my_putstr(" match(es) from line ");
    my_put_nbr(game_d->player_choice.line);
    my_putchar('\n');
    return (1);
}