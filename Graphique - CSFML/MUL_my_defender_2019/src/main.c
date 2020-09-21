/*
** EPITECH PROJECT, 2020
** MAIN
** File description:
** Main for my_runner
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "scene.h"
#include "my_def.h"
#include "my.h"

static void create_window(window_t *window_d)
{
    window_d->video_mode.width = 1920;
    window_d->video_mode.height = 1080;
    window_d->video_mode.bitsPerPixel = 32;
    window_d->window = sfRenderWindow_create(window_d->video_mode, \
    "[= STAR WARS DEFENDER =]", sfClose, NULL);
    window_d->icon.icon_img = sfImage_createFromFile("./src/res/icon.png");
    window_d->icon.icon_uint = sfImage_getPixelsPtr\
    (window_d->icon.icon_img);
    sfRenderWindow_setIcon(window_d->window, 600, 822, \
    window_d->icon.icon_uint);
}

static void all_scene(core_t *core_d)
{
    for (int cursor = 0; cursor <= 5 && core_d->id_scene != 0; cursor++) {
        if (cursor == 5)
            cursor = 0;
        if (scene_tab[cursor].id_scene == core_d->id_scene)
            scene_tab[cursor].scene(core_d);
    }
}

int main(void)
{
    core_t core_d;

    create_window(&core_d.window_d);
    core_d.id_scene = 1;
    core_d.id_prev_scene = 1;
    sfRenderWindow_setFramerateLimit(core_d.window_d.window, 120);
    all_scene(&core_d);
    sfRenderWindow_destroy(core_d.window_d.window);
    return (0);
}