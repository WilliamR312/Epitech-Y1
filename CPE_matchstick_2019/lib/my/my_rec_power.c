/*
** EPITECH PROJECT, 2020
** MY_COMPUTE_POWER_REC
** File description:
** takes nb to the power p recursively
*/

#include "my.h"

int my_recpower(int nb, int p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    p--;
    if (p > 0)
        nb = nb * my_recpower(nb, p);
    return (nb);
}