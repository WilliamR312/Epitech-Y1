/*
** EPITECH PROJECT, 2019
** MY_DEFENDER_PROTOTYPES
** File description:
** all prototypes used by my def
*/

#include "struct.h"

#ifndef MY_DEF_H_
#define MY_DEF_H_

/// MENU ///

void menu_core(core_t *core_d);
void menu_analysis_events(core_t *core_d);
void init_menu_ressources(core_t *core_d);
void init_game_ressources(core_t *core_d);
void init_menu_buttons(core_t *core_d);
void init_menu_sounds(scene_menu_t *menu);
void free_menu(scene_menu_t *menu);

/// ACTION BUTTONS ///

void action_quit_button(core_t *core_d);
void action_play_button(core_t *core_d);
void action_htp_button(core_t *core_d);

/// GAME ///

void game_core(core_t *core_d);
void game_analysis_events(core_t *core_d);
void init_shop(core_t *core_d);
void draw_shop(core_t *core_d);
void check_shop_actions(scene_game_t *game, sfMouseButtonEvent event);
void init_text_game(core_t *core_d);
void put_hand_tower(scene_game_t *game, sfMouseButtonEvent event);
void draw_tower_on_map(core_t *core_d);
void init_tower_01_in_shop(tower_shop_t *new_tower, core_t *core_d);
void init_tower_02_in_shop(tower_shop_t *new_tower, core_t *core_d);
void init_tower_03_in_shop(tower_shop_t *new_tower, core_t *core_d);
void init_tower_04_in_shop(tower_shop_t *new_tower, core_t *core_d);
void init_wave(core_t *core_d);
void init_all_direction_box(core_t *core_d);
void init_play_pause_button(core_t *core_d);
void init_menu_game(game_menu_t *game_menu);
void draw_menu_game(scene_game_t *game, sfRenderWindow *window);
void check_tower_attack(scene_game_t *game, tower_t *tower);
void draw_wave(sfRenderWindow *window, scene_game_t *game);
void enemy_01_animation(enemy_t *enemy);
void smooth_enemy(enemy_t *enemy, int pause);
void check_dir_box(enemy_t *enemy, scene_game_t *game);
void resume_game_action(core_t *core_d);
void return_to_menu_game_action(core_t *core_d);
void quit_game_action(core_t *core_d);
void init_all_block_box(core_t *core_d);
void draw_hand_tower(sfRenderWindow *window, tower_hand_t *tower, \
    scene_game_t *game);
int check_all_collision_tower(tower_hand_t *tower, scene_game_t *game);
int check_all_collision_block(tower_hand_t *tower, scene_game_t *game);
void free_game_core(scene_game_t *game);
void free_game_menu(game_menu_t *game_m, button_t *play_pause);
void free_box(scene_game_t *game);
void free_shop(shop_t *shop);
void free_towers_on_map(scene_game_t *game);
void free_enemy_wave(wave_data_t *wave_d);
void init_money_text(core_t *core_d);
void init_life_text(core_t *core_d);
void draw_money(core_t *core);

void draw_life(core_t *core);
void draw_score_ingame(core_t *core);
void init_score_text(core_t *core_d);

/// HOW TO PLAY ///

void htp_scene(core_t *core_d);

/// RESULT ///

void result_scene(core_t *core_d);
void init_result_ressources(core_t *core_d);

/// INTRO ///

void intro_scene(core_t *core_d);

#endif /* !MY_H_ */