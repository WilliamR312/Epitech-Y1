/*
** EPITECH PROJECT, 2020
** MY_STRCAPITALIZE
** File description:
** Converts your string to capitalism
*/

#include "my.h"

static int is_alpha(char str)
{
    if ((str >= 65 && str <= 90) || (str >= 97 && str <= 122))
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int phrase = 0;

    for (unsigned long i = 0; str[i]; i++) {
        if (is_alpha(str[i]) == 1 && phrase == 0) {
            phrase = 1;
            if (str[i] >= 97 && str[i] <= 122)
                str[i] = str[i] - 32;
        }
        if (is_alpha(str[i]) == 0 && phrase == 1)
            phrase = 0;
    }
    return (str);
}