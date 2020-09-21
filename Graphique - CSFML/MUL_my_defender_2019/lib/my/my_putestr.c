/*
** EPITECH PROJECT, 2019
** MY_PUTSTR
** File description:
** displays the characters of a string one by one
*/

#include <unistd.h>
#include <stddef.h>
#include "my.h"

static void my_putechar(char c)
{
    write(2, &c, 1);
}

int my_putestr(char const *str)
{
    if (str == NULL)
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        my_putechar(str[i]);
    return (0);
}