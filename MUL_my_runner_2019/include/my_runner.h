/*
** EPITECH PROJECT, 2019
** INCLUDE_MY_RUNNER
** File description:
** my_runner includes
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

void game_core(core_t *core_d);
void draw_background_core(core_t *core_d);
void load_background_res(background_t *back_d);
void load_ressource(core_t *core_d);
void analysis_events(core_t *core_d);
void character_management(core_t *core_d);
int map_load(map_t *map_d, char *path);
int map_display(core_t *core_d);
void load_map_res(map_t *map_d);
void block_1(core_t *core_d, int y, int x);
void block_2(core_t *core_d, int y, int x);
void exit_free_res(core_t *core_d);
void character_alive(core_t *core_d);
void character_dead(core_t *core_d);
void load_char_res(char_t *char_d);
void load_sound_res(all_sounds_t *all_sounds_d);
void load_text_res(text_t *text_d);
void score_management(core_t *core_d);
void restart_key_game(core_t *core_d, sfKeyEvent key);
void win_game(core_t *core_d);
void character_win(core_t *core_d);

#endif