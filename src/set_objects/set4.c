/*
** EPITECH PROJECT, 2021
** set4.c
** File description:
** set4
*/

#include "../../include/prototypes.h"

int set_sounds(s_window *window)
{
    window->sounds = malloc(sizeof(s_sound) * 6);

    for (int i = 0; i < 6; i++) {
        window->sounds[i] = malloc(sizeof(s_sound));
        window->sounds[i]->sound = sfSound_create();
    }
    window->sounds[0]->buffer = sfSoundBuffer_createFromFile(PATH_SOUND_DEAD);
    window->sounds[1]->buffer = sfSoundBuffer_createFromFile(PATH_SOUND_JUMP);
    window->sounds[2]->buffer = sfSoundBuffer_createFromFile(PATH_SOUND_BONUS);
    window->sounds[3]->buffer = sfSoundBuffer_createFromFile(PATH_SOUND_MALUS);
    window->sounds[4]->buffer = sfSoundBuffer_createFromFile(PATH_SOUND_LAND);
    window->sounds[5]->buffer = sfSoundBuffer_createFromFile(PATH_SOUND_WIN);
    for (int i = 0; i < 6; i++) {
        if (window->sounds[i]->buffer == 0)
            return 84;
        sfSound_setBuffer(window->sounds[i]->sound, window->sounds[i]->buffer);
        sfSound_setVolume(window->sounds[i]->sound, VOLUME);
    }
}

void set_image_coin(s_coin *coin, int col, int line)
{
    coin->is_touched = 0;
    coin->is_bonus = rand() % 2;
    coin->struct_spr = set_struct_sprite(coin->is_bonus ? PATH_COIN_Y
    : PATH_COIN_R , col * BLOCK_SIZE + 15, line * BLOCK_SIZE + 75);
    coin->struct_spr->sprite = set_sprite(coin->is_bonus ? PATH_COIN_Y
    : PATH_COIN_R, coin->struct_spr->pos.x, coin->struct_spr->pos.y);
    sfSprite_setScale(coin->struct_spr->sprite, enemy_scale);
}

void find_pos_coin(s_map *map, int i, int col_p)
{
    int line = -1;
    int col = 8 * i + rand() % 8 + col_p;

    for (int j = 0; map->grid[j]; j++) {
        if (map->grid[j][col] && !is_in_str(map->grid[j][col], " \n0")) {
            line = j;
            break;
        }
    }
    if (line == -1 || map->grid[line][col] != '1') {
        find_pos_coin(map, i, col_p);
        return;
    }
    set_image_coin(map->coins[i], col, line);
}

void set_coins(s_map *map)
{
    int col_p = 0;

    for (int i = 0; map->grid[i]; i++) {
        for (int j = 0; map->grid[i][j]; j++)
            map->grid[i][j] == '0' ? col_p = j + 4 : 0;
    }
    map->nb_coins = (map->nb_col - col_p) / 8;
    map->coins = malloc(sizeof(s_coin *) * map->nb_coins);
    for (int i = 0; i < map->nb_coins; i++) {
        map->coins[i] = malloc(sizeof(s_coin));
        find_pos_coin(map, i, col_p);
        map->coins[i]->struct_spr->image = rand() % 4;
    }
}
