/*
** EPITECH PROJECT, 2020
** STRUCT
** File description:
** Struct used by my_runner
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct icon_data
{
    sfImage *icon_image;
    const sfUint8 *icon_uint;
}icon_t;

typedef struct window_prop
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    unsigned int width;
    unsigned int height;
    icon_t icon_d;
}window_t;

typedef struct graphic_element
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
}g_element_t;

typedef struct parallax_element
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfClock *clock;
}p_element_t;

typedef struct background
{
    p_element_t back_00;
    p_element_t back_01;
    p_element_t back_02;
    p_element_t back_03;
}background_t;

typedef struct character_data
{
    g_element_t character;
    g_element_t dead_char;
    sfClock *clock_anim;
    sfClock *clock_jump;
    sfVector2f land_level;
    float attenuation;
    int state;
    int ground;
}char_t;

typedef struct all_sound_data
{
    sfSoundBuffer *sound_b;
    sfSound *sound;
    int state;
}sound_t;

typedef struct all_sounds_data
{
    sfMusic *music_1;
    sound_t sound_data;
}all_sounds_t;

typedef struct map_data
{
    char **map;
    int map_size;
    int nb_line;
    g_element_t block_1;
    g_element_t block_2;
    sfClock *clock;
    sfVector2f cursor;
    sfVector2f cursor_move;
}map_t;

typedef struct text_data
{
    sfFont *font;
    sfText *text_1;
    sfText *text_2;
    sfText *result;
    sfText *restart;
}text_t;

typedef struct score_data
{
    int score_int;
    char *score_str;
    sfClock *clock_score;
}score_t;

typedef struct core_struct
{
    map_t map_d;
    window_t window_p;
    background_t background;
    char_t character_data;
    all_sounds_t all_sounds_d;
    text_t text_d;
    score_t score_d;
    int game_state;
}core_t;

#endif