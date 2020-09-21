/*
** EPITECH PROJECT, 2019
** STRUCT
** File description:
** Struct used by my_hunter
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct window
{
    sfRenderWindow *window;
    sfEvent event;
    unsigned int width;
    unsigned int height;
}window_t;

typedef struct graph_element
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
}g_element_t;

typedef struct sound
{
    unsigned int state;
    sfSoundBuffer* interract_mem;
    sfSound* interract_sound;
}
sound_t;

typedef struct music
{
    sfMusic* music;
}music_t;

typedef struct menu_button
{
    g_element_t button_play_p;
    g_element_t button_quit_p;
    sfTexture *button_play_red;
    sfTexture *button_quit_red;
    sound_t button_sound_p;
}menu_b_t;

typedef struct menu
{
    g_element_t background_p;
    g_element_t empire_logo_p;
    g_element_t title_p;
    menu_b_t menu_b_p;
    music_t music_menu_p;

}menu_t;

typedef struct game
{
    unsigned int game_statut;
}game_t;

typedef struct player
{
    unsigned int hp;
    int score;
}player_t;

typedef struct vessel
{
    g_element_t g_vessel_p;
    sfVector2f offset;
    sfClock *clock;
    unsigned int escape;
    unsigned int state;
}v_01_t;

typedef struct ennemis
{
    v_01_t x_wing_01;
    v_01_t x_wing_02;
    g_element_t destroy_x_wing;
}ennemis_t;

typedef struct cursor
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
}cursor_t;

typedef struct game_01
{
    sfClock *clock;
    sfTexture *texture_field;
    sfSprite *sprite_field;
    sfTexture *texture_sky;
    sfSprite *sprite_sky;
    sfIntRect rect;
    ennemis_t ennemis_p;
    cursor_t cursor_p;
    music_t music_p;
    sound_t shoot_p;
    sound_t explosion_p;
    g_element_t rebel_score;
    g_element_t empire_score;
}game_01_t;

typedef struct all_struct
{
    game_t game_p;
    player_t player_p;
    window_t window_p;
    menu_t menu_p;
    game_01_t game_01_p;
}all_t;

typedef struct game_statut
{
    unsigned int statut;
    void (*f)(all_t *);
}game_state_t;

typedef struct vessel_statut
{
    unsigned int statut;
    void (*f)(v_01_t *, all_t *);
}vessel_state_t;

#endif