/*
** EPITECH PROJECT, 2020
** close_element
** File description:
** close an element
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_solv.h"
#include "struct.h"

static void remove_from_open(solver_t *solver)
{
    if (solver->nb_open == 1) {
        solver->open = NULL;
    } else if (solver->open == solver->act_node) {
        solver->open = solver->open->next;
        solver->act_node->prev->next = solver->act_node->next;
        solver->act_node->next->prev = solver->act_node->prev;
    } else {
        solver->act_node->prev->next = solver->act_node->next;
        solver->act_node->next->prev = solver->act_node->prev;
    }
}

static void add_to_closed(solver_t *solver)
{
    if (solver->nb_closed == 0) {
        solver->closed = solver->act_node;
        solver->closed->next = solver->closed;
        solver->closed->prev = solver->closed;
    } else if (solver->nb_closed == 1) {
        solver->closed->prev = solver->act_node;
        solver->closed->next = solver->act_node;
        solver->act_node->next = solver->closed;
        solver->act_node->prev = solver->closed;
    } else {
        solver->act_node->next = solver->closed;
        solver->act_node->prev = solver->closed->prev;
        solver->closed->prev->next = solver->act_node;
        solver->closed->prev = solver->act_node;
    }
}

void close_actual(solver_t *solver)
{
    solver->cmaze[solver->act_node->y][solver->act_node->x] = true;
    remove_from_open(solver);
    solver->act_node->prev = NULL;
    solver->act_node->next = NULL;
    add_to_closed(solver);
    solver->nb_closed += 1;
    solver->nb_open -= 1;
}