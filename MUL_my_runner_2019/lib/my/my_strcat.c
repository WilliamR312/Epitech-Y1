/*
** EPITECH PROJECT, 2019
** MY_STRCAT
** File description:
** concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_size = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[dest_size + i] = src[i];
    dest[dest_size + i] = '\0';
    return (dest);
}