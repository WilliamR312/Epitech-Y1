/*
** EPITECH PROJECT, 2020
** random_direction_imperfect
** File description:
** random imperfect
*/
#include "include/my_gen.h"
#include "include/struct.h"

int choose_direction4_imperfect(int direction, generator_t *generator)
{
    switch (direction)
    {
    case 3:
        generator->y += 2;
        if (generator->y >= generator->info_maze.y) {
            generator->y -= 2;
            return (84);
        }
        if (check_group_same_number(direction, generator) == 84)
            return (84);
        else
            return (0);
    default:
        return (0);
    }
}

int choose_direction3_imperfect(int direction, generator_t *generator)
{
    switch (direction)
    {
    case 2:
        generator->x += 2;
        if (generator->x >= generator->info_maze.x) {
            generator->x -= 2;
            return (84);
        }
        if (check_group_same_number(direction, generator) == 84)
            return (84);
        else
            return (0);
    default:
        if (choose_direction4_imperfect(direction, generator) == 84)
            return (84);
        else
            return (0);
    }
}

int choose_direction2_imperfect(int direction, generator_t *generator)
{
    switch (direction)
    {
        case 1:
        generator->x -= 2;
        if (generator->x < 0) {
            generator->x += 2;
            return (84);
        }
        if (check_group_same_number(direction, generator) == 84)
            return (84);
        else
            return (0);
    default:
        if (choose_direction3_imperfect(direction, generator) == 84)
            return (84);
        else
            return (0);
    }
}

int choose_direction_imperfect(int direction, generator_t *generator)
{
    switch (direction)
    {
    case 0:
        generator->y -= 2;
        if (generator->y < 0) {
            generator->y += 2;
            return (84);
        }
        if (check_group_same_number(direction, generator) == 84)
            return (84);
        else
            return (0);
    default:
        if (choose_direction2_imperfect(direction, generator) == 84)
            return (84);
        else
            return (0);
    }
}

int random_direction_imperfect(generator_t *generator)
{
    int random = rand();
    int direction = random % 4;

    if (choose_direction_imperfect(direction, generator) == 84)
        return (84);
    return (0);
}
