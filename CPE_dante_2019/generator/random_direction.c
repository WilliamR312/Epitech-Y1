/*
** EPITECH PROJECT, 2020
** random_direction
** File description:
** Choose a random direction for the ways
*/
#include "include/my_gen.h"
#include "include/struct.h"

static int dir_up(generator_t *generator)
{
    generator->y += 2;
    if (generator->y >= generator->info_maze.y) {
        generator->y -= 2;
        return (84);
    }
    if (check_group(3, generator) == 84)
        return (84);
    return (0);
}

static int dir_right(generator_t *generator)
{
    generator->x += 2;
    if (generator->x >= generator->info_maze.x) {
        generator->x -= 2;
        return (84);
    }
    if (check_group(2, generator) == 84)
        return (84);
    else
        return (0);
}

static int dir_left(generator_t *generator)
{
    generator->x -= 2;
    if (generator->x < 0) {
        generator->x += 2;
        return (84);
    }
    if (check_group(1, generator) == 84)
        return (84);
    return (0);
}

static int dir_down(generator_t *generator)
{
    generator->y -= 2;
    if (generator->y < 0) {
        generator->y += 2;
        return (84);
    }
    if (check_group(0, generator) == 84)
        return (84);
    return (0);
}

int random_direction(generator_t *generator)
{
    int random = rand();
    int direction = random % 4;
    int return_value = 0;

    switch (direction) {
        case 0:
            return_value = dir_up(generator);
            break;
        case 1:
            return_value = dir_right(generator);
            break;
        case 2:
            return_value = dir_down(generator);
            break;
        case 3:
            return_value = dir_left(generator);
            break;
    }
    return (return_value);
}