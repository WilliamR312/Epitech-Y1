/*
** EPITECH PROJECT, 2020
** MY_HEADER
** File description:
** ITS MYYY HEADEEEEEER
*/

#include "struct.h"

#ifndef MY_MS_H_
#define MY_MS_H_

void display_matchstick(nfo_t *game_d);
int player_turn(nfo_t *game_d);
int ask_match(nfo_t *game_d);
int ask_line(nfo_t *game_d);
void ai_turn(nfo_t *game_d);
void ai_action_regular_g(nfo_t *game_d);
void ai_action_end_g(nfo_t *game_d);
int count_nbr_line_fill(nfo_t *game_d);
void two_lines_core(nfo_t *game_d, int one, int two);
int two_lines_case_one_and_other(nfo_t *game_d, int one, int two);

#endif /* !MY_H_ */