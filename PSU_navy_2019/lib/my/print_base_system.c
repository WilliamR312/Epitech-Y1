/*
** EPITECH PROJECT, 2020
** 1-Lib-
** File description:
** base_system
*/
#include "../../include/my.h"

int base_system(unsigned int nb, char *base)
{
    int u = my_strlen(base);
    if (nb >= u) {
        base_system(nb/u , base);
        my_putchar(base[nb%u]);
    } else
        my_putchar(base[nb]);
}