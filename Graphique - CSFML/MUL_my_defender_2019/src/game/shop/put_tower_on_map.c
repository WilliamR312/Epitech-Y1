/*
** EPITECH PROJECT, 2020
** PUT_TOWER_ON_MAP
** File description:
** manage the action to put a tower on the map
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void put_tower(tower_t *tower, scene_game_t *game, \
sfMouseButtonEvent event)
{
    int id = game->shop.tower_hand.id_tower;

    tower->sprite = sfSprite_copy(game->shop.tower_on_shop[id].sprite);
    sfSprite_setScale(tower->sprite, (sfVector2f) {1, 1});
    tower->pos = (sfVector2f) {(event.x - game->shop.tower_on_shop[id]. \
    base.x), (event.y - game->shop.tower_on_shop[id].base.y)};
    sfSprite_setPosition(tower->sprite, tower->pos);
    tower->price = game->shop.tower_on_shop[id].price;
    tower->id_tower = game->shop.tower_on_shop[id].id_tower;
    tower->range = game->shop.tower_on_shop[id].range;
    tower->rect = game->shop.tower_on_shop[id].rect;
    tower->base = game->shop.tower_on_shop[id].base;
    tower->hit_p = game->shop.tower_on_shop[id].hit_p;
    tower->shoot_speed = game->shop.tower_on_shop[id].shoot_speed;
    tower->shoot_cloak = sfClock_create();
    tower->type = game->shop.tower_on_shop[id].type;
}

static tower_on_map_t *list_first_tower(scene_game_t *game, \
sfMouseButtonEvent event)
{
    tower_on_map_t *element = NULL;

    element = malloc(sizeof(tower_on_map_t));
    element->next = NULL;
    element->prev = NULL;
    put_tower(&element->tower, game, event);
    return (element);
}

static void clist_tower(tower_on_map_t **element, scene_game_t *game, \
sfMouseButtonEvent event)
{
    tower_on_map_t *new_element = NULL;

    new_element = malloc(sizeof(tower_on_map_t));
    put_tower(&new_element->tower, game, event);
    new_element->next = (*element);
    new_element->prev = (*element)->prev;
    (*element)->prev->next = new_element;
    (*element)->prev = new_element;
    (*element) = new_element;
}

static void put_tower_on_map(scene_game_t *game, sfMouseButtonEvent event)
{
    tower_on_map_t *element = NULL;

    sfSound_play(game->put_sound.sound);
    if (game->nb_tower_map == 0) {
        element = list_first_tower(game, event);
        element->next = element;
        element->prev = element;
        game->tower_on_map = element;
    } else {
        element = game->tower_on_map;
        clist_tower(&element, game, event);
        element = game->tower_on_map;
    }
    game->money -= \
    game->shop.tower_on_shop[game->shop.tower_hand.id_tower].price;
    game->nb_tower_map += 1;
}

void put_hand_tower(scene_game_t *game, sfMouseButtonEvent event)
{
    if (event.button == sfMouseLeft && game->shop.on_hand == 1) {
        put_tower_on_map(game, event);
        sfSprite_destroy(game->shop.tower_hand.sprite);
    }
    if (event.button == sfMouseRight)
        sfSprite_destroy(game->shop.tower_hand.sprite);
    game->shop.on_hand = 0;
}