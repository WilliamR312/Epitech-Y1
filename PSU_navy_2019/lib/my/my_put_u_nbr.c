/*
** EPITECH PROJECT, 2019
** my_put_u_nbr.c
** File description:
** my_putchar but for unsigned int
*/
#include <stdlib.h>
#include "../../include/my.h"

void my_put_u_nbr(unsigned nb)
{
    unsigned int temp = 0;
    int i = 0;
    char *result = malloc(sizeof(unsigned int)* nb + 1);

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    for (; nb > 0 ; i++) {
        temp = nb % 10;
        temp = temp + 48;
        nb = nb / 10;
        result[i] = temp;
    }
    result[i] = '\0';
    my_revstr(result);
    my_putstr(result);
    free(result);
}
