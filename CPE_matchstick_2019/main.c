/*
** EPITECH PROJECT, 2020
** MAIN
** File description:
** main for matchstick
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my.h"
#include "my_ms.h"
#include "struct.h"

static int catch_args(int nb_args, char **args, nfo_t *game_d)
{
    if (nb_args != 3 || !(my_str_isnum(args[1])) || !(my_str_isnum(args[2])))
        return (1);
    game_d->size = my_getnbr(args[1]);
    game_d->max_take = my_getnbr(args[2]);
    game_d->tab_stick = malloc(sizeof(int) * game_d->size);
    game_d->max_size = 2 * game_d->size + 1;
    if (game_d->size < 2 || game_d->size > 99 || game_d->max_take <= 0)
        return (1);
    return (0);
}

static void fill_initial_tab(nfo_t *game_d)
{
    int nb_stick = 1;

    game_d->total_stick = 0;
    for (int i = 0; i < game_d->size; i++) {
        game_d->tab_stick[i] = nb_stick;
        game_d->total_stick = game_d->total_stick + nb_stick;
        nb_stick = nb_stick + 2;
    }
}

static int turn_handle(nfo_t *game_d)
{
    int return_p = 0;

    return_p = player_turn(game_d);
    if (return_p == 42)
        return (42);
    display_matchstick(game_d);
    if (game_d->total_stick != 0) {
        ai_turn(game_d);
        display_matchstick(game_d);
    }
    return (0);
}

static int result_handle(int winner)
{
    if (winner == 1) {
        my_putstr("You lost, too bad...\n");
        return (2);
    } else {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}

int main(int nb_args, char **args)
{
    nfo_t game_d;
    int return_winner = 0;

    srandom(time(NULL));
    if (catch_args(nb_args, args, &game_d))
        return (84);
    fill_initial_tab(&game_d);
    display_matchstick(&game_d);
    while (game_d.total_stick != 0) {
        if (turn_handle(&game_d) == 42)
            return (0);
    }
    return_winner = result_handle(game_d.turn_state);
    for (int i = 0; i < game_d.size; i++)
        free(game_d.tab_stick[i]);
    free(game_d.tab_stick);
    return (return_winner);
}