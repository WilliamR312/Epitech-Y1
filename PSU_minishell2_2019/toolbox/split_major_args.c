/*
** EPITECH PROJECT, 2020
** SPLIT_STRING
** File description:
** split string, separators will all be space or tab character.
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int count_args(char const *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ';' || str[i] == '|')
            count++;
    }
    return (count + 1);
}

static char ***fill_3d_tab(char const *str, char ***tab, int nb_words)
{
    int min = 0;
    int max = 0;

    for (int i = 0; i < nb_words; i++) {
        for (; str[max] != ';' && str[max] != '\0'; max++);
        tab[i] = split_args_limits(str, min, max - 1);
        max++;
        min = max;
    }
    return (tab);
}

char ***split_major_args(char const *str)
{
    int nb_args = 0;
    char ***tab = NULL;

    nb_args = count_args(str);
    tab = malloc(sizeof(char **) * (nb_args + 1));
    tab = fill_3d_tab(str, tab, nb_args);
    tab[nb_args] = NULL;
    return (tab);
}