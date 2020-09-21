/*
** EPITECH PROJECT, 2020
** wanted_group
** File description:
** wanted_group
*/
#include "include/my_gen.h"
#include "include/struct.h"

int check_group_same_number(int direction, generator_t *generator)
{
    generator->nbr_to = generator->maze[generator->y][generator->x];
    if (generator->nbr_to == generator->nbr_src) {
        if (direction == 0)
            generator->maze[generator->y+1][generator->x] = generator->nbr_src;
        else if (direction == 1)
            generator->maze[generator->y][generator->x+1] = generator->nbr_src;
        if (direction == 2)
            generator->maze[generator->y][generator->x-1] = generator->nbr_src;
        else if (direction == 3)
            generator->maze[generator->y-1][generator->x] = generator->nbr_src;
        return (0);
    } else
        return (84);
}