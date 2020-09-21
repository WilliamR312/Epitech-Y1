/*
** EPITECH PROJECT, 2020
** MY_STRTABLEN
** File description:
** count size of str tab
*/

#include <stddef.h>

int my_strtablen(char **array)
{
    int count = 0;

    for (count; array[count] != NULL; count++);
    return (count);
}