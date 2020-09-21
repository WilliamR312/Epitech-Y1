/*
** EPITECH PROJECT, 2020
** P_TURN_ASK_LINE
** File description:
** handle ask line player
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my_ms.h"
#include "struct.h"

static void input_handle(nfo_t *game_d, char *answer, int size)
{
    if (my_str_isnum(answer) == 0 || size == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        game_d->player_choice.line = 0;
    }
    else if (game_d->player_choice.line <= 0 || \
    game_d->player_choice.line > game_d->size || \
    game_d->tab_stick[game_d->player_choice.line - 1] == 0) {
        my_putstr("Error: this line is out of range\n");
        game_d->player_choice.line = 0;
    }
}

int ask_line(nfo_t *game_d)
{
    size_t size_answer = 0;
    char *answer = NULL;
    int size = 0;

    do {
        game_d->player_choice.line = 0;
        my_putstr("Line: ");
        if (getline(&answer, &size_answer, stdin) == EOF)
            return (42);
        for (size = 0; answer[size] != '\n'; size++);
        if (answer[size] == '\n')
            answer[size] = '\0';
        if (answer[0] != '\0' && my_str_isnum(answer) == 1) {
            game_d->player_choice.line = my_getnbr(answer);
        }
        input_handle(game_d, answer, size);
    } while (game_d->player_choice.line <= 0);
    free(answer);
    return (0);
}