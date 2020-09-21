/*
** EPITECH PROJECT, 2020
** TOWER_ATTACK
** File description:
** manage attack of the towers
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static int compute_distance(sfVector2f tpos, sfVector2f epos, sfVector2f base)
{
    int distance = 0;
    int a = 0;
    int b = 0;

    a = (epos.x - (tpos.x + base.x));
    if (a < 0)
        a = a * (-1);
    b = (epos.y - (tpos.y + base.y));
    if (b < 0)
        b = b * (-1);
    distance = a + b;
    return (distance);
}

static int check_enemy_on_tower_range(tower_t *tower, enemy_t *enemy)
{
    sfVector2f tpos = tower->pos;
    sfVector2f epos = sfSprite_getPosition(enemy->sprite);
    int distance = 1980;
    int tmp_dist = 0;

    for (int i = 0; i != 2; i++) {
        tmp_dist = compute_distance(tpos, epos, tower->base);
        if (tmp_dist < distance)
            distance = tmp_dist;
        epos.x = epos.x + enemy->rect.width;
        tmp_dist = compute_distance(tpos, epos, tower->base);
        if (tmp_dist < distance)
            distance = tmp_dist;
        epos.x = epos.x - enemy->rect.width;
        epos.y = epos.y + enemy->rect.height;
    }
    if (distance > tower->range)
        return (-1);
    return (distance);
}

static void tower_attack_rate(tower_t *tower, enemy_t *enemy)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(tower->shoot_cloak);
    seconds = time.microseconds / 1000000.0;
    if (seconds > tower->shoot_speed) {
        enemy->hp -= tower->hit_p;
        sfClock_restart(tower->shoot_cloak);
    }
}

void check_tower_attack(scene_game_t *game, tower_t *tower)
{
    wave_enemy_t *index = game->wave_data.wave_enemy;
    wave_enemy_t *origin = game->wave_data.wave_enemy;
    int dist = 0;
    int best_dist = 1080;

    tower->target = NULL;
    for (int i = 0; index != origin || i == 0; index = index->next, i++) {
        dist = check_enemy_on_tower_range(tower, &index->enemy);
        if (tower->type == index->enemy.type && dist != -1) {
            if (dist < best_dist) {
                tower->target = index;
                tower_attack_rate(tower, &index->enemy);
            }
        }
    }
}