/*
** EPITECH PROJECT, 2019
** MY_PUTSTR
** File description:
** displays the characters of a string one by one
*/

#include "my.h"
#include <stddef.h>

int my_putstr(char const *str)
{
    if (str == NULL)
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}