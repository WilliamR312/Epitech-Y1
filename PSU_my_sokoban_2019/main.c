/*
** EPITECH PROJECT, 2019
** MAIN_H
** File description:
** Main of my sokoban
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/my_sokoban.h"
#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int nb_args, char **args)
{
    char **map_2d;
    map_data_t map_d;

    map_d.game_state = 0;
    while (map_d.game_state == 0) {
        map_d.over = 0;
        check_args(nb_args, args);
        map_2d = map_to_mem_management(args[1], &map_d);
        game_loop_core(&map_d, map_2d);
        free_2d_tab(map_d.rows, map_2d);
        check_game_state(map_d);
    }
    return (0);
}