/*
** EPITECH PROJECT, 2019
** MY_GEN_PROTOTYPES
** File description:
** all prototypes used by my gen
*/

#ifndef MY_GEN_H_
#define MY_GEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "struct.h"

int str_is_num(char *src);
void generate_empty_maze(generator_t *generator);
void display_int_maze(generator_t *generator);
void display_char_maze(generator_t *generator);
int check_group(int direction, generator_t *generator);
int kruskal_algorithm(generator_t *generator);
int random_direction(generator_t *generator);
int update_ways(int direction, generator_t *generator);
void change_number_ways(generator_t *generator);
int check_group_same_number(int direction, generator_t *generator);
void manage_imperfect(generator_t *generator);
int random_direction_imperfect(generator_t *generator);
int check_link(generator_t *generator);


#endif /* !MY_H_ */