/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** seconde_player
*/
#include "my.h"
#include "my_navy.h"

void free_ressources(char ***maps)
{
    free(maps[0]);
    free(maps[1]);
    free(maps);
}