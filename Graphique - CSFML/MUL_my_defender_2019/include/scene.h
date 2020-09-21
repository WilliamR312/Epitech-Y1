/*
** EPITECH PROJECT, 2020
** STRUCT
** File description:
** Struct used by me
*/

#ifndef SCENE_H
#define SCENE_H

#include "struct.h"
#include "my_def.h"

scene_tab_t scene_tab[] = {
    {1, &menu_core},
    {2, &intro_scene},
    {3, &game_core},
    {4, &result_scene},
    {5, &htp_scene}
};

#endif