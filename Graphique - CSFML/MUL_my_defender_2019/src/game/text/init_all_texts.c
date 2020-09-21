/*
** EPITECH PROJECT, 2020
** INIT_ALL_TEXT
** File description:
** init all text res
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_fonts_lib(fonts_lib_t *fonts_lib)
{
    fonts_lib->font_01 = sfFont_createFromFile("./src/res/fonts/font.ttf");
}

void init_text_game(core_t *core_d)
{
    init_fonts_lib(&core_d->fonts_lib);
    init_money_text(core_d);
    init_life_text(core_d);
    init_score_text(core_d);
}