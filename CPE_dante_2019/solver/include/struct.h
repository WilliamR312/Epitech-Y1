/*
** EPITECH PROJECT, 2019
** MY_STRUCT
** File description:
** all prototypes used by my solver
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

#include <stdbool.h>

typedef struct info_maze_s {
    int size_x;
    int size_y;
}info_maze_t;

typedef struct list_s clist_t;

typedef struct list_s {
    int f;
    int g;
    int h;
    int x;
    int y;
    clist_t *prev;
    clist_t *next;
    clist_t *parent;
}clist_t;

typedef struct solver_s {
    info_maze_t info_maze;
    char **maze;
    bool **cmaze;
    int min_power;
    clist_t *act_node;
    int nb_open;
    clist_t *open;
    int nb_closed;
    clist_t *closed;
}solver_t;

#endif /* !MY_H_ */