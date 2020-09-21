/*
** EPITECH PROJECT, 2019
** TOOL_BOX_H
** File description:
** many functions used by my_sokoban
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"
#include <ncurses.h>

void check_game_state(map_data_t map_d)
{
    if (map_d.game_state != 0) {
        clear();
        endwin();
        if (map_d.game_state == 2)
            exit (84);
        else
            exit (0);
    }
}

int free_2d_tab(int size, char **tab)
{
    for (int i = 0; i < size; i++)
        free(tab[i]);
    free(tab);
}

static void display_help()
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map, containing '#' \
    for walls,\n");
    my_putstr("         'P' for the player, 'X' for boxes and 'O' for storage\
     locations.\n");
}

void check_args(int nb_args, char **args)
{
    if (nb_args != 2)
        exit(84);
    if (args[1][0] == '-' && args[1][1] == 'h' && args[1][2] == '\0') {
        display_help();
        exit(0);
    }
    else if (args[1][0] == '-' && args[1][1] == 'h' && args[1][2] != '\0')
        exit (84);
}