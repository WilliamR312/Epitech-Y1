/*
** EPITECH PROJECT, 2020
** update_ways
** File description:
** update ways
*/
#include "include/my_gen.h"
#include "include/struct.h"

int way_left(generator_t *generator)
{
    generator->y -= 1;
    if (generator->maze[generator->y][generator->x] == generator->nbr_src)
        return (84);
    generator->maze[generator->y][generator->x] = generator->nbr_src;
    generator->y += 1;
    change_number_ways(generator);
    return (0);
}

int way_down(generator_t *generator)
{
    generator->x -= 1;
    if (generator->maze[generator->y][generator->x] == generator->nbr_src)
        return (84);
    generator->maze[generator->y][generator->x] = generator->nbr_src;
    generator->x += 1;
    change_number_ways(generator);
    return (0);
}

int way_right(generator_t *generator)
{
    generator->x += 1;
    if (generator->maze[generator->y][generator->x] == generator->nbr_src)
        return (84);
    generator->maze[generator->y][generator->x] = generator->nbr_src;
    generator->x -= 1;
    change_number_ways(generator);
    return (0);
}

int way_up(generator_t *generator)
{
    generator->y += 1;
    if (generator->maze[generator->y][generator->x] == generator->nbr_src)
        return (84);
    generator->maze[generator->y][generator->x] = generator->nbr_src;
    generator->y -= 1;
    change_number_ways(generator);
    return (0);
}

int update_ways(int direction, generator_t *generator)
{
    switch (direction) {
        case 0:
            if (way_up(generator) == 84)
                return (84);
            return (0);
        case 1:
            if (way_right(generator) == 84)
                return (84);
            return (0);
        case 2:
            if (way_down(generator) == 84)
                return (84);
            return (0);
        case 3:
            if (way_left(generator) == 84)
                return (84);
            return (0);
    }
    return (0);
}