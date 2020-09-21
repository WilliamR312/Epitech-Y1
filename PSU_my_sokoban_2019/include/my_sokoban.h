/*
** EPITECH PROJECT, 2019
** INCLUDE_MY_SOKOBAN
** File description:
** my sokoban game includes
*/

#ifndef MY_SOKOBAN_H
#define MY_SOKOBAN_H

char **map_to_mem_management(char *pathname, map_data_t *map_d);
char **get_map_2d(map_data_t *map_d, char *map_1d, char **map_2d);
int count_line(int size, char *map_1d, map_data_t *map_d);
void game_loop_core(map_data_t *map_d, char **map_2d);
void move_player(int key, map_data_t *map_d, char **map_2d);
int free_2d_tab(int size, char **tab);
void check_args(int nb_args, char **args);
void display_help();
void over_hole(char **map, map_data_t *map_d, int y, int x);
void check_game_state(map_data_t map_d);
#endif