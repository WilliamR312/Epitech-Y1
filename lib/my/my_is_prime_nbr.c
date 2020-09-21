/*
** EPITECH PROJECT, 2020
** IS_PRIME_NUMBER
** File description:
** search if is a prime number
*/

int is_prime_number(int nb)
{
    int test = 0;

    if (nb <= 1)
        return (0);
    for (int i = 1; i < 10; i++) {
        if (nb % i == 0)
            test++;
    }
    if (nb > 9 && nb % nb == 0)
        test++;
    if (nb % nb == 0 && nb % 1 == 0 && test == 2)
        return (1);
    return (0);
}