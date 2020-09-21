/*
** EPITECH PROJECT, 2020
** toolbox
** File description:
** toolbox
*/
#include "include/my_gen.h"
#include "include/struct.h"

int str_is_num(char *src)
{
    for (int i = 0; src[i]; i++) {
        if (src[i] < 48 && src[i] > 57)
            return (0);
    }
    return (1);
}

void display_int_maze(generator_t *generator)
{
    for (int j = 0; j < generator->info_maze.y; j++) {
        for (int i = 0; i < generator->info_maze.x; i++) {
            printf("%d ", generator->maze[j][i]);
        }
        printf("\n");
    }
}

void display_char_maze(generator_t *generator)
{
    for (int j = 0; j < generator->info_maze.y; j++) {
        for (int i = 0; i < generator->info_maze.x; i++) {
            if (generator->maze[j][i] == 0)
                printf("X");
            else
                printf("*");
        }
        if (j + 1 < generator->info_maze.y)
            printf("\n");
    }
}