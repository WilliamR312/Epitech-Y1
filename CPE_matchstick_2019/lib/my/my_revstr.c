/*
** EPITECH PROJECT, 2020
** MY_REVSTR
** File description:
** reverses a string passed as parameter
*/

#include "my.h"

char *reverse_string(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char save;

    while (i < j) {
        save = str[i];
        str[i] = str[j];
        str[j] = save;
        i++;
        j--;
    }
    return (str);
}