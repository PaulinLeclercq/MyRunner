/*
** EPITECH PROJECT, 2021
** get_map.c
** File description:
** get_map
*/

#include "../../include/prototypes.h"

void place_player(s_player *player, s_map *map, int i, int j)
{
    player->pos.x = BLOCK_SIZE * j;
    player->pos.y = BLOCK_SIZE * i - 35;
    sfSprite_setPosition(player->sprite, player->pos);
}

void get_pos_player(s_map *map, s_player *player, int reset_blocks)
{
    for (int i = 0; i < map->nb_line; i++) {
        for (int j = 0; map->grid[i][j]; j++)
            map->grid[i][j] == '0' ? place_player(player, map, i + 1, j) : 0;
    }
    reset_blocks ? set_blocks(map) : 0;
}

int get_nb_line(int *file, s_map *map)
{
    int size = 0;
    char *nb_line = my_strset(3);
    char *buffer = my_strset(20);

    map->nb_col = 0;
    for (; *buffer != '\n'; nb_line[my_strlen(nb_line)] = buffer[0])
        size = read((*file), buffer, 1);
    return str_to_long(nb_line);
}

int get_size_file(char *path, s_map *map)
{
    int i = 0;
    int size = 1;
    int file = open(path, O_RDONLY);
    char *buffer = my_strset(2);

    if (try_open(path) == 84)
        return 0;
    while (size) {
        size = read(file, buffer, 1);
        if (buffer[0] >= '0' && buffer[0] <= '9')
            i++;
    }
    close(file);
    map->blocks = malloc(sizeof(s_sprite *) * (i + 1));
    return i + 1;
}

int get_map(char *path, s_map *map, s_player *player)
{
    int size = 1;
    int file = open(path, O_RDONLY);

    if (try_open(path) == 84 || error_map(path) == 84)
        return 84;
    for (int i = 0; i < 7; i++) {
        map->grid[i] = my_strset(get_size_file(path, map));
        do
            size = read(file, map->grid[i] + my_strlen(map->grid[i]), 1);
        while (map->grid[i][my_strlen(map->grid[i]) - 1] != '\n' && size == 1);
        size == 1 ? map->grid[i][my_strlen(map->grid[i]) - 1] = 0 : 0;
        if (my_strlen(map->grid[i]) > map->nb_col)
            map->nb_col = my_strlen(map->grid[i]);
    }
    if (error_enemies(map) == 84)
        return 84;
    get_pos_player(map, player, 1);
    set_enemies(map);
    close(file);
    return 0;
}
