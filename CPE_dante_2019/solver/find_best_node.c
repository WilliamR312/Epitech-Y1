/*
** EPITECH PROJECT, 2020
** find_best_node
** File description:
** find the best node
*/

#include "my_solv.h"
#include "struct.h"

static void find_best_hdist_node(solver_t *solver, int count)
{
    clist_t *index = solver->open;
    int ref_pow = solver->act_node->f;
    int min_hdist = solver->act_node->h;
    int hcount = 0;
    int stop = 0;

    for (int i = 0; i < solver->nb_open && stop != count; \
    index = index->next, i++) {
        if (index->f == ref_pow) {
            if (index->h < min_hdist) {
                solver->act_node = index;
                min_hdist = index->h;
                hcount = 0;
            }
            if (index->h == min_hdist)
                hcount++;
            stop++;
        }
    }
}

void find_best_node(solver_t *solver)
{
    int min_pow = solver->min_power;
    int pow = 0;
    int count = 0;
    clist_t *index = solver->open;

    min_pow = index->f + 1;
    for (int i = 0; i < solver->nb_open; index = index->next, i++) {
        pow = index->f;
        if (pow < min_pow) {
            solver->act_node = index;
            min_pow = pow;
            count = 0;
        }
        if (pow == min_pow)
            count++;
    }
    if (count >= 2)
        find_best_hdist_node(solver, count);
}