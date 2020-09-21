/*
** EPITECH PROJECT, 2019
** MY_STRNCPY
** File description:
** copies the n first characters for a string to another provided as parameter
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int size_src = my_strlen(src);

    if (n > size_src) {
        for (i = 0; src[i] != 0; i++) {
            dest[i] = src[i];
        }
        for (int j = i ; j < n ; j++)
            dest[i] = '\0';
    } else {
        for (i = 0; i < n; i++) {
            dest[i] = src[i];
        }
    }
    return (dest);
}