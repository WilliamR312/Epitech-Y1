/*
** EPITECH PROJECT, 2020
** INIT_RESULT
** File description:
** init of the result resources
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_score_str(core_t *core_d)
{
    sfVector2f pos_textbefore = {950, 250};
    char *str_score = "YOUR SCORE : ";

    core_d->result_scene.score_text.text = sfText_create();
    sfText_setFont(core_d->result_scene.score_text.text, \
        core_d->fonts_lib.font_01);
    sfText_setCharacterSize(core_d->result_scene.score_text.text, 40);
    sfText_setString(core_d->result_scene.score_text.text, str_score);
    sfText_setColor(core_d->result_scene.score_text.text, sfWhite);
    sfText_setPosition(core_d->result_scene.score_text.text, pos_textbefore);
}

static void init_score_nbr(core_t *core_d)
{
    sfVector2f pos_textbefore = {1240, 250};

    core_d->result_scene.score_text.valor = sfText_create();
    sfText_setFont(core_d->result_scene.score_text.valor, \
        core_d->fonts_lib.font_01);
    sfText_setCharacterSize(core_d->result_scene.score_text.valor, 40);
    sfText_setColor(core_d->result_scene.score_text.valor, sfWhite);
    sfText_setPosition(core_d->result_scene.score_text.valor, pos_textbefore);
}

static void init_final_score_text(core_t *core_d)
{
    init_score_str(core_d);
    init_score_nbr(core_d);
}

void init_result_ressources(core_t *core_d)
{
    core_d->result_scene.score = core_d->game_scene.score;
    if (core_d->game_scene.life > 0) {
        core_d->result_scene.result_sprite = sfSprite_create();
        core_d->result_scene.result_text = sfTexture_createFromFile \
            ("./src/res/backgrounds/victory.png", NULL);
        sfSprite_setTexture(core_d->result_scene.result_sprite, \
        core_d->result_scene.result_text, sfTrue);
    } else {
        core_d->result_scene.result_sprite = sfSprite_create();
        core_d->result_scene.result_text = sfTexture_createFromFile \
            ("./src/res/backgrounds/loose.png", NULL);
        sfSprite_setTexture(core_d->result_scene.result_sprite, \
        core_d->result_scene.result_text, sfTrue);
    }
    init_final_score_text(core_d);
}