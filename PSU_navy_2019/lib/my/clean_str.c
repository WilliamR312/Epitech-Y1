/*
** EPITECH PROJECT, 2020
** clean string
** File description:
** clean str
*/
#include "../../include/my.h"

static char *clean_verif_str(char *new_str)
{
    for (int i = 0; new_str[i] != '\n'; i++)
        if (new_str[i] == ' ' && new_str[i+1] == '\n')
            new_str[i] = '\n';
    return (new_str);
}

char *clean_str(char *str)
{
    int nb_character = 0;
    int space = 0;
    int w = 0;
    char *new_str = NULL;

    for (;str[nb_character] != '\0';nb_character++);
    new_str = malloc(sizeof(char) *(nb_character));
    for (int i = 0, z = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            new_str[w] = str[i];
            w++;
            z = 0;
        } else if (z == 0 && w != 0 && w != nb_character) {
            new_str[w] = ' ';
            z = 1;
            w++;
        }
    }
    new_str = clean_verif_str(new_str);
    free (str);
    return (new_str);
}
