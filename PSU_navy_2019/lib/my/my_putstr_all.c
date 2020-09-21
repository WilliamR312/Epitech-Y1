/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_putstr_all
*/
#include "../../include/my.h"

void my_putstr_all(char *str)
{
    for (int c = 0;str[c] != '\0'; c++) {
        if (str[c] >= 32 && str[c] < 127)
            my_putchar(str[c]);
        else {
            my_putchar('\\');
            base_system(str[c], "01234567");
        }
    }
}