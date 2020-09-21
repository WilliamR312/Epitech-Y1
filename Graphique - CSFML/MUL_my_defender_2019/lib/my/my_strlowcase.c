/*
** EPITECH PROJECT, 2019
** MY_STRLOWCASE
** File description:
** switches a string to lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int phrase = 0;

    for (unsigned long i = 0; str[i]; i++) {
        if (is_alpha(str[i]) == 1 && phrase == 0) {
            phrase = 1;
            if (str[i] >= 65 && str[i] <= 90)
                str[i] = str[i] + 32;
        }
        if (is_alpha(str[i]) == 0 && phrase == 1)
            phrase = 0;
    }
    return (str);
}