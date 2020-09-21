/*
** EPITECH PROJECT, 2019
** MY_NAVY
** File description:
** my navy prototype
*/

#ifndef MY_NAVY_H_
#define MY_NAVY_H_

#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int first_player(char **av);
int second_player(char **av);
char **read_pos_boat(char *file);
char **gen_empty_map(void);
char **stock_boat_on_map(char **map, char **pos_boat);
void display_map(char **map);
char **load_map(char *pos);
char **get_map_p2_print_init_map(char **map);
int game_loop(char **map_, char **map_enemy, int pid, int player);
int wait_signal(void);
char **change_map(char **map, int pid);
char **change_enemy_map(char **map, char *answer, int pid);
void handler_p1(int sig, siginfo_t *info, void *ucontext);
int count_signal(void);
int wait_result_sig(void);
void display_all_maps(char **map, char **map_enemy);
char **attack_result(int result, int *pos, char *answer, char **map);
int check_all_result(char **map, char **map_enemy);
void free_ressources(char ***maps);

#endif /* !MY_H_ */