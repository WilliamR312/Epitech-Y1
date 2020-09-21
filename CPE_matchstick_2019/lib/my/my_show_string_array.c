/*
** EPITECH PROJECT, 2020
** SHOW_STRING_ARRAY
** File description:
** show_string_array
*/

#include <stdlib.h>
#include "my.h"

int my_show_str_array(char *const *array)
{
    for (int j = 0; array[j] != 0; j++) {
        for (int i = 0; array[j][i]; i++)
            my_putchar(array[j][i]);
        my_putchar('\n');
    }
    return (0);
}