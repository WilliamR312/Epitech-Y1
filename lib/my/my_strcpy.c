/*
** EPITECH PROJECT, 2020
** MY_STRCPY
** File description:
** copies a string into another one provided as a parameter
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int src_size = my_strlen(src);

    for (int i = 0; src[i] != '\0' && i < src_size; i++)
        dest[i] = src[i];
    return (dest);
}