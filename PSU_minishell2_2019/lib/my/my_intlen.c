/*
** EPITECH PROJECT, 2020
** MY_INTLEN
** File description:
** returns the length of an int
*/

int my_intlen(int nb)
{
    int lenght = 0;

    while (nb != 0) {
        nb = nb / 10;
        lenght++;
    }
    return (lenght);
}