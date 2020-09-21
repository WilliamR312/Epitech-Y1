/*
** EPITECH PROJECT, 2020
** INIT_ENEMY
** File description:
** initialisation of enemies
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_enemy_01(enemy_t *enemy, int cursor, wave_data_t *wave_data)
{
    sfVector2f speed = {0.05, 0};
    sfIntRect rect = {0, 0, 36, 53};
    sfVector2f position = {cursor, 550};

    enemy->id = 1;
    enemy->rect = rect;
    enemy->sprite = sfSprite_create();
    enemy->move_clock = sfClock_create();
    sfSprite_setTexture(enemy->sprite, wave_data->enemy_01, sfTrue);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    enemy->speed = speed;
    sfSprite_setPosition(enemy->sprite, position);
    enemy->anim_clock = sfClock_create();
    enemy->hp = 30;
    enemy->hit_p = 10;
    enemy->dir = 2;
    enemy->type = 1;
}

static void init_enemy_02(enemy_t *enemy, int cursor, wave_data_t *wave_data)
{
    sfVector2f speed = {0.12, 0};
    sfIntRect rect = {0, 0, 113, 36};
    sfVector2f position = {cursor, 550};

    enemy->id = 2;
    enemy->rect = rect;
    enemy->sprite = sfSprite_create();
    enemy->move_clock = sfClock_create();
    sfSprite_setTexture(enemy->sprite, wave_data->enemy_02, sfTrue);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    enemy->speed = speed;
    sfSprite_setPosition(enemy->sprite, position);
    enemy->anim_clock = sfClock_create();
    enemy->hp = 20;
    enemy->hit_p = 15;
    enemy->dir = 2;
    enemy->type = 2;
}

static wave_enemy_t *init_wave_clist(int cursor, int type,
wave_data_t *wave_data)
{
    wave_enemy_t *element = NULL;

    element = malloc(sizeof(wave_enemy_t));
    if (type == 1)
        init_enemy_01(&element->enemy, cursor, wave_data);
    if (type == 2)
        init_enemy_02(&element->enemy, cursor, wave_data);
    element->next = NULL;
    element->prev = NULL;
    return (element);
}

static void fill_wave_clist(wave_enemy_t **element, int cursor, int type,
wave_data_t *wave_data)
{
    wave_enemy_t *new_element = NULL;

    new_element = malloc(sizeof(wave_enemy_t));
    if (type == 1)
        init_enemy_01(&new_element->enemy, cursor, wave_data);
    if (type == 2)
        init_enemy_02(&new_element->enemy, cursor, wave_data);
    new_element->next = NULL;
    new_element->prev = (*element);
    (*element)->next = new_element;
    *element = new_element;
}

void init_wave(core_t *core_d)
{
    wave_enemy_t *racine = NULL;
    wave_enemy_t *element = NULL;
    int nb_enemy = 0;
    int spacing = 55;
    int cursor = -10;

    element = init_wave_clist(cursor, 1, &core_d->game_scene.wave_data);
    racine = element;
    for (nb_enemy = 1; nb_enemy < 11; nb_enemy++) {
        cursor -= spacing;
        if (nb_enemy == 6)
            fill_wave_clist(&element, cursor, 2,
            &core_d->game_scene.wave_data);
        else
            fill_wave_clist(&element, cursor, 1,
            &core_d->game_scene.wave_data);
    }
    element->next = racine;
    racine->prev = element;
    core_d->game_scene.wave_data.wave_enemy = racine;
    core_d->game_scene.wave_data.nb_enemy = nb_enemy;
}