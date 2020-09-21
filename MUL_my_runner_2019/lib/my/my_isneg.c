/*
** EPITECH PROJECT, 2019
** MY_ISNEG
** File description:
** Returns N if nb is negative and P if it's positive.
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
}