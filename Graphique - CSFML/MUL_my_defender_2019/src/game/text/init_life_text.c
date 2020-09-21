/*
** EPITECH PROJECT, 2020
** INIT_LIFE_TEXT
** File description:
** init life text
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_life_str(core_t *core_d)
{
    sfVector2f pos_textbefore = {1600, 900};
    sfText *life_text = sfText_create();
    char *str_life = "LIFE: ";

    sfText_setCharacterSize(life_text, 35);
    sfText_setString(life_text, str_life);
    sfText_setColor(life_text, sfBlue);
    sfText_setFont(life_text, core_d->fonts_lib.font_01);
    sfText_setPosition(life_text, pos_textbefore);
    core_d->game_scene.life_text.text = life_text;
}

static void init_life_nbr(core_t *core_d)
{
    sfVector2f pos_text = {1700, 900};
    sfText *life = sfText_create();

    sfText_setCharacterSize(life, 35);
    sfText_setColor(life, sfBlue);
    sfText_setFont(life, core_d->fonts_lib.font_01);
    sfText_setPosition(life, pos_text);
    core_d->game_scene.life_text.valor = life;
}

void init_life_text(core_t *core_d)
{
    init_life_str(core_d);
    init_life_nbr(core_d);
}