/*
** EPITECH PROJECT, 2021
** collisions.c
** File description:
** collisions
*/

#include "../../include/prototypes.h"

int is_out_limit(s_window *window, s_player *player, int x_first)
{
    int p_col_l = (player->pos.x - x_first) / BLOCK_SIZE;
    int p_col_r = (player->pos.x + player->dim(player->sprite).width - x_first)
    / BLOCK_SIZE;
    int p_line_h = player->pos.y / BLOCK_SIZE - 1;
    int p_line_f = (player->pos.y + player->height) / BLOCK_SIZE - 1;

    if (p_line_f >= window->map->nb_line || p_col_r >= window->map->nb_col)
        return 1;
    if (p_line_h < 0 || p_col_l < 0)
        return 1;
    return 0;
}

int get_first_block(s_map *map)
{
    long long tmp = 9999999999999;

    for (int i = 0; i < map->nb_block; i++) {
        if (map->blocks[i]->pos.x < tmp)
            tmp = map->blocks[i]->pos.x;
    }
    return tmp;
}

int collisions(s_window *window, s_player *player)
{
    int x_first = window->map->first;
    int p_col_l = (player->pos.x - x_first) / BLOCK_SIZE;
    int p_col_r = (player->pos.x + player->dim(player->sprite).width - x_first)
    / BLOCK_SIZE;
    int p_line_h = player->pos.y / BLOCK_SIZE - 1;
    int p_line_f = (player->pos.y + player->height) / BLOCK_SIZE - 1;

    if (is_out_limit(window, player, x_first))
        return 1;
    if (is_in_str(window->map->grid[p_line_h + 1][p_col_l], " 0") &&
    is_in_str(window->map->grid[p_line_h + 1][p_col_r], " 0")) {
        if (!is_in_str(window->map->grid[p_line_f][p_col_l], " 0") ||
        !is_in_str(window->map->grid[p_line_f][p_col_r], " 0"))
            return 2;
    } else
        return 1;
    if (!is_in_str(window->map->grid[p_line_h][p_col_l], " 0") ||
    !is_in_str(window->map->grid[p_line_h][p_col_r], " 0"))
        return 1;
    return 0;
}
