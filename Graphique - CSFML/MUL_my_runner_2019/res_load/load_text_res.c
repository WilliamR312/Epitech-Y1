/*
** EPITECH PROJECT, 2020
** LOAD_TEXT_RES
** File description:
** manage loading of ressources used by text
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void load_score_text_res(text_t *text_d)
{
    text_d->text_1 = sfText_create();
    sfText_setFont(text_d->text_1, text_d->font);
    sfText_setString(text_d->text_1, "SCORE :");
    sfText_setFillColor(text_d->text_1, (sfColor){255, 0, 0, 255});
    sfText_setPosition(text_d->text_1, (sfVector2f){0, 0});
}

static void load_score_res(text_t *text_d)
{
    text_d->text_2 = sfText_create();
    sfText_setFont(text_d->text_2, text_d->font);
    sfText_setString(text_d->text_2, "0");
    sfText_setFillColor(text_d->text_2, (sfColor){255, 0, 0, 255});
    sfText_setPosition(text_d->text_2, (sfVector2f){230, 0});
}

static void result_res(text_t *text_d)
{
    text_d->result = sfText_create();
    sfText_setFont(text_d->result, text_d->font);
    sfText_setString(text_d->result, "RESULT");
    sfText_setFillColor(text_d->result, (sfColor){255, 0, 0, 255});
    sfText_setPosition(text_d->result, (sfVector2f){400, 100});
    sfText_setCharacterSize(text_d->result, 40);
}

static void press_space_res(text_t *text_d)
{
    text_d->restart = sfText_create();
    sfText_setFont(text_d->restart, text_d->font);
    sfText_setString(text_d->restart, "press {SPACE} to restart");
    sfText_setFillColor(text_d->restart, (sfColor){250, 255, 0, 255});
    sfText_setPosition(text_d->restart, (sfVector2f){320, 650});
    sfText_setCharacterSize(text_d->restart, 30);
}

void load_text_res(text_t *text_d)
{
    text_d->font = sfFont_createFromFile("./res/font/japan.TTF");
    load_score_text_res(text_d);
    load_score_res(text_d);
    result_res(text_d);
    press_space_res(text_d);
}