/*
** EPITECH PROJECT, 2020
** DRAW_GAME_SHOP
** File description:
** manage display of game shop
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void draw_hand_tower_range(sfRenderWindow *window, tower_hand_t *tower)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f pos = tower->pos;
    sfColor ccolor = {200, 200, 255, 40};
    sfColor ocolor = {220, 220, 255, 100};

    sfCircleShape_setRadius(circle, tower->range);
    pos.x = pos.x - tower->range + tower->base.x;
    pos.y = pos.y - tower->range + tower->base.y;
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setFillColor(circle, ccolor);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOutlineColor(circle, ocolor);
    sfRenderWindow_drawCircleShape(window, circle, NULL);
}

static void check_placement(tower_hand_t *tower, \
scene_game_t *game)
{
    sfColor good_color = {220, 220, 255, 220};
    sfColor bad_color = {255, 180, 180, 220};
    int collision = 0;

    collision += check_all_collision_block(tower, game);
    collision += check_all_collision_tower(tower, game);
    if (collision >= 1) {
        game->shop.on_hand = 2;
        sfSprite_setColor(tower->sprite, bad_color);
    } else {
        game->shop.on_hand = 1;
        sfSprite_setColor(tower->sprite, good_color);
    }
}

void draw_hand_tower(sfRenderWindow *window, tower_hand_t *tower, \
scene_game_t *game)
{
    sfVector2i pos = {0, 0};
    sfVector2f fpos = {0, 0};

    pos = sfMouse_getPositionRenderWindow(window);
    fpos = (sfVector2f) {(pos.x - tower->base.x), (pos.y - tower->base.y)};
    tower->pos.x = fpos.x;
    tower->pos.y = fpos.y;
    sfSprite_setPosition(tower->sprite, fpos);
    draw_hand_tower_range(window, tower);
    check_placement(tower, game);
    sfRenderWindow_drawSprite(window, tower->sprite, NULL);
}