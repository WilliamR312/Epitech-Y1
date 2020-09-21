/*
** EPITECH PROJECT, 2019
** MY_STRCMP
** File description:
** it cmps 2 strings
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);
    int same = 0;

    for (int j = 0; s1[j] != '\0' && s2[j] != '\0'; j++) {
        if (s1[j] == s2[j])
            same++;
    }
    if (same == size_s1 && size_s1 == size_s2)
        return (1);
    return (0);
}