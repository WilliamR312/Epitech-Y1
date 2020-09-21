/*
** EPITECH PROJECT, 2020
** FREE_ALL
** File description:
** manage free of all ressouces
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

void free_enemy_wave(wave_data_t *wave_d)
{
    wave_enemy_t *index = NULL;
    wave_enemy_t *to_destroy = NULL;

    if (wave_d->nb_enemy > 0)
        index = wave_d->wave_enemy;
    sfTexture_destroy(wave_d->enemy_01);
    sfTexture_destroy(wave_d->enemy_02);
    for (int i = 0; i < wave_d->nb_enemy; i++) {
        sfSprite_destroy(index->enemy.sprite);
        sfClock_destroy(index->enemy.move_clock);
        sfClock_destroy(index->enemy.anim_clock);
        to_destroy = index;
        if (index->next != NULL)
            index = index->next;
        free(to_destroy);
    }
}

void free_towers_on_map(scene_game_t *game)
{
    tower_on_map_t *index = NULL;
    tower_on_map_t *to_destroy = NULL;

    if (game->nb_tower_map > 0)
        index = game->tower_on_map;
    for (int i = 0; i < game->nb_tower_map; i++) {
        sfSprite_destroy(index->tower.sprite);
        sfClock_destroy(index->tower.shoot_cloak);
        to_destroy = index;
        if (index->next != NULL)
            index = index->next;
        free(to_destroy);
    }
}

void free_shop(shop_t *shop)
{
    sfRectangleShape_destroy(shop->bar);
    if (shop->on_hand == 1)
        sfSprite_destroy(shop->tower_hand.sprite);
    for (int i = 0; i < shop->nb_towers; i++) {
        sfSprite_destroy(shop->tower_on_shop[i].sprite);
        sfTexture_destroy(shop->tower_on_shop[i].texture);
        sfText_destroy(shop->tower_on_shop[i].text_price);
    }
    free(shop->tower_on_shop);
}

void free_box(scene_game_t *game)
{
    for (int i = 0; i < game->nb_dir_box; i++)
        sfRectangleShape_destroy(game->dir_box[i].rect);
    for (int i = 0; i < game->nb_block_box; i++)
        sfRectangleShape_destroy(game->block_box[i].rect);
}

void free_game_menu(game_menu_t *game_m, button_t *play_pause)
{
    sfRectangleShape_destroy(game_m->rect);
    for (int i = 0; i < game_m->nb_buttons; i++) {
        sfRectangleShape_destroy(game_m->button_tab[i].rect);
        sfTexture_destroy(game_m->button_tab[i].texture);
    }
    sfRectangleShape_destroy(play_pause->rect);
    sfTexture_destroy(play_pause->texture);
}