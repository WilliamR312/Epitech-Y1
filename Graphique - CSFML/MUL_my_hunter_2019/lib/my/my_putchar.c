/*
** EPITECH PROJECT, 2019
** MY_PUTCHAR
** File description:
** Displays a char passed as parameter.
*/

#include "../../include/my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}