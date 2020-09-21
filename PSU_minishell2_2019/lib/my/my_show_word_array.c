/*
** EPITECH PROJECT, 2020
** MY_SHOW_WORD_ARRAY
** File description:
** shows an array of words in a single string separated by \ns
*/

#include <stdlib.h>
#include "my.h"

static int is_anum(char c)
{
    if (('0' <= c &&  c <= '9')
    || ('a' <= c && c <= 'z')
    || ('A' <= c && c <= 'Z' ))
        return (1);
    return (0);
}

static int whole_strlen(int argc, char * const *argv)
{
    int whole_strlen = 0;

    for (int i = 0; i < argc; i++) {
        whole_strlen += my_strlen(argv[i]);
    }
    return (whole_strlen);
}

static int my_strlen_2dim(char * const *tab)
{
    int length = 0;

    for (int i = 0; tab[i] != 0; i++)
        length++;
    return (length);
}

int my_show_word_array(char * const *tab)
{
    int nb_words = my_strlen_2dim(tab);
    int whole_length = whole_strlen(nb_words, tab);
    char *dest = NULL;

    if (tab[0] != 0 && is_anum(tab[0][0])) {
        dest = malloc(sizeof(char) * (whole_length + nb_words + 1));
        my_strcpy(dest, tab[0]);
        my_strcat(dest, "\n");
        for (int i = 1; i < nb_words; i++) {
            my_strcat(dest, tab[i]);
            my_strcat(dest, "\n");
        }
        my_putstr(dest);
        free(dest);
        return (1);
    } else if (tab[0][0] == '\0') {
        my_putchar('\n');
        return (0);
    }
    return (-1);
}