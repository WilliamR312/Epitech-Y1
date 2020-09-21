/*
** EPITECH PROJECT, 2020
** DISPLAY_MATCHSTICK
** File description:
** display matchstick
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "my_ms.h"
#include "struct.h"

static void print_limit(int max_size)
{
    for (int i = 0; i < max_size; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
}

static void print_game_content(int i, nfo_t *gm_d)
{
    int space_l = ((gm_d->max_size -2) / 2 ) - i;
    int space_r = gm_d->max_size - 2 - gm_d->tab_stick[i] - space_l;

    write(1, "*", 1);
    for (int left = 0; left < space_l; left++)
        write(1, " ", 1);
    for (int s = 0; s < gm_d->tab_stick[i]; s++)
        write(1, "|", 1);
    for (int right = 0; right < space_r; right++)
        write(1, " ", 1);
    for (int r = 0; space_r + space_l + 2 + gm_d->tab_stick[i] + r <\
    gm_d->max_size; r++)
        write(1, " ", 1);
    write(1, "*", 1);
}

void display_matchstick(nfo_t *game_d)
{
    print_limit(game_d->max_size);
    for (int i = 0; i < game_d->size; i++) {
        print_game_content(i, game_d);
        write(1, "\n", 1);
    }
    print_limit(game_d->max_size);
}