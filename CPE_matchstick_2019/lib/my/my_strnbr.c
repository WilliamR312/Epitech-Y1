/*
** EPITECH PROJECT, 2019
** SHOW_NUMBER
** File description:
** Show number
*/

#include "my.h"

int show_over(int nb)
{
    int display = 0;
    int negative = 0;

    if (nb < 0) {
        nb = nb + 1;
        nb *= -1;
        my_putchar('-');
        negative = 1;
    }
    if (nb >= 10) {
        display = nb % 10;
        nb = nb / 10;
        if (negative == 1)
            display++;
        show_over(nb);
        my_putchar(display + '0');
    } else if (nb < 10)
        my_putchar(nb + '0');
    return (0);
}

int show_normal_case(int nb)
{
    int display = 0;
    int negative = 0;

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb >= 10) {
        display = nb % 10;
        nb = nb / 10;
        show_normal_case(nb);
        my_putchar(display + '0');
    } else if (nb < 10)
        my_putchar(nb + '0');
    return (0);
}

int my_strnbr(int nb)
{
    if (nb == -2147483648)
        show_over(nb);
    else
        show_normal_case(nb);
    return (0);
}