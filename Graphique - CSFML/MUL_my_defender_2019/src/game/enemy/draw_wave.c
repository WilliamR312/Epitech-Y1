/*
** EPITECH PROJECT, 2020
** DRAW_WAVE
** File description:
** manage draw wave of enemies
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void free_enemy(wave_enemy_t *enemy_d)
{
    sfSprite_destroy(enemy_d->enemy.sprite);
    sfClock_destroy(enemy_d->enemy.anim_clock);
    sfClock_destroy(enemy_d->enemy.move_clock);
    free(enemy_d);
}

static void despawn_enemy(wave_enemy_t **enemy_d, scene_game_t *game)
{
    wave_enemy_t *to_destroy = *enemy_d;

    if ((*enemy_d) == game->wave_data.wave_enemy && \
    game->wave_data.nb_enemy > 0)
        game->wave_data.wave_enemy = game->wave_data.wave_enemy->next;
    if (game->wave_data.nb_enemy > 0) {
        (*enemy_d)->prev->next = (*enemy_d)->next;
        (*enemy_d)->next->prev = (*enemy_d)->prev;
        (*enemy_d) = (*enemy_d)->prev;
    } else {
        game->wave_data.wave_enemy = NULL;
    }
    free_enemy(to_destroy);
    game->wave_data.nb_enemy -= 1;
}

static void check_on_base(wave_enemy_t *enemy_d, scene_game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(enemy_d->enemy.sprite);
    enemy_d->enemy.pos = pos;

    if (pos.x >= 1920) {
        game->life -= 10;
        enemy_d->enemy.hp = 0;
    }
}

void check_hp(wave_enemy_t **enemy_d, scene_game_t *game)
{
    if (game->wave_data.nb_enemy > 0 && (*enemy_d)->enemy.hp <= 0) {
        if ((*enemy_d)->enemy.pos.x < 1920) {
            game->money += 50;
            game->score += 10 * (*enemy_d)->enemy.type;
        }
        despawn_enemy(enemy_d, game);
    }
}

void draw_wave(sfRenderWindow *window, scene_game_t *game)
{
    wave_enemy_t *index = NULL;

    if (game->wave_data.nb_enemy <= 0)
        return;
    index = game->wave_data.wave_enemy;
    do {
        if (game->wave_data.nb_enemy > 0) {
            smooth_enemy(&index->enemy, game->pause);
            sfRenderWindow_drawSprite(window, index->enemy.sprite, NULL);
            index = index->next;
        }
        if (game->pause == 0) {
            enemy_01_animation(&index->enemy);
            check_dir_box(&index->enemy, game);
            check_on_base(index, game);
            check_hp(&index, game);
        }
    } while (game->wave_data.nb_enemy > 0 && \
    index != game->wave_data.wave_enemy);
}