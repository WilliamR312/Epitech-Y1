/*
** EPITECH PROJECT, 2020
** links_way
** File description:
** Manage the Kruskal's algorithm actions
*/
#include "include/my_gen.h"
#include "include/struct.h"

static int get_anchor(generator_t *generator)
{
    if (generator->maze[generator->y][generator->x] == 0) {
        while (generator->x != generator->info_maze.x) {
            if (generator->maze[generator->y][generator->x] != 0) {
                generator->nbr_src = \
                generator->maze[generator->y][generator->x];
                return (0);
            }
            generator->x++;
        }
        return (84);
    }
    return (0);
}

static int create_anchor(generator_t *generator)
{
    int x = rand();
    int y = rand();

    generator->x = (x % generator->info_maze.x);
    generator->y = (y % generator->info_maze.y);
    generator->nbr_src = generator->maze[generator->y][generator->x];
    if (get_anchor(generator) == 84)
        return (84);
    return (0);
}

static int end_ways(generator_t *generator)
{
    generator->nbr_src = generator->maze[0][0];

    for (int y = 0; y != generator->info_maze.y; y++) {
        for (int x = 0; x != generator->info_maze.x; x++) {
            if (y % 2 == 0 && generator->maze[y][x] != generator->nbr_src && \
            generator->maze[y][x] != 0)
                return (84);
        }
    }
    return (0);
}

int kruskal_algorithm(generator_t *generator)
{
    generator->nbr_src = 1;
    generator->nbr_to = 1;
    while (end_ways(generator) == 84) {
        while (create_anchor(generator) == 84);
        random_direction(generator);
    }
    return (0);
}