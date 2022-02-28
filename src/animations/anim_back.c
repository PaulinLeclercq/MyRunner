/*
** EPITECH PROJECT, 2021
** anim_player.c
** File description:
** anim_player
*/

#include "../../include/prototypes.h"

void to_jump(s_player *player)
{
    player->image = 0;
    player->path = PATH_PLAYER_J;
    player->height = PLAYER_HEIGHT_J;
    sfSprite_setTexture(player->sprite, player->jump_text[player->is_red]
    , sfTrue);
    sfSprite_setTextureRect(player->sprite, int_player_j[player->image]);
    sfSprite_setScale(player->sprite, player->scale);
}

void to_run(s_player *player)
{
    player->image = 0;
    player->path = PATH_PLAYER_R;
    player->height = PLAYER_HEIGHT;
    sfSprite_setTexture(player->sprite, player->run_text[player->is_red]
    , sfTrue);
    sfSprite_setTextureRect(player->sprite, int_player_r[player->image]);
    sfSprite_setScale(player->sprite, player->scale);

}

void move_enemies(s_map *map)
{
    for (int i = 0; i < map->nb_enemies; i++) {
        map->enemies[i]->pos.x -= 6;
        sfSprite_setPosition(map->enemies[i]->sprite
        , map->enemies[i]->pos);
    }
    for (int i = 0; i < map->nb_coins; i++) {
        map->coins[i]->struct_spr->pos.x -= 6;
        sfSprite_setPosition(map->coins[i]->struct_spr->sprite
        , map->coins[i]->struct_spr->pos);
    }
}

void move_bg(s_window *window)
{
    for (int i = 0; i < 4; i++) {
        if (window->parall[i]->pos.x <= -1920)
            window->parall[i]->pos.x = -7 + i;
        else
            window->parall[i]->pos.x -= (6 - i);
        sfSprite_setPosition(window->parall[i]->sprite
        , window->parall[i]->pos);
    }
    for (int i = 0; i < window->map->nb_block; i++) {
        window->map->blocks[i]->pos.x -= 6;
        sfSprite_setPosition(window->map->blocks[i]->sprite
        , window->map->blocks[i]->pos);
    }
    window->map->first -= 6;
}
