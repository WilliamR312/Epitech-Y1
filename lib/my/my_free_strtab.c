/*
** EPITECH PROJECT, 2020
** MY_FREE_STRTAB
** File description:
** Free str tab
*/

#include <stdlib.h>

void my_free_strtab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}