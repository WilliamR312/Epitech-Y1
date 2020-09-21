/*
** EPITECH PROJECT, 2020
** create_node
** File description:
** create a node
*/

#include "my_solv.h"
#include "struct.h"

void create_node(solver_t *solver)
{
    int x = solver->act_node->x;
    int y = solver->act_node->y;

    close_actual(solver);
    direction_horizontal(solver, x, y);
    direction_vertical(solver, x, y);
}