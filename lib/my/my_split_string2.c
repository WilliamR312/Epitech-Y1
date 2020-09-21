/*
** EPITECH PROJECT, 2020
** SPLIT_STRING2
** File description:
** split string, separators will all be non-alphanumeric characters.
*/

#include <stdlib.h>
#include "my.h"

static int count_words(char const *str, char sep)
{
    int count = 0;
    int lock = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == sep && lock == 1)
            lock = 0;
        if (str[i] != sep && lock == 0) {
            lock = 1;
            count++;
        }
    }
    return (count);
}

static int count_one_word(char const *str, int cursor, char sep)
{
    int size = 0;

    for (; str[cursor] != sep; cursor++)
        size++;
    return (size);
}

static void fill_word(char const *src, char *dest, int size, int cursor)
{
    int i = 0;

    for (i = 0; i < size; i++, cursor++)
        dest[i] = src[cursor];
    dest[i] = '\0';
}

static void fill_2d_tab(char const *str, char **words, int nb_words, char sep)
{
    int word_size = 0;
    int lock = 0;
    int i = 0;
    int count = 0;

    while (count != nb_words) {
        if (str[i] == sep) {
            lock = 0;
            i++;
        }
        if (str[i] != sep && lock == 0) {
            word_size = count_one_word(str, i, sep);
            words[count] = NULL;
            words[count] = malloc(sizeof(char) * (word_size + 1));
            fill_word(str, words[count], word_size, i);
            i = i + word_size;
            lock = 1;
            count++;
        }
    }
}

char **my_split_str2(char const *str, char sep)
{
    int nb_words = 0;
    char **words = NULL;

    nb_words = count_words(str, sep);
    words = malloc(sizeof(char *) * (nb_words + 1));
    fill_2d_tab(str, words, nb_words, sep);
    words[nb_words] = NULL;
    return (words);
}