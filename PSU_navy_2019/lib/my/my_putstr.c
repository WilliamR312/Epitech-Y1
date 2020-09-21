/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr
*/
#include "../../include/my.h"

void my_putstr(char const *str)
{
    for (int c = 0;str[c] != '\0'; c++)
        write(1 , &str[c], 1);
}
