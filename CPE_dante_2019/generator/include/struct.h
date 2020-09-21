/*
** EPITECH PROJECT, 2019
** MY_STRUCT
** File description:
** all prototypes used by my gen
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct info_maze_s {
    int x;
    int y;
    int group_min;
    int group_max;
    int last_group;
}info_maze_t;

typedef struct generator_s {
    info_maze_t info_maze;
    int **maze;
    int perfect;
    int x;
    int y;
    int nbr_src;
    int nbr_to;

}generator_t;

#endif /* !MY_H_ */