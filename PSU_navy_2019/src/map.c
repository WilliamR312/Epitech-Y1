/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** map
*/
#include "my.h"
#include "my_navy.h"

char **load_map(char *pos)
{
    char **pos_boat = NULL;
    char **map = NULL;

    pos_boat = read_pos_boat(pos);
    if (pos_boat == NULL)
        return (NULL);
    map = gen_empty_map();
    map = stock_boat_on_map(map, pos_boat);
    return (map);
}

char **get_map_p2_print_init_map(char **map)
{
    char **map_p2 = NULL;

    display_map(map);
    my_putstr("enemy's positions:\n");
    map_p2 = gen_empty_map();
    display_map(map_p2);
    return (map_p2);
}