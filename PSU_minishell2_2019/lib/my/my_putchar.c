/*
** EPITECH PROJECT, 2020
** MY_PUTCHAR
** File description:
** Displays a char passed as parameter.
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}