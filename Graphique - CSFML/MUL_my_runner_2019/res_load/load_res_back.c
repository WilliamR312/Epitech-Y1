/*
** EPITECH PROJECT, 2020
** LOAD_RES_BACK
** File description:
** load ressource for background
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void load_background(p_element_t *p_back, char *pathname,\
unsigned parallax)
{
    p_back->texture = sfTexture_createFromFile(pathname, NULL);
    p_back->sprite = sfSprite_create();
    sfSprite_setTexture(p_back->sprite, p_back->texture, sfTrue);
    if (parallax == 1)
        p_back->clock = sfClock_create();
    else
        p_back->clock = NULL;
}

void load_background_res(background_t *back_d)
{
    load_background(&back_d->back_00,"./res/sky.png", 0);
    load_background(&back_d->back_01,"./res/cloud.png", 1);
    load_background(&back_d->back_02,"./res/trees.png", 1);
    load_background(&back_d->back_03,"./res/ground.png", 1);
}