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

static int check_collision_tower(tower_hand_t *tower, sfVector2f pos, \
sfIntRect rect)
{
    sfVector2f pos_tow = tower->pos;
    sfVector2f size_tow = {tower->rect.width, tower->rect.height};

    if ((pos.x > pos_tow.x - 1 && pos.x < (pos_tow.x + size_tow.x + 1) && \
    pos.y > pos_tow.y -1 && pos.y < (pos_tow.y + size_tow.y + 1)) || \
    (pos.x + rect.width > pos_tow.x - 1 && pos.x + rect.width < \
    (pos_tow.x + size_tow.x + 1) && pos.y > pos_tow.y -1 && pos.y < \
    (pos_tow.y + size_tow.y + 1)) || (pos.x > pos_tow.x - 1 && pos.x < \
    (pos_tow.x + size_tow.x + 1) && pos.y + rect.height > pos_tow.y - 1 && \
    pos.y + rect.height < (pos_tow.y + size_tow.y + 1)) ||
    (pos.x + rect.width > pos_tow.x - 1 && pos.x + rect.width < \
    (pos_tow.x + size_tow.x + 1) && pos.y + rect.height > pos_tow.y - 1 && \
    pos.y + rect.height < (pos_tow.y + size_tow.y + 1)))
        return (1);
    return (0);
}

static int check_collision_block(tower_hand_t *tower, block_box_t *block)
{
    sfVector2f pos_tow = tower->pos;
    sfVector2f size_tow = {tower->rect.width, tower->rect.height};
    sfFloatRect frect = sfRectangleShape_getGlobalBounds(block->rect);

    if (sfFloatRect_contains(&frect, pos_tow.x, pos_tow.y) == sfTrue || \
    sfFloatRect_contains(&frect, pos_tow.x + size_tow.x, pos_tow.y) \
    == sfTrue || \
    sfFloatRect_contains(&frect, pos_tow.x, pos_tow.y + size_tow.y) == sfTrue \
    || sfFloatRect_contains(&frect, pos_tow.x + size_tow.y, pos_tow.y + \
    size_tow.y) == sfTrue || \
    sfFloatRect_contains(&frect, pos_tow.x + size_tow.y / 2, pos_tow.y + \
    size_tow.y / 2) == sfTrue)
        return (1);
    return (0);
}

int check_all_collision_block(tower_hand_t *tower, scene_game_t *game)
{
    int collision = 0;

    for (int i = 0; i < game->nb_block_box; i++) {
        collision = check_collision_block(tower, &game->block_box[i]);
        if (collision == 1) {
            return (1);
        }
    }
    return (0);
}

int check_all_collision_tower(tower_hand_t *tower, scene_game_t *game)
{
    int collision = 0;
    tower_on_map_t *element = NULL;
    element = game->tower_on_map;

    for (int i = 0; i < game->nb_tower_map; i++, element = element->next) {
        collision += check_collision_tower(tower, element->tower.pos, \
            element->tower.rect);
        if (collision == 1)
            return (1);
    }
    return (0);
}