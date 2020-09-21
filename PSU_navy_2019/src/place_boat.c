/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** place_boat
*/
#include "my.h"
#include "my_navy.h"

static char **change_horizontale(char **map, int *boat_int, int i)
{
    int x = 0;
    int x2 = 0;
    int y = 0;
    int temp = 0;

    y = boat_int[i] / 10;
    x = boat_int[i] % 10;
    x2 = boat_int[i+1] % 10;
    if (x > x2) {
        temp = x2;
        x2 = x;
        x = temp;
    }
    for (; x <= x2 ;x++) {
        if (map[x-1][y] != '.')
            return (NULL);
        map[x-1][y] = (i / 2) + 2 + 48;
    }
    return (map);
}

static char **change_verticale(char **map, int *boat_int, int i)
{
    int y = 0;
    int y2 = 0;
    int x = 0;
    int temp = 0;

    x = boat_int[i] % 10;
    y = boat_int[i] / 10;
    y2 = boat_int[i+1] / 10;
    if (y > y2) {
        temp = y2;
        y2 = y;
        y = temp;
    }
    for (; y <= y2 ;y++) {
        if (map[x-1][y] != '.')
            return (NULL);
        map[x-1][y] = (i / 2) + 2 + 48;
    }
    return (map);
}

static char **init_change_map(char **map, int *boat_int)
{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;

    for (int i = 0; i < 8 && map != NULL; i += 2) {
        x1 = boat_int[i]%10;
        x2 = boat_int[i+1]%10;
        y1 = boat_int[i]/10;
        y2 = boat_int[i+1]/10;
        if (y1 == y2 && x2 - x1 + 1 == i/2 + 2 || \
        y1 == y2 && x1 - x2 + 1 == i/2 + 2)
            map = change_horizontale(map, boat_int, i);
        else if (x1 == x2 && y2 - y1 + 1 == i/2 + 2 || \
        x1 == x2 && y1 - y2 + 1 == i/2 + 2)
            map = change_verticale(map, boat_int, i);
        else
            return (NULL);
    }
    return (map);
}

char **stock_boat_on_map(char **map, char **pos_boat)
{
    char **boat = NULL;
    int *boat_int = NULL;
    int x = 0;
    int y = 0;

    boat_int = malloc(sizeof(int) * 8);
    for (int i = 0, j = 0; i != 4; i++, j += 2) {
        boat = my_str_to_word_array(pos_boat[i], ':');
        if (my_getnbr(boat[0]) != i+2) {
            free(boat_int);
            return (NULL);
        }
        boat_int[0 + j] = (boat[1][0] - 65) * 10 + (boat[1][1]-48);
        boat_int[1 + j] = (boat[2][0] - 65) * 10 + (boat[2][1]-48);
        free(boat);
    }
    map = init_change_map(map, boat_int);
    free(boat_int);
    return (map);
}