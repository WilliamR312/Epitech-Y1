/*
** EPITECH PROJECT, 2020
** solver
** File description:
** solver
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_solv.h"
#include "struct.h"

static void init_first(solver_t *solver)
{
    solver->nb_closed = 0;
    solver->nb_open = 1;
    solver->open = NULL;
    solver->open = malloc(sizeof(clist_t));
    solver->open->x = 0;
    solver->open->y = 0;
    solver->open->h = compute_distance(solver->open->x, solver->open->y, \
        solver->info_maze.size_x, solver->info_maze.size_y);
    solver->open->g = 0;
    solver->open->f = solver->open->g + solver->open->h;
    solver->open->next =  solver->open;
    solver->open->prev =  solver->open;
    solver->open->parent = NULL;
    solver->act_node = solver->open;
}

static void free_closed_list(solver_t *solver)
{
    clist_t *index = solver->closed;

    clist_t *prev = index;
    for (int i = 0; i < solver->nb_closed; i++) {
        if (i != 0)
            free(prev);
        prev = index;
        index = index->next;
    }
    free(prev);
}

static void free_open_list(solver_t *solver)
{
    clist_t *index = solver->open;
    clist_t *prev = index;

    index = solver->open;
    prev = index;
    for (int i = 0; i < solver->nb_open; i++) {
        if (i != 0)
            free(prev);
        prev = index;
        index = index->next;
    }
    free(prev);
}

static void print_map(solver_t *solver)
{
    clist_t *index = solver->act_node;

    for (int i = 0; index->x != 0 || index->y != 0; \
    i++, index = index->parent) {
        solver->maze[index->y][index->x] = 'o';
    }
    solver->maze[index->y][index->x] = 'o';
    for (int i = 0; i < solver->info_maze.size_y; i++) {
        for (int j = 0; j < solver->info_maze.size_x; j++) {
            printf("%c", solver->maze[i][j]);
        }
        if (i  + 1!= solver->info_maze.size_y)
            puts("");
    }
}

void astar(solver_t *solver)
{
    init_first(solver);
    for (int i = 0; ((solver->act_node->x != solver->info_maze.size_x - 1 || \
    solver->act_node->y != solver->info_maze.size_y - 1) && \
    solver->nb_open != 0); i++) {
        create_node(solver);
        if (solver->nb_open != 0)
            find_best_node(solver);
    }
    if (solver->act_node->x == solver->info_maze.size_x - 1 || \
    solver->act_node->y == solver->info_maze.size_y - 1)
        print_map(solver);
    else
        printf("no solution found");
    if (solver->nb_open > 0)
        free_open_list(solver);
    if (solver->nb_closed > 0)
        free_closed_list(solver);
}