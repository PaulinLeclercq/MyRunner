/*
** EPITECH PROJECT, 2021
** anim_player.c
** File description:
** anim_player
*/

#include "../../include/prototypes.h"

void anim_enemies(s_map *map)
{
    for (int i = 0; i < map->nb_enemies; i++) {
        if (map->enemies[i]->image < 3)
            map->enemies[i]->image += 1;
        else
            map->enemies[i]->image = 0;
        sfSprite_setTextureRect(map->enemies[i]->sprite,
        int_bandit[map->enemies[i]->image]);
    }
    for (int i = 0; i < map->nb_coins; i++) {
        if (map->coins[i]->struct_spr->image < 4)
            map->coins[i]->struct_spr->image += 1;
        else
            map->coins[i]->struct_spr->image = 0;
        sfSprite_setTextureRect(map->coins[i]->struct_spr->sprite,
        int_coin[map->coins[i]->struct_spr->image]);
    }
}

void move_player(s_player *player)
{
    int end = player->path[31] == 'r' ? 7 : 1;

    if (player->image >= end)
        player->image = 0;
    else
        player->image++;
    sfSprite_setTextureRect(player->sprite,
    (end == 7 ? int_player_r : int_player_j)[player->image]);
}

void jump_player(s_window *window, s_player *player)
{
    int coll;

    player->pos.y -= player->jump;
    coll = collisions(window, player);
    if (coll == 2) {
        to_run(player);
        player->is_jump = 0;
        player->jump = PLAYER_JUMP;
        player->pos.y = ((int) (player->pos.y) / BLOCK_SIZE + 1) *
        BLOCK_SIZE - 35 - (coll == 1 ? BLOCK_SIZE : 0);
        sfSound_play(window->sounds[4]->sound);
    } else if (coll == 0)
        player->jump -= 1;
    else
        return;
    player->height = (coll > 0) ? PLAYER_HEIGHT : PLAYER_HEIGHT_J;
}

void player_gravity(s_window *window, s_player *player)
{
    int coll;

    if (player->is_jump)
        return;
    player->pos.y += 10;
    coll = collisions(window, player);
    if (coll <= 1) {
        to_jump(player);
        player->is_fall = 1;
    } else if (player->is_fall) {
        to_run(player);
        player->is_fall = 0;
        player->pos.y = ((int) (player->pos.y) / BLOCK_SIZE + 1) *
        BLOCK_SIZE - 35 - (coll == 1 ? BLOCK_SIZE : 0);
        sfSound_play(window->sounds[4]->sound);
    } else
        player->pos.y -= 10;
}

void anim_player(s_window *window, s_clock **clocks, s_player *player)
{
    if (get_seconds(clocks[0]->g_clock) > 0.016) {
        move_bg(window);
        move_enemies(window->map);
        player_gravity(window, player);
        sfClock_restart(clocks[0]->g_clock);
    }
    if (get_seconds(clocks[1]->g_clock) > 0.06) {
        move_player(player);
        sfClock_restart(clocks[1]->g_clock);
    }
    if (get_seconds(clocks[3]->g_clock) > 0.1) {
        anim_enemies(window->map);
        sfClock_restart(clocks[3]->g_clock);
    }
    if (get_seconds(clocks[2]->g_clock) > 0.016) {
        if (player->is_jump && !player->is_fall)
            jump_player(window, player);
        sfClock_restart(clocks[2]->g_clock);
    }
    sfSprite_setPosition(player->sprite, player->pos);
}
