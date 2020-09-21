/*
** EPITECH PROJECT, 2020
** MY_PUTSTR
** File description:
** displays the characters of a string one by one
*/

#include <stddef.h>
#include "my.h"

int my_putstr(char const *str)
{
    if (str == NULL)
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}