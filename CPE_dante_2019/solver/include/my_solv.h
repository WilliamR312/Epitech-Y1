/*
** EPITECH PROJECT, 2019
** MY_SOLV_PROTOTYPES
** File description:
** all prototypes used by my solv
*/

#ifndef MY_SOLV_H_
#define MY_SOLV_H_

#include "struct.h"

void astar(solver_t *solver);
void compute_power_distance(solver_t *solver);
int compute_distance(int xa, int ya, int xb, int yb);
void find_best_node(solver_t *solver);
void add_to_list(solver_t *solver, int x, int y);
void close_actual(solver_t *solver);
void create_node(solver_t *solver);
void direction_vertical(solver_t *solver, int x, int y);
void direction_horizontal(solver_t *solver, int x, int y);
char **get_map(char **map, char *path, solver_t *solver);

#endif /* !MY_H_ */