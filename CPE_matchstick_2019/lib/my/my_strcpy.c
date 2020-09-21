/*
** EPITECH PROJECT, 2020
** MY_STRCPY
** File description:
** copies a string into another one provided as a parameter
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    for (unsigned long i = 0; dest[i]; i++)
        dest[i] = 0;
    for (unsigned long i = 0; src[i]; i++)
        dest[i] = src[i];
    return (dest);
}