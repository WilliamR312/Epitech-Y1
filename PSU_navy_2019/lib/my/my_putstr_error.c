/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_putstr_error
*/
#include "../../include/my.h"

void my_putstr_error(char const *str)
{
    for (int c = 0; str[c] != '\0'; c++)
        write(2, &str[c], 1);
}