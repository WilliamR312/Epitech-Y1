/*
** EPITECH PROJECT, 2019
** INCLUDE_MY_HUNTER
** File description:
** my_hunter includes
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

void createMyWindow(window_t *window_d);
void ressource_load(all_t *all_sd);
void menu(all_t *all_sd);
void game_loop(void);
void game_state(all_t *all_sd);
void menu_res_load(menu_t *menu_d, window_t window_d, game_t *game);
void menu_display_elements(window_t window_d, menu_t menu_d);
void help_display(void);
void analyse_events(all_t *all_sd);
void button(sfMouseMoveEvent event, window_t window_d, menu_t *menu_d);
void manage_click(sfMouseButtonEvent event, all_t *all_sd);
int button_play(sfMouseMoveEvent event, window_t window_d, menu_t *menu_d);
int button_quit(sfMouseMoveEvent event, window_t window_d, menu_t *menu_d);
void menu_button_play_res(menu_t *menu_d);
void menu_button_quit_res(menu_t *menu_d);
void menu_title_res(menu_t *menu_d);
void menu_empire_logo_res(menu_t *menu_d);
void menu_background_res(menu_t *menu_d, window_t window_d);
void menu_sound_res(menu_t *menu_d);
void menu_destroy(all_t *all_sd);
void game_res_load(game_01_t *game_01_d, window_t window_d);
void game_sky_res(game_01_t *game_01_d, window_t window_d);
void game_field_res(game_01_t *game_01_d, window_t window_d);
void game_background_load(game_01_t *game_01_d, window_t window_d);
void game_ennemis_load(ennemis_t *ennemis_d);
void game_hud_rebel_score_res(game_01_t *game_01_d);
void game_hud_empire_score_res(game_01_t *game_01_d);
void game_cursor_res(game_01_t *game_01_d);
void game_hud_load(game_01_t *game_01_d);
void game_01(all_t *all_sd);
void menu_to_game_01(all_t *all_sd);
void ennemies_spawn(ennemis_t *enemies_d);
void game_sound_res(game_01_t *game_01_d);
void game_hud_res(game_01_t *game_01_d);
void enemies_respawn(all_t *all_sd);
void cursor(sfMouseMoveEvent event, cursor_t cursor_d);
void ennemis_01_management(v_01_t *vessel_d, all_t *all_sd);
void ennemis_01_crash(v_01_t *vessel_d ,all_t *all_sd);
void ennemis_01_hit(v_01_t *vessel_d ,all_t *all_sd);
void ennemis_01_alive(v_01_t *vessel_d ,all_t *all_sd);
void game_destroy_xwing(ennemis_t *ennemis_d);
void game_xwing_02_res(ennemis_t *ennemis_d);
void game_xwing_01_res(ennemis_t *ennemis_d);
void score_rebel_mangement(game_01_t *game_01_d);
void enemies_management(all_t *all_sd);
void game_01_display_element(all_t *all_sd);
void ennemis_01_animation(v_01_t *vessel_d);
void ennemis_01_destroy_animation(v_01_t *vessel_d);
void enemy_01(sfMouseButtonEvent event, ennemis_t *ennemis_d,\
game_01_t *game_01_d);
void enemy_02(sfMouseButtonEvent event, ennemis_t *ennemis_d,\
game_01_t *game_01_d);
void shoot_event(sfMouseButtonEvent event, ennemis_t *ennemis_d,\
game_01_t *game_01_d);
void shoot_management(all_t *all_sd);
void enemies_01_colision_left(window_t window_d, v_01_t *vessel_d,\
int x, int y);
void enemies_01_colision_right(window_t window_d, v_01_t *vessel_d,\
int x, int y);
void enemies_01_colision_up(window_t window_d, v_01_t *vessel_d,\
int x, int y);
void enemies_01_colision_down(window_t window_d, v_01_t *vessel_d,\
int x, int y);
void enemies_01_colision_management(window_t window_d, v_01_t *vessel_d);
void enemies_01_despawn(all_t *all_sd, v_01_t *vessel_d);
void ennemis_01_destroy(v_01_t *vessel_d, all_t *all_sd);
void ennemis_01_management(v_01_t *vessel_d, all_t *all_sd);

#endif