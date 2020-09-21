/*
** EPITECH PROJECT, 2020
** CHECK_SHOP_ACTIONS
** File description:
** check shop actions
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void get_tower_info(shop_t *shop, int tower_tab)
{
    sfColor color = {220, 220, 255, 220};

    shop->tower_hand.sprite = \
    sfSprite_copy(shop->tower_on_shop[tower_tab].sprite);
    sfSprite_setScale(shop->tower_hand.sprite, \
    (sfVector2f) {1, 1});
    sfSprite_setColor(shop->tower_hand.sprite, color);
    shop->tower_hand.base = shop->tower_on_shop[tower_tab].base;
    shop->tower_hand.range = shop->tower_on_shop[tower_tab].range;
    shop->tower_hand.rect = shop->tower_on_shop[tower_tab].rect;
    shop->tower_hand.id_tower = shop->tower_on_shop[tower_tab].id_tower;
}

static void get_hand_tower(shop_t *shop, int tower_tab)
{
    if (shop->on_hand == 0) {
        get_tower_info(shop, tower_tab);
        shop->on_hand = 1;
    } else {
        shop->on_hand = 0;
    }
}

void check_shop_actions(scene_game_t *game, sfMouseButtonEvent event)
{
    sfFloatRect frect = {0, 0, 0, 0};

    if (game->pause == 1)
        return;
    for (int i = 0; i < game->shop.nb_towers; i++) {
        frect = sfSprite_getGlobalBounds(game->shop.tower_on_shop[i].sprite);
        if (sfFloatRect_contains(&frect, event.x, event.y) == sfTrue && \
        event.button == sfMouseLeft && game->shop.on_hand == 0 && \
        game->shop.tower_on_shop[i].price <= game->money) {
            get_hand_tower(&game->shop, i);
            return;
        } else if (game->shop.on_hand != 0) {
            put_hand_tower(game, event);
        }
    }
}