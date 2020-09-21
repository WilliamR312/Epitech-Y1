/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_putchar but for number
*/
#include <stdlib.h>
#include "../../include/my.h"

static void except(int nb)
{
    if (nb == 0)
        write(1, "0", 1);
}

void my_put_nbr(int nb)
{
    int temp = 0;
    int i = 0;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    char *result = malloc(sizeof(int)* nb + 1);
    except(nb);
    for (;nb > 0;i++) {
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
