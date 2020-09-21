/*
** EPITECH PROJECT, 2019
** INCLUDE_MY_SOKOBAN
** File description:
** struc of my sokoban
*/

#ifndef MY_STRUCT_H
#define MY_STRUCT_H

typedef struct map_data
{
    int size;
    int rows;
    int max_col;
    int pos_player_x;
    int pos_player_y;
    int nbr_box;
    int nbr_box_place;
    int game_state;
    int over;
}map_data_t;

#endif