/*
** EPITECH PROJECT, 2020
** INIT_ALL
** File description:
** manage initialisation of all ressources
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_def.h"
#include "my.h"

static void init_background(core_t *core_d)
{
    core_d->game_scene.background.sprite = sfSprite_create();
    core_d->game_scene.background.texture = sfTexture_createFromFile \
    ("./src/res/backgrounds/map.png", NULL);
    sfSprite_setTexture(core_d->game_scene.background.sprite, \
    core_d->game_scene.background.texture, sfTrue);
}

static void init_game_sounds(scene_game_t *game)
{
    game->put_sound.sound_b = \
        sfSoundBuffer_createFromFile("./src/res/sounds/put_sound.ogg");
    game->put_sound.sound = sfSound_create();
    sfSound_setBuffer(game->put_sound.sound, game->put_sound.sound_b);
    game->game_music = \
        sfMusic_createFromFile("./src/res/sounds/game_music.ogg");
    sfMusic_setVolume(game->game_music, 20);
    sfMusic_play(game->game_music);
}

static void init_waves(core_t *core_d)
{
    core_d->game_scene.wave_data.actual_wave = 0;
    core_d->game_scene.wave_data.max_wave = 3;
    core_d->game_scene.wave_data.nb_enemy = 0;
    core_d->game_scene.wave_data.enemy_01 = sfTexture_createFromFile \
        ("./src/res/enemies/enemy_01.png", NULL);
    core_d->game_scene.wave_data.enemy_02 = sfTexture_createFromFile \
        ("./src/res/enemies/enemy_02.png", NULL);
}

void init_game_ressources(core_t *core_d)
{
    core_d->game_scene.nb_tower_map = 0;
    core_d->game_scene.money = 500;
    core_d->game_scene.life = 100;
    core_d->game_scene.score = 0;
    core_d->game_scene.nb_tower_map = 0;
    core_d->game_scene.pause = 0;
    init_text_game(core_d);
    init_background(core_d);
    init_waves(core_d);
    init_shop(core_d);
    init_all_direction_box(core_d);
    init_all_block_box(core_d);
    init_play_pause_button(core_d);
    init_game_sounds(&core_d->game_scene);
    init_menu_game(&core_d->game_scene.game_menu);
}