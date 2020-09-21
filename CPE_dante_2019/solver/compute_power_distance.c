/*
** EPITECH PROJECT, 2020
** COMPUTE_POWER_DISTANCE
** File description:
** compute power distance from f = g + h
*/

#include "my_solv.h"
#include "struct.h"

int compute_distance(int xa, int ya, int xb, int yb)
{
    int one = (xb - xa);
    int two = (yb - ya);
    int result = 0;

    if (one < 0)
        one *= -1;
    if (two < 0)
        two *= -1;
    result = one + two;
    return (result);
}

void compute_power_distance(solver_t *solver)
{
    solver->open->prev->g = solver->act_node->g + 1;
    solver->open->prev->h = compute_distance(solver->open->prev->x, \
        solver->open->prev->y, solver->info_maze.size_x - 1, \
        solver->info_maze.size_y - 1);
    solver->open->prev->f = solver->open->prev->g + solver->open->prev->h;
}