/*
** EPITECH PROJECT, 2020
** MY_STRCAT
** File description:
** concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int count_src = 0;
    int cursor_dest = 0;

    for (int i = 0; src[i]; i++)
        count_src++;
    while (dest[cursor_dest])
        cursor_dest++;
    for (int i = 0; i <= count_src; i++) {
        dest[cursor_dest] = src[i];
        cursor_dest++;
    }
    return (dest);
}