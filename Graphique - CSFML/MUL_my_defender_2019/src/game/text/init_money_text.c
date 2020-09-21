/*
** EPITECH PROJECT, 2020
** INIT_MONEY_TEXT
** File description:
** init money text
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_money_str(core_t *core_d)
{
    sfVector2f pos_textbefore = {1600, 940};
    sfText *money_text = sfText_create();
    char *str_money = "MONEY: ";

    sfText_setCharacterSize(money_text, 35);
    sfText_setString(money_text, str_money);
    sfText_setColor(money_text, sfBlue);
    sfText_setFont(money_text, core_d->fonts_lib.font_01);
    sfText_setPosition(money_text, pos_textbefore);
    core_d->game_scene.money_text.text = money_text;
}

static void init_money_nbr(core_t *core_d)
{
    sfVector2f pos_text = {1750, 940};
    sfText *money = sfText_create();

    sfText_setCharacterSize(money, 35);
    sfText_setColor(money, sfBlue);
    sfText_setFont(money, core_d->fonts_lib.font_01);
    sfText_setPosition(money, pos_text);
    core_d->game_scene.money_text.valor = money;
}

void init_money_text(core_t *core_d)
{
    init_money_str(core_d);
    init_money_nbr(core_d);
}