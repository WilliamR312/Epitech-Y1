/*
** EPITECH PROJECT, 2020
** CONCAT_PARAMETERS
** File description:
** concat parameters
*/

#include <stdlib.h>
#include "my.h"

static void copy_2d_tab_to_1d(char *result, char **args, int nb)
{
    int cursor = 0;
    int count = 0;

    for (int j = 0; j < nb; j++) {
        for (int i = 0; args[j][i]; i++) {
            result[cursor] = args[j][i];
            cursor++;
        }
        if (count != nb - 1) {
            result[cursor] = '\n';
            cursor++;
        }
        count++;
    }
}

char *concat_parameters(int nb, char **args)
{
    int size = 0;
    char *result = NULL;

    if (nb == 0)
        return (NULL);
    for (int j = 0; j < nb; j++) {
        for (int i = 0; args[j][i]; i++)
            size++;
    }
    result = malloc(sizeof(char) * (size + nb));
    if (result == NULL)
        return (NULL);
    copy_2d_tab_to_1d(result, args, nb);
    return (result);
}