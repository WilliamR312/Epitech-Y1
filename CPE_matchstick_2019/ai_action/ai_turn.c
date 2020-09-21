/*
** EPITECH PROJECT, 2020
** AI_TURN
** File description:
** handle ai turn
*/

#include <stdlib.h>
#include "my.h"
#include "my_ms.h"
#include "struct.h"

void ai_turn(nfo_t *game_d)
{
    game_d->turn_state = 0;
    my_putstr("\nAI's turn...\n");
    if (count_nbr_line_fill(game_d) > 2)
        ai_action_regular_g(game_d);
    else
        ai_action_end_g(game_d);
    my_putstr("AI removed ");
    my_put_nbr(game_d->ai_choice.match);
    my_putstr(" match(es) from line ");
    my_put_nbr(game_d->ai_choice.line);
    my_putchar('\n');
}