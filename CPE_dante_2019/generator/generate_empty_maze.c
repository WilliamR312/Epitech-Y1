/*
** EPITECH PROJECT, 2020
** generator
** File description:
** main for generator
*/
#include "include/my_gen.h"
#include "include/struct.h"

static void create_end(generator_t *generator)
{
    if ((generator->info_maze.x % 2) == 0) {
        generator->maze[generator->info_maze.y - 1]\
        [generator->info_maze.x - 1] = generator->info_maze.last_group;
        generator->maze[generator->info_maze.y - 1]\
        [generator->info_maze.x - 2] = generator->info_maze.last_group;
    }
    if ((generator->info_maze.y % 2) != 0)
        generator->maze[generator->info_maze.y - 1]\
        [generator->info_maze.x - 1] = generator->info_maze.last_group;
}

static void fill_normal_line(generator_t *generator, int y)
{
    for (int x = 0; x < generator->info_maze.x; x++) {
        if (((x + 1) % 2) != 0) {
            generator->maze[y][x] = generator->info_maze.last_group;
            generator->info_maze.last_group++;
        } else {
            generator->maze[y][x] = 0;
        }
    }
}

static void fill_maze(generator_t *generator)
{
    generator->maze = malloc(sizeof(int *) * generator->info_maze.y);
    for (int y = 0; y < generator->info_maze.y; y++) {
        generator->maze[y] = NULL;
        generator->maze[y] = malloc(sizeof(int) * generator->info_maze.x);
        if (((y + 1) % 2) != 0)
            fill_normal_line(generator, y);
        else
            for (int x = 0; x < generator->info_maze.x; x++)
                generator->maze[y][x] = 0;
    }
}

void generate_empty_maze(generator_t *generator)
{
    generator->info_maze.group_max = 100;
    generator->info_maze.group_min = 0;
    generator->info_maze.last_group = 1;
    fill_maze(generator);
    create_end(generator);
}