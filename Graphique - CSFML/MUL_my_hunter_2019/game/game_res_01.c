/*
** EPITECH PROJECT, 2019
** GAME_RES
** File description:
** game element resources
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/my_hunter.h"
#include "../include/my.h"

void game_sound_res(game_01_t *game_01_d)
{
    game_01_d->music_p.music = sfMusic_createFromFile\
    ("res/sound/game_music.ogg");
    game_01_d->shoot_p.interract_mem = \
    sfSoundBuffer_createFromFile("res/sound/shoot_01.ogg");
    game_01_d->shoot_p.interract_sound = sfSound_create();
    sfSound_setBuffer(game_01_d->shoot_p.interract_sound,\
    game_01_d->shoot_p.interract_mem);
    sfSound_setVolume(game_01_d->shoot_p.interract_sound, 10);
    game_01_d->explosion_p.interract_mem = \
    sfSoundBuffer_createFromFile("res/sound/explosion_01.ogg");
    game_01_d->explosion_p.interract_sound = sfSound_create();
    sfSound_setBuffer(game_01_d->explosion_p.interract_sound,\
    game_01_d->explosion_p.interract_mem);
    sfSound_setVolume(game_01_d->explosion_p.interract_sound, 10);
}

void game_sky_res(game_01_t *game_01_d, window_t window_d)
{
    game_01_d->texture_sky = sfTexture_createFromFile\
    ("res/sky_background.png", NULL);
    game_01_d->sprite_sky = sfSprite_create();
    game_01_d->rect = (sfIntRect){0, 0, window_d.width, window_d.height};;
    sfSprite_setTexture(game_01_d->sprite_sky, game_01_d->texture_sky, sfTrue);
    sfSprite_setTextureRect(game_01_d->sprite_sky, game_01_d->rect);
}

void game_field_res(game_01_t *game_01_d, window_t window_d)
{
    game_01_d->texture_field = sfTexture_createFromFile\
    ("res/background_01.png", NULL);
    game_01_d->sprite_field = sfSprite_create();
    game_01_d->rect = (sfIntRect){0, 0, window_d.width, window_d.height};
    sfSprite_setTexture(game_01_d->sprite_field,\
    game_01_d->texture_field, sfTrue);
    sfSprite_setTextureRect(game_01_d->sprite_field, game_01_d->rect);
}

void game_hud_rebel_score_res(game_01_t *game_01_d)
{
    sfVector2f rebel_score_pos = {10, 750};

    game_01_d->rebel_score.texture = sfTexture_createFromFile\
    ("res/rebel_score.png", NULL);
    game_01_d->rebel_score.sprite = sfSprite_create();
    game_01_d->rebel_score.rect = (sfIntRect){0, 0, 430, 42};
    sfSprite_setTexture(game_01_d->rebel_score.sprite,\
    game_01_d->rebel_score.texture, sfTrue);
    sfSprite_setTextureRect(game_01_d->rebel_score.sprite,\
    game_01_d->rebel_score.rect);
    sfSprite_setPosition(game_01_d->rebel_score.sprite, rebel_score_pos);
}

void game_hud_empire_score_res(game_01_t *game_01_d)
{
    sfVector2f empire_score_pos = {1120, 750};

    game_01_d->empire_score.texture = sfTexture_createFromFile\
    ("res/empire_score.png", NULL);
    game_01_d->empire_score.sprite = sfSprite_create();
    game_01_d->empire_score.rect = (sfIntRect){0, 0, 136, 42};
    sfSprite_setTexture(game_01_d->empire_score.sprite,\
    game_01_d->empire_score.texture, sfTrue);
    sfSprite_setTextureRect(game_01_d->empire_score.sprite,\
    game_01_d->empire_score.rect);
    sfSprite_setPosition(game_01_d->empire_score.sprite, empire_score_pos);
}