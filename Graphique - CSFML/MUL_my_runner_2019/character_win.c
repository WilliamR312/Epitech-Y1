/*
** EPITECH PROJECT, 2020
** CHAR_MANAGEMENT
** File description:
** manage character
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

void character_win(core_t *core_d)
{
    sfSprite_setPosition(core_d->character_data.character.sprite,\
    (sfVector2f){100, 700 - 118});
    sfSprite_setTextureRect(core_d->character_data.character.sprite,\
    (sfIntRect){644, 0, 92, 118});
    sfRenderWindow_drawSprite(core_d->window_p.window,\
    core_d->character_data.character.sprite, NULL);
}