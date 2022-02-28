/*
** EPITECH PROJECT, 2021
** set2.c
** File description:
** set2
*/

#include "../../include/prototypes.h"

sfFloatRect getdim(sfSprite *sprite)
{
    return sfSprite_getGlobalBounds(sprite);
}

s_sprite *set_struct_sprite(char const *path, int x, int y)
{
    s_sprite *struc = malloc(sizeof(s_sprite));
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfVector2f vector;

    struc->sprite = sfSprite_create();
    struc->pos.x = x;
    struc->pos.y = y;
    struc->dim = getdim;
    struc->scale = scale;
    struc->texture = texture;
    struc->image = rand() % 4;
    sfSprite_setPosition(struc->sprite, struc->pos);
    sfSprite_setTexture(struc->sprite, struc->texture, sfFalse);
    if (is_in_str('x', path) + is_in_str('-', path) == 0)
        sfSprite_setScale(struc->sprite, struc->scale);
    return struc;
}

void set_color_player(s_player *player)
{
    player->path = PATH_PLAYER_R;
    player->run_text = malloc(sizeof(sfTexture *) * 2);
    player->jump_text = malloc(sizeof(sfTexture *) * 2);
    player->run_text[0] = sfTexture_createFromFile(PATH_PLAYER_R, NULL);
    player->jump_text[0] = sfTexture_createFromFile(PATH_PLAYER_J, NULL);
    player->run_text[1] = sfTexture_createFromFile(PATH_PLAYER_R_RED, NULL);
    player->jump_text[1] = sfTexture_createFromFile(PATH_PLAYER_J_RED, NULL);
}

s_player *set_player(int x, int y)
{
    s_player *player = malloc(sizeof(s_player));

    player->jump = PLAYER_JUMP;
    player->height = PLAYER_HEIGHT;
    player->dim = getdim;
    player->image = 0;
    player->pos.x = x;
    player->pos.y = y;
    player->is_red = 0;
    player->is_jump = 0;
    player->is_fall = 0;
    player->scale = player_scale;
    set_color_player(player);
    player->sprite = set_sprite(PATH_PLAYER_R, x, y);
    sfSprite_setScale(player->sprite, player->scale);
    sfSprite_setTextureRect(player->sprite, int_player_r[0]);
    return player;
}

s_sprite **set_parall(void)
{
    s_sprite **parall = malloc(sizeof(s_sprite *) * 7);

    for (int i = 0; i < 5; i++) {
        parall[i] = set_struct_sprite(path_parall[i], 0, 0);
    }
    return parall;
}
