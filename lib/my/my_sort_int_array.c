/*
** EPITECH PROJECT, 2020
** MY_SORT_INT_ARRAY
** File description:
** Sorts an array of ints in increasing order.
*/

#include "my.h"

void my_sort_int_array(int *src, int size)
{
    for (int i = size; i != 0; i--) {
        my_put_nbr(src[i - 1]);
        my_putchar('\n');
    }
}