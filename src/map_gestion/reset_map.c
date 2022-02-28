/*
** EPITECH PROJECT, 2022
** reset_ap.
** File description:
** reset_map
*/

#include "../../include/prototypes.h"

void reset_pos_coin(s_map *map, int i, int col_p)
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
        reset_pos_coin(map, i, col_p);
        return;
    }
    map->coins[i]->struct_spr->pos.x = col * BLOCK_SIZE + 15;
    map->coins[i]->struct_spr->pos.y = line * BLOCK_SIZE + 75;
}

void reset_pos_enemies(s_map *map, int i, int col_p)
{
    int line  = -1;
    int col = 8 * i + rand() % 8 + col_p;

    for (int j = 0; map->grid[j]; j++) {
        if (map->grid[j][col] && !is_in_str(map->grid[j][col], " \n0")) {
            line = j;
            break;
        }
    }
    if (line == -1 || map->grid[line][col] != '1') {
        reset_pos_enemies(map, i, col_p);
        return;
    }
    map->enemies[i]->pos.x = col * BLOCK_SIZE;
    map->enemies[i]->pos.y = line * BLOCK_SIZE + 75;
}

void reset_enemies(s_map *map)
{
    int col_p = 0;

    for (int i = 0; map->grid[i]; i++) {
        for (int j = 0; map->grid[i][j]; j++)
            map->grid[i][j] == '0' ? col_p = j + 4 : 0;
    }
    for (int i = 0; i < map->nb_enemies; i++) {
        reset_pos_enemies(map, i, col_p);
        map->enemies[i]->image = rand() % 4;
    }
    for (int i = 0; i < map->nb_coins; i++) {
        reset_pos_coin(map, i, col_p);
        map->coins[i]->struct_spr->image = rand() % 4;
        map->coins[i]->is_touched = 0;
    }
}

int reset_map(s_window *window, s_player *player, int reset)
{
    if (reset == 2) {
        window->map = malloc(sizeof(s_map));
        window->map->grid = my_dbstrset(8);
        window->map->nb_line = 7;
        window->map->nb_col = 0;
        if (get_map(window->path, window->map, player) == 84) {
            window->error = 84;
            return 84;
        }
    }
    if (reset == 1) {
        for (int i = 0; i < window->map->nb_block; i++)
            window->map->blocks[i]->pos.x += ABS(window->map->first);
        player->pos = (sfVector2f) {0, 0};
        get_pos_player(window->map, player, 0);
        reset_enemies(window->map);
    }
    (reset == 1 || reset == 2) ? window->map->first = 0 : 0;
    (reset == 1 || reset == 2) ? window->bonus = 0 : 0;
    return 0;
}
