/*
** EPITECH PROJECT, 2020
** MAP_LOAD
** File description:
** load map for map_load
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void free_back_res(core_t *core_d)
{
    sfSprite_destroy(core_d->background.back_00.sprite);
    sfSprite_destroy(core_d->background.back_01.sprite);
    sfSprite_destroy(core_d->background.back_02.sprite);
    sfSprite_destroy(core_d->background.back_03.sprite);
    sfClock_destroy(core_d->background.back_00.clock);
    sfClock_destroy(core_d->background.back_01.clock);
    sfClock_destroy(core_d->background.back_02.clock);
    sfClock_destroy(core_d->background.back_03.clock);
    sfTexture_destroy(core_d->background.back_00.texture);
    sfTexture_destroy(core_d->background.back_01.texture);
    sfTexture_destroy(core_d->background.back_02.texture);
    sfTexture_destroy(core_d->background.back_03.texture);
}

static void free_map_res(core_t *core_d)
{
    sfSprite_destroy(core_d->map_d.block_1.sprite);
    sfSprite_destroy(core_d->map_d.block_2.sprite);
    sfTexture_destroy(core_d->map_d.block_1.texture);
    sfTexture_destroy(core_d->map_d.block_2.texture);
    for (int i = 0; i < core_d->map_d.nb_line; i++)
        free(core_d->map_d.map[i]);
    free(core_d->map_d.map);
}

static void free_player_res(core_t *core_d)
{
    sfSprite_destroy(core_d->character_data.character.sprite);
    sfTexture_destroy(core_d->character_data.character.texture);
    if (core_d->character_data.state != 2 && core_d->character_data.state != 3)
        sfClock_destroy(core_d->character_data.clock_jump);
    sfClock_destroy(core_d->character_data.clock_anim);
    sfSprite_destroy(core_d->character_data.dead_char.sprite);
    sfTexture_destroy(core_d->character_data.dead_char.texture);
}

void exit_free_res(core_t *core_d)
{
    sfRenderWindow_clear(core_d->window_p.window, sfBlue);
    sfMusic_destroy(core_d->all_sounds_d.music_1);
    sfSound_destroy(core_d->all_sounds_d.sound_data.sound);
    sfSoundBuffer_destroy(core_d->all_sounds_d.sound_data.sound_b);
    sfImage_destroy(core_d->window_p.icon_d.icon_image);
    sfClock_destroy(core_d->map_d.clock);
    sfText_destroy(core_d->text_d.text_1);
    sfText_destroy(core_d->text_d.text_2);
    sfText_destroy(core_d->text_d.restart);
    sfText_destroy(core_d->text_d.result);
    sfFont_destroy(core_d->text_d.font);
    sfClock_destroy(core_d->score_d.clock_score);
    sfRenderWindow_destroy(core_d->window_p.window);
}