/*
** EPITECH PROJECT, 2020
** imperfect
** File description:
** Generate a labyrinth imperfect
*/
#include "include/my_gen.h"
#include "include/struct.h"

int suit_break_wall(generator_t *generator)
{
    if ((generator->x - 1) < 0)
        return (84);
    if (generator->maze[generator->y][generator->x - 1] == 0) {
        if ((generator->x - 2) < 0)
            return (84);
        if (generator->maze[generator->y][generator->x - 2] != 0)
            return (0);
    }
    if ((generator->y - 1) < 0)
        return (84);
    if (generator->maze[generator->y - 1][generator->x] == 0) {
        if ((generator->y - 2) < 0)
            return (84);
        if (generator->maze[generator->y][generator->x - 2] != 0)
            return (0);
    }
    return (84);
}

int break_wall(generator_t *generator)
{
    if ((generator->x + 1) >= generator->info_maze.x)
        return (84);
    if (generator->maze[generator->y][generator->x + 1] == 0) {
        if ((generator->x + 2) >= generator->info_maze.x)
            return (84);
        if (generator->maze[generator->y][generator->x + 2] != 0)
            return (0);
    }
    if ((generator->y + 1) >= generator->info_maze.y)
        return (84);
    if (generator->maze[generator->y + 1][generator->x] == 0) {
        if ((generator->y + 2) >= generator->info_maze.y)
            return (84);
        if (generator->maze[generator->y + 2][generator->x] != 0)
            return (0);
    }
    if (suit_break_wall(generator) == 84)
        return (84);
    else
        return (0);
}

int check_link_imperfect(generator_t *generator)
{
    if (generator->maze[generator->y][generator->x] == 0) {
        while (generator->x != generator->info_maze.x) {
            if (generator->maze[generator->y][generator->x] != 0 && \
            break_wall(generator) == 0) {
                generator->nbr_src = \
                generator->maze[generator->y][generator->x];
                return (0);
            }
            generator->x++;
        }
        return (84);
    }
    if (generator->maze[generator->y][generator->x] != 0 && \
    break_wall(generator) == 0)
        return (0);
    return (84);
}

int create_way_imperfect(generator_t *generator)
{
    int x = rand();
    int y = rand();

    generator->x = (x % generator->info_maze.x);
    generator->y = (y % generator->info_maze.y);
    generator->nbr_src = generator->maze[generator->y][generator->x];
    if (check_link_imperfect(generator) == 84)
        return (84);
    return (0);
}

void manage_imperfect(generator_t *generator)
{
    int fin_imperfect = 0;

    if (generator->info_maze.x >= generator->info_maze.y)
        fin_imperfect = generator->info_maze.x * 2;
    else
        fin_imperfect = generator->info_maze.y * 2;
    for (int i = 0; i != fin_imperfect; i++) {
        while (create_way_imperfect(generator) == 84);
        while (random_direction_imperfect(generator) == 84);
    }
}