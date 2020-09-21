/*
** EPITECH PROJECT, 2020
** AI_ANALYSIS
** File description:
** handle ai analysis
*/

#include <stdlib.h>
#include "my.h"
#include "my_ms.h"
#include "struct.h"

int count_nbr_line_fill(nfo_t *game_d)
{
    int count = 0;

    for (int i = 0; i < game_d->size; i++)
        if (game_d->tab_stick[i] > 0)
            count++;
    return (count);
}