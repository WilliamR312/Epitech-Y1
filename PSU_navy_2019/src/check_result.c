/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** place_boat
*/
#include "my.h"
#include "my_navy.h"

char **attack_result(int result, int *pos, char *answer, char **map)
{
    if (result == 10) {
        my_printf("%c%i: hit\n\n", answer[0], pos[1]);
        map[pos[1] - 1][pos[0] - 1] = 'x';
    } else {
        my_printf("%c%i: missed\n\n", answer[0], pos[1]);
        map[pos[1] - 1][pos[0] - 1] = 'o';
    }
    return (map);
}

static int check_result(char **map)
{
    int counter = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (map[i][j] == 'x')
                counter++;
    if (counter == 14)
        return (1);
    return (-1);
}

int check_all_result(char **map, char **map_enemy)
{
    if (check_result(map_enemy) == 1) {
        display_all_maps(map, map_enemy);
        my_putstr("I won\n");
        return (0);
    }
    if (check_result(map) == 1) {
        display_all_maps(map, map_enemy);
        my_putstr("Enemy won\n");
        return (1);
    }
    return (2);
}