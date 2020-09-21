/*
** EPITECH PROJECT, 2020
** create_dir_node
** File description:
** create a directional node
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_solv.h"
#include "struct.h"

static bool is_possible(solver_t solver, int x, int y)
{
    if (x < solver.info_maze.size_x && y < solver.info_maze.size_y && \
    x >= 0 && y >= 0 && solver.maze[y][x] != 'X' && solver.cmaze[y][x] == false)
        return (true);
    return (false);
}

static void update_open(solver_t *solver, clist_t *open)
{
    if (open->g > solver->act_node->g) {
        open->parent = solver->act_node;
        open->g = solver->act_node->g + 1;
        open->f = open->g + open->h;
    }
}

static bool is_open(solver_t *solver, int x, int y)
{
    clist_t *index = solver->open;

    for (int i = 0; i < solver->nb_open; i++, index = index->next) {
        if (index->x == x && index->y == y) {
            update_open(solver, index);
            return (true);
        }
    }
    return (false);
}

void direction_horizontal(solver_t *solver, int x, int y)
{
    bool check = 0;

    if (is_possible(*solver, x + 1, y) == 1) {
        check = is_open(solver, x + 1, y);
        if (check == 0)
            add_to_list(solver, x + 1, y);
    }
    if (is_possible(*solver, x - 1, y) == 1) {
        check = is_open(solver, x - 1, y);
        if (check == 0)
            add_to_list(solver, x - 1, y);
    }
}

void direction_vertical(solver_t *solver, int x, int y)
{
    bool check = 0;

    if (is_possible(*solver, x, y + 1) == 1) {
        check = is_open(solver, x, y + 1);
        if (check == 0)
            add_to_list(solver, x, y + 1);
    }
    if (is_possible(*solver, x, y - 1) == 1) {
        check = is_open(solver, x, y - 1);
        if (check == 0)
            add_to_list(solver, x, y - 1);
    }
}