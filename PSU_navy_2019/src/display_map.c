/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** display_map
*/
#include "my.h"
#include "my_navy.h"

void display_map(char **map)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; map[i] != NULL; i++) {
        my_put_nbr(i + 1);
        write(1, "|", 1);
        for (int j = 0; map[i][j]; j++) {
            write(1, &map[i][j], 1);
            if (map[i][j+1] != '\0')
                write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}

void display_all_maps(char **map, char **map_enemy)
{
    my_putstr("my positions:\n");
    display_map(map);
    my_putstr("enemy's positions:\n");
    display_map(map_enemy);
}