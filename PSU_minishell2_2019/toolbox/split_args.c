/*
** EPITECH PROJECT, 2020
** SPLIT_STRING
** File description:
** split string, separators will all be space or tab character.
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int count_words(char const *str)
{
    int count = 0;
    int lock = 0;

    for (int i = 0; str[i]; i++) {
        if (is_space_tab(str[i]) == 1 && lock == 1)
            lock = 0;
        if (is_space_tab(str[i]) == 0 && lock == 0) {
            lock = 1;
            count++;
        }
    }
    return (count);
}

static int count_one_word(char const *str, int cursor)
{
    int size = 0;

    for (; is_space_tab(str[cursor]) == 0 && str[cursor] != '\0' && \
    str[cursor] != '\n'; cursor++)
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

static char **fill_2d_tab(char const *str, char **words, int nb_words)
{
    int word_size = 0;
    int lock = 0;
    int i = 0;
    int count = 0;

    while (count != nb_words) {
        if (is_space_tab(str[i]) == 1) {
            lock = 0;
            i++;
        }
        if (is_space_tab(str[i]) == 0 && lock == 0) {
            word_size = count_one_word(str, i);
            words[count] = NULL;
            words[count] = malloc(sizeof(char) * (word_size + 1));
            fill_word(str, words[count], word_size, i);
            i = i + word_size;
            lock = 1;
            count++;
        }
    }
    return (words);
}

char **split_args(char const *str)
{
    int nb_words = 0;
    char **words = NULL;

    nb_words = count_words(str);
    words = malloc(sizeof(char *) * (nb_words + 1));
    words = fill_2d_tab(str, words, nb_words);
    words[nb_words] = NULL;
    return (words);
}