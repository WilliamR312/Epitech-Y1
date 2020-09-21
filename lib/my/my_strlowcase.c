/*
** EPITECH PROJECT, 2020
** MY_STRLOWCASE
** File description:
** switches a string to lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int sentence = 0;

    for (unsigned long i = 0; str[i]; i++) {
        if (is_alpha(str[i]) == 1 && sentence == 0) {
            sentence = 1;
            if (str[i] >= 65 && str[i] <= 90)
                str[i] = str[i] + 32;
        }
        if (is_alpha(str[i]) == 0 && sentence == 1)
            sentence = 0;
    }
    return (str);
}