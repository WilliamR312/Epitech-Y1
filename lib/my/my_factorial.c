/*
** EPITECH PROJECT, 2020
** ITERATIVE_FACTORIAL
** File description:
** iterative factorial
*/

int my_factorial(int nb)
{
    if (nb == 0)
        return (1);
    if (nb < 0 || nb > 12)
        return (0);
    for (int i = nb - 1; i > 0; i--)
        nb = nb * i;
    return (nb);
}