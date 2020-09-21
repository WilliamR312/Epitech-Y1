/*
** EPITECH PROJECT, 2020
** solver
** File description:
** solver main
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_solv.h"
#include "struct.h"

static void get_bool_map(solver_t *solver)
{
    solver->cmaze = NULL;
    solver->cmaze = malloc(sizeof(bool *) * solver->info_maze.size_y);
    for (int i = 0; i < solver->info_maze.size_y; i++) {
        solver->cmaze[i] = malloc(sizeof(bool) * solver->info_maze.size_x);
        for (int j = 0; j < solver->info_maze.size_x; j++)
            solver->cmaze[i][j] = false;
    }
}

static void free_maps(solver_t *solver)
{
    for (int i = 0; solver->maze[i] != NULL; i++)
        free(solver->maze[i]);
    free(solver->maze);
    for (int i = 0; i < solver->info_maze.size_y; i++)
        free(solver->cmaze[i]);
    free(solver->cmaze);
}

static int check_base(solver_t *solver)
{
    if (solver->maze[0][0] == 'X')
        return (1);
    if (solver->maze[solver->info_maze.size_y - 1] \
    [solver->info_maze.size_x - 1] == 'X')
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    char **map = NULL;
    solver_t solver;

    if (argc != 2)
        return (84);
    map = get_map(map, argv[1], &solver);
    if (map == NULL)
        return (84);
    solver.maze = map;
    if (check_base(&solver) == 1) {
        printf("no solution found");
        return (0);
    }
    get_bool_map(&solver);
    astar(&solver);
    free_maps(&solver);
    return (0);
}