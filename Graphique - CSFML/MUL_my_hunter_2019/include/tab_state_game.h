/*
** EPITECH PROJECT, 2019
** TAB
** File description:
** Tab used by my_hunter
*/

#include "my_hunter.h"
#include "../include/struct.h"

#ifndef TAB_GAME_H
#define TAB_GAME_H

game_state_t tab_game_statut[] = {
    {0, &menu},
    {1, &menu_to_game_01},
    {2, &game_01}
};

#endif