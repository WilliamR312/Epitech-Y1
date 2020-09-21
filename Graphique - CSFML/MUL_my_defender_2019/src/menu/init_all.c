/*
** EPITECH PROJECT, 2020
** MENU
** File description:
** Main for menu
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_background(core_t *core_d)
{
    core_d->menu_scene.background.sprite = sfSprite_create();
    core_d->menu_scene.background.texture = sfTexture_createFromFile \
    ("./src/res/backgrounds/menu_back.png", NULL);
    sfSprite_setTexture(core_d->menu_scene.background.sprite, \
    core_d->menu_scene.background.texture, sfTrue);
}

void init_menu_ressources(core_t *core_d)
{
    init_menu_buttons(core_d);
    init_background(core_d);
    init_menu_sounds(&core_d->menu_scene);
}