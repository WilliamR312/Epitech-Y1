/*
** EPITECH PROJECT, 2020
** STRUCT
** File description:
** Struct used by my_defender
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct sound_s {
    sfSoundBuffer *sound_b;
    sfSound *sound;
}sound_t;

typedef struct music_s {
    sfMusic *music;
}music_t;

typedef struct icon_s {
    sfImage *icon_img;
    const sfUint8 *icon_uint;
}icon_t;

typedef struct window_prop {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    unsigned int width;
    unsigned int height;
    icon_t icon;
}window_t;

typedef struct core_d core_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfIntRect text_rect;
    sfTexture *texture;
    int state;
    void (* callback)(core_t *);
}button_t;

typedef struct background_d {
    sfTexture *texture;
    sfSprite *sprite;
}background_t;

typedef struct scene_tab_d {
    int id_scene;
    void (* scene)(core_t *);
}scene_tab_t;

typedef struct enemy {
    int id;
    int hp;
    int hit_p;
    int dir;
    int type;
    sfVector2f pos;
    sfVector2f speed;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *anim_clock;
    sfClock *move_clock;
}enemy_t;

typedef struct wave_enemy_list wave_enemy_t;

typedef struct wave_enemy_list {
    enemy_t enemy;
    wave_enemy_t *next;
    wave_enemy_t *prev;
}wave_enemy_t;

typedef struct tower {
    int id_tower;
    int price;
    int range;
    int hit_p;
    int shoot_speed;
    int type;
    sfClock *shoot_cloak;
    sfVector2f base;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    wave_enemy_t *target;
}tower_t;

typedef struct tower_shop {
    int id_tower;
    int price;
    int range;
    int hit_p;
    int shoot_speed;
    float scale;
    int type;
    sfVector2f base;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text_price;
}tower_shop_t;

typedef struct tower_hand {
    int id_tower;
    int range;
    sfVector2f pos;
    sfVector2f base;
    sfIntRect rect;
    sfSprite *sprite;
}tower_hand_t;

typedef struct tower_on_map tower_on_map_t;

typedef struct tower_on_map {
    tower_t tower;
    tower_on_map_t *next;
    tower_on_map_t *prev;
}tower_on_map_t;

typedef struct direction_box {
    sfVector2f pos;
    sfRectangleShape *rect;
    int dir;
}dir_box_t;

typedef struct block_box {
    sfVector2f pos;
    sfRectangleShape *rect;
    int type;
}block_box_t;

typedef struct scene_htp {
    sfSprite *htp_sprite;
    sfTexture *htp_text;
    sfSprite *exit_sprite;
    sfTexture *exit_text;
}scene_htp_t;

typedef struct shop_bar {
    int on_hand;
    int nb_towers;
    sfRectangleShape *bar;
    tower_shop_t *tower_on_shop;
    tower_hand_t tower_hand;
}shop_t;

typedef struct enemy_wave_data {
    wave_enemy_t *wave_enemy;
    int nb_enemy;
    int actual_wave;
    int max_wave;
    sfTexture *enemy_01;
    sfTexture *enemy_02;
}wave_data_t;

typedef struct game_menu {
    sfRectangleShape *rect;
    sfIntRect text_rect;
    button_t *button_tab;
    int nb_buttons;
}game_menu_t;

typedef struct text_valor {
    sfText *text;
    sfText *valor;
}text_valor_t;

typedef struct money {
    sfRectangleShape *cred_img;
    sfText *money;
}money_t;

typedef struct scene_game {
    int pause;
    int life;
    int score;
    int money;
    text_valor_t score_text;
    text_valor_t life_text;
    text_valor_t money_text;
    button_t pause_b;
    background_t background;
    int nb_dir_box;
    dir_box_t *dir_box;
    int nb_block_box;
    block_box_t *block_box;
    wave_data_t wave_data;
    shop_t shop;
    int nb_tower_map;
    tower_on_map_t *tower_on_map;
    game_menu_t game_menu;
    sound_t put_sound;
    sfMusic *game_music;
}scene_game_t;

typedef struct scene_menu {
    int nb_buttons;
    button_t *button_tab;
    background_t background;
    sound_t menu_bip;
    music_t menu_music;
}scene_menu_t;

typedef struct result {
    sfSprite *result_sprite;
    sfTexture *result_text;
    text_valor_t score_text;
    int score;
}result_scene_t;

typedef struct fonts_lib_s {
    sfFont *font_01;
}fonts_lib_t;

typedef struct intro {
    sfSprite *sprite;
    sfTexture *texture;
    sfMusic *music;
}scene_intro_t;

typedef struct core_d {
    int id_scene;
    int id_prev_scene;
    window_t window_d;
    scene_menu_t menu_scene;
    scene_game_t game_scene;
    scene_htp_t htp_scene;
    fonts_lib_t fonts_lib;
    scene_intro_t intro;
    result_scene_t result_scene;
}core_t;

#endif