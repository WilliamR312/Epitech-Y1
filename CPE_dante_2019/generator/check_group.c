/*
** EPITECH PROJECT, 2020
** check_group
** File description:
** Check group number of after the walls
*/
#include "include/my_gen.h"
#include "include/struct.h"

void change_number_ways(generator_t *generator)
{
    for (int y = 0; y != generator->info_maze.y; y++) {
        for (int x = 0; x != generator->info_maze.x; x++) {
            if (generator->maze[y][x] == generator->nbr_to)
                generator->maze[y][x] = generator->nbr_src;
        }
    }
}

int check_group(int direction, generator_t *generator)
{
    generator->nbr_to = generator->maze[generator->y][generator->x];
    if (generator->nbr_to != generator->nbr_src && generator->nbr_to != 0) {
        if (update_ways(direction, generator) == 84)
            return (84);
    } else {
        return (84);
    }
    return (0);
}