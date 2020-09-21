/*
** EPITECH PROJECT, 2020
** STRUCT_H
** File description:
** Struct used by matchstick
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct choice
{
    int line;
    int match;
}choice_t;

typedef struct game_data
{
    int *tab_stick;
    int total_stick;
    int size;
    int max_take;
    int max_size;
    int turn_state;
    choice_t player_choice;
    choice_t ai_choice;
}nfo_t;

#endif /* !MY_H_ */