/*
** EPITECH PROJECT, 2020
** SHOW_STRING_ARRAY
** File description:
** show string array
*/

#include <stddef.h>
#include "my.h"

int my_show_str_array(char *const *array)
{
    for (int j = 0; array[j] != NULL; j++) {
        my_putstr(array[j]);
        my_putchar('\n');
    }
    return (0);
}