/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_strcpy_double
*/
#include "../../include/my.h"

char **my_strcpy_double(char **str)
{
    char **new = NULL;
    int lng = 0;

    for (;str[lng] != NULL; lng++);
    new = malloc(sizeof(char *)* (lng+1));
    for (int x = 0, y = 0; str[x] != NULL; x++) {
        for (; str[x][y] != '\0'; y++);
        new[x] = malloc(sizeof(char)* (y+1));
        for (int w = 0, z = 0; str[x][z] != '\0'; z++, w++)
            new[x][w] = str[x][z];
        new[x][y] = '\0';
        y = 0;
    }
    new[lng+1] = NULL;
    return (new);
}