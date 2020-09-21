/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_put_array
*/
#include "../../include/my.h"

void my_put_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}