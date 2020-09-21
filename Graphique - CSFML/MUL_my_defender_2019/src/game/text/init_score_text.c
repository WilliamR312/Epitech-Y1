/*
** EPITECH PROJECT, 2020
** INIT_SCORE_TEXT
** File description:
** init score text
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_score_str(core_t *core_d)
{
    sfVector2f pos_textbefore = {1600, 980};
    sfText *score_text = sfText_create();
    char *str_life = "SCORE: ";

    sfText_setCharacterSize(score_text, 35);
    sfText_setString(score_text, str_life);
    sfText_setColor(score_text, sfBlue);
    sfText_setFont(score_text, core_d->fonts_lib.font_01);
    sfText_setPosition(score_text, pos_textbefore);
    core_d->game_scene.score_text.text = score_text;
}

static void init_score_nbr(core_t *core_d)
{
    sfVector2f pos_text = {1750, 980};
    sfText *score = sfText_create();

    sfText_setCharacterSize(score, 35);
    sfText_setColor(score, sfBlue);
    sfText_setFont(score, core_d->fonts_lib.font_01);
    sfText_setPosition(score, pos_text);
    core_d->game_scene.score_text.valor = score;
}

void init_score_text(core_t *core_d)
{
    init_score_str(core_d);
    init_score_nbr(core_d);
}