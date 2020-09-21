/*
** EPITECH PROJECT, 2020
** MY_STRNCMP
** File description:
** it cmps n characters from one string to another
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++) {
        count++;
        if (s1[i] > s2[i])
            return (count);
        if (s1[i] < s2[i])
            return (-count);
    }
    return (0);
}