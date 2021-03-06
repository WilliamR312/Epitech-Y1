/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_str_to_word_array
*/
#include "../../include/my.h"

char **my_str_to_word_array(char *str, char separate)
{
    char **str_result = NULL;
    int nbr_seperation = 0;
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == separate)
            nbr_seperation++;
    str_result = malloc(sizeof(char *)*(nbr_seperation+2));
    for (int pos = 0, x = 0; str[pos] != '\0'; x++, y++) {
        for (; str[y] != '\0' && str[y] != separate; y++);
        str_result[x] = malloc(sizeof(char) * (y-pos));
        for (int j = 0; pos != y; pos++, j++) {
            str_result[x][j] = str[pos];
        }
        pos = pos + 1;
    }
    str_result[nbr_seperation+1] = NULL;
    return (str_result);
}