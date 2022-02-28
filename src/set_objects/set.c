/*
** EPITECH PROJECT, 2021
** set.c
** File description:
** set
*/

#include "../../include/prototypes.h"

void draw_block(s_map *map, int nb, int i, int j)
{
    map->blocks[map->nb_block] = set_struct_sprite(path_block[nb]
    , BLOCK_SIZE * j, BLOCK_SIZE * i);
    sfSprite_setScale(map->blocks[map->nb_block]->sprite, block_scale);
    if (map->grid[i - 1][j] == '4' || map->grid[i - 1][j] == '6') {
        sfSprite_scale(map->blocks[map->nb_block]->sprite, reverse);
        map->blocks[map->nb_block]->pos.x += BLOCK_SIZE;
    }
    if (map->grid[i - 1][j] == '8') {
        sfSprite_rotate(map->blocks[map->nb_block]->sprite, 90);
        map->blocks[map->nb_block]->pos.x += BLOCK_SIZE;
    }
    if (map->grid[i - 1][j] == '7') {
        sfSprite_rotate(map->blocks[map->nb_block]->sprite, -90);
        map->blocks[map->nb_block]->pos.y += BLOCK_SIZE;
    }
    sfSprite_setPosition(map->blocks[map->nb_block]->sprite
    , map->blocks[map->nb_block]->pos);
    map->nb_block++;
}

void set_blocks(s_map *map)
{
    map->first = 0;
    map->nb_block = 0;
    for (int i = 0; i < map->nb_line; i++) {
        for (int j = 0; map->grid[i][j]; j++) {
            map->grid[i][j] == '1' ? draw_block(map, 1, i + 1, j) : 0;
            map->grid[i][j] == '2' ? draw_block(map, 0, i + 1, j) : 0;
            map->grid[i][j] == '3' ? draw_block(map, 2, i + 1, j) : 0;
            map->grid[i][j] == '4' ? draw_block(map, 2, i + 1, j) : 0;
            map->grid[i][j] == '5' ? draw_block(map, 3, i + 1, j) : 0;
            map->grid[i][j] == '6' ? draw_block(map, 3, i + 1, j) : 0;
            map->grid[i][j] == '7' ? draw_block(map, 1, i + 1, j) : 0;
            map->grid[i][j] == '8' ? draw_block(map, 1, i + 1, j) : 0;
        }
    }
}

sfSprite *set_sprite(char const *path, int x, int y)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, vector);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

s_clock **set_clock(int nb)
{
    s_clock **clocks = malloc(sizeof(s_clock *) * (nb + 1));

    for (int i = 0; i < nb; i++) {
        s_clock *game_clock = malloc(sizeof(s_clock));
        game_clock->g_clock = sfClock_create();
        game_clock->get_sec = get_seconds;
        clocks[i] = game_clock;
    }
    return clocks;
}

int set_music(s_window *window)
{
    window->music = malloc(sizeof(sfMusic *) * 2);
    window->music[0] = sfMusic_createFromFile(PATH_MUSIC_M);
    window->music[1] = sfMusic_createFromFile(PATH_MUSIC_G);
    if (window->music[0] == NULL || window->music[1] == NULL)
        return 84;
    sfMusic_setLoop(window->music[0], sfTrue);
    sfMusic_setLoop(window->music[1], sfTrue);
    sfMusic_setVolume(window->music[0], VOLUME);
    sfMusic_setVolume(window->music[1], VOLUME);
    return 0;
}
