/*
** EPITECH PROJECT, 2020
** FREE_ALL
** File description:
** manage free of all ressouces
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

void free_game_core(scene_game_t *game)
{
    free_enemy_wave(&game->wave_data);
    free_towers_on_map(game);
    free_shop(&game->shop);
    free_box(game);
    free_game_menu(&game->game_menu, &game->pause_b);
    sfSprite_destroy(game->background.sprite);
    sfTexture_destroy(game->background.texture);
    sfText_destroy(game->life_text.valor);
    sfText_destroy(game->life_text.text);
    sfText_destroy(game->money_text.text);
    sfText_destroy(game->money_text.valor);
    if (sfSound_getStatus(game->put_sound.sound) != sfStopped)
        sfSound_stop(game->put_sound.sound);
    sfSound_destroy(game->put_sound.sound);
    sfSoundBuffer_destroy(game->put_sound.sound_b);
    if (sfMusic_getStatus(game->game_music) != sfStopped)
        sfMusic_stop(game->game_music);
    sfMusic_destroy(game->game_music);
}