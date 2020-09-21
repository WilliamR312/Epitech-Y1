/*
** EPITECH PROJECT, 2020
** open_element
** File description:
** open a new element
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_solv.h"
#include "struct.h"

static void create_element(int x, int y, solver_t *solver)
{
    clist_t *element = NULL;

    element = malloc(sizeof(clist_t));
    element->parent = solver->act_node;
    element->x = x;
    element->y = y;
    if (solver->nb_open == 0) {
        solver->open = element;
        element->next = element;
        element->prev = element;
    } else {
        element->next = solver->open;
        element->prev = solver->open->prev;
        solver->open->prev->next = element;
        solver->open->prev = element;
    }
    solver->nb_open += 1;
}

void add_to_list(solver_t *solver, int x, int y)
{
    create_element(x, y, solver);
    compute_power_distance(solver);
}