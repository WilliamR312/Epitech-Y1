/*
** EPITECH PROJECT, 2020
** my_realloc
** File description:
** my_realloc
*/
#include "../../include/my.h"

char **my_realloc_double(char **str, int difference)
{
    char **new = NULL;
    int lng = 0;

    for (;str[lng] != NULL; lng++);
    new = malloc(sizeof(char *)* (lng+1+difference));
    for (int x = 0, y = 0; str[x] != NULL; x++) {
        for (; str[x][y] != '\0'; y++);
        new[x] = malloc(sizeof(char)* (y+1));
        for (int w = 0, z = 0; str[x][z] != '\0'; z++, w++)
            new[x][w] = str[x][z];
        new[x][y] = '\0';
        y = 0;
    }
    for (int i = 0; str[i] != NULL;i++)
        free (str[i]);
    free (str);
    new[lng] = NULL;
    return (new);
}