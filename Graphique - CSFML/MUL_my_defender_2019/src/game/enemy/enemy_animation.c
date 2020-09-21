/*
** EPITECH PROJECT, 2020
** ENEMY_ANIMATION
** File description:
** manage enemy animation
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

void enemy_01_animation(enemy_t *enemy)
{
    sfTime time;
    float seconds = 0;

    if (enemy->id == 2)
        return;
    time = sfClock_getElapsedTime(enemy->anim_clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.18) {
        enemy->rect.left = enemy->rect.left + 36;
        if (enemy->rect.left == 288)
            enemy->rect.left = 0;
        sfClock_restart(enemy->anim_clock);
        sfSprite_setTextureRect(enemy->sprite, \
        enemy->rect);
    }
}

void smooth_enemy(enemy_t *enemy, int pause)
{
    sfTime time;
    sfVector2f offset = enemy->speed;
    float seconds;

    if (pause == 0) {
        time = sfClock_getElapsedTime(enemy->move_clock);
        seconds = sfTime_asMilliseconds(time);
        offset.x *= seconds;
        offset.y *= seconds;
        sfSprite_move(enemy->sprite, offset);
    }
    sfClock_restart(enemy->move_clock);
}

static void change_enemy_dir(enemy_t *enemy, dir_box_t *dir_box)
{
    if (dir_box->dir == 1 && enemy->dir != 1) {
        enemy->speed.y = - enemy->speed.x;
        enemy->speed.x = 0;
        enemy->dir = 1;
    }
    if (dir_box->dir == 2 && enemy->dir != 2) {
        if (enemy->dir == 1)
            enemy->speed = (sfVector2f) {(enemy->speed.y * (-1)), 0};
        else
            enemy->speed = (sfVector2f) {enemy->speed.y, 0};
        enemy->dir = 2;
    }
    if (dir_box->dir == 3 && enemy->dir != 3) {
        enemy->speed = (sfVector2f) {0, enemy->speed.x};
        enemy->dir = 3;
    }
}

void check_dir_box(enemy_t *enemy, scene_game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(enemy->sprite);

    for (int i = 0; i < game->nb_dir_box; i++) {
        sfFloatRect dir_box_rect = \
            sfRectangleShape_getGlobalBounds(game->dir_box[i].rect);
        if (sfFloatRect_contains(&dir_box_rect, pos.x, pos.y) == sfTrue) {
            change_enemy_dir(enemy, &game->dir_box[i]);
        }
    }
}