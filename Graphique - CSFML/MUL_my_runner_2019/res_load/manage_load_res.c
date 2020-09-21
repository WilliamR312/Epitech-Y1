/*
** EPITECH PROJECT, 2020
** MANAGE_LOAD_RES
** File description:
** manage loading of ressources
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void create_window(window_t *window_d)
{
    window_d->video_mode.width = 1280;
    window_d->video_mode.height = 800;
    window_d->video_mode.bitsPerPixel = 32;
    window_d->window = sfRenderWindow_create(window_d->video_mode,\
    "~ Spirit ~", sfClose, NULL);
    window_d->icon_d.icon_image = sfImage_createFromFile("./res/bal.png");
    window_d->icon_d.icon_uint = sfImage_getPixelsPtr\
    (window_d->icon_d.icon_image);
    sfRenderWindow_setIcon(window_d->window, 89, 152,\
    window_d->icon_d.icon_uint);
}

void load_ressource(core_t *core_d)
{
    core_d->score_d.score_int = 0;
    core_d->score_d.score_str = NULL;
    core_d->score_d.clock_score = sfClock_create();
    create_window(&core_d->window_p);
    load_background_res(&core_d->background);
    load_char_res(&core_d->character_data);
    load_sound_res(&core_d->all_sounds_d);
    load_map_res(&core_d->map_d);
    load_text_res(&core_d->text_d);
}