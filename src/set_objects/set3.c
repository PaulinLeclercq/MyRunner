/*
** EPITECH PROJECT, 2021
** set3.c
** File description:
** set3
*/

#include "../../include/prototypes.h"

void set_score(s_window *window)
{
    int p_col = (-window->map->first) / BLOCK_SIZE / 2;
    int len = my_len_nbr(p_col);
    int tmp_score = p_col;
    int nb = 0;

    window->score_nb = p_col;
    for (int i = 0; i < 8; i++) {
        window->score[i] = set_struct_sprite(PATH_NB_W
        , 1880 - i * 30, 60);
        window->score_max[i] = set_struct_sprite(PATH_NB_W
        , 30 * i + 20, 60);
        sfSprite_setTextureRect(window->score[i]->sprite
        , int_nb[0]);
    }
}

void set_menu2(s_menu *menu)
{
    menu->fps_text = set_struct_sprite(PATH_FPS_T, 1200, 460);
    menu->res_text = set_struct_sprite(PATH_RES_T, 150, 460);
    sfSprite_setScale(menu->res_text->sprite, scale);
    sfSprite_setScale(menu->fps_text->sprite, scale);
    menu->fullscreen = set_struct_sprite
    (menu->is_full ? PATH_FULL2 : PATH_FULL, 300, 690);
    menu->vsync = set_struct_sprite(PATH_VSYNC, 1410, 690);
    menu->res = malloc(sizeof(s_sprite *) * 3);
    menu->fps = malloc(sizeof(s_sprite *) * 3);
    set_volume(menu);
    for (int i = 0; i < 3; i++) {
        menu->res[i] = set_struct_sprite(path_res[i], 175 + i * 200, 540);
        menu->fps[i] = set_struct_sprite(path_fps[i][0], 1215 + i * 200, 540);
    }
    menu->fps[menu->act_fps] = set_struct_sprite(path_fps[menu->act_fps][1]
    , 1215 + menu->act_fps * 200, 540);
}

s_menu *set_menu(int fullscreen)
{
    s_menu *menu = malloc(sizeof(s_menu));
    menu->is_vsync = 0;
    menu->is_full = fullscreen;
    menu->act_fps = GET_FPS_I(FRAME_RATE);
    menu->play = set_struct_sprite(PATH_PLAY, 874, 340);
    menu->exit = set_struct_sprite(PATH_EXIT, 874, 628);
    menu->settings = set_struct_sprite(PATH_SET, 841, 482);
    menu->menu_text = set_struct_sprite(PATH_MENU, 880, 790);
    menu->music_text = set_struct_sprite(PATH_MUSIC_TEXT, 150, 150);
    menu->sound_text = set_struct_sprite(PATH_SOUND_TEXT, 1200, 150);
    sfSprite_setScale(menu->exit->sprite, scale);
    sfSprite_setScale(menu->music_text->sprite, scale);
    sfSprite_setScale(menu->sound_text->sprite, scale);
    menu->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->rect, win_size);
    sfRectangleShape_setFillColor(menu->rect, sfColor_fromRGBA(0, 0, 0, 150));
    menu->red = set_struct_sprite(PATH_RED, 1010, 290);
    menu->green = set_struct_sprite(PATH_GREEN2, 810, 290);
    set_menu2(menu);
    return menu;
}

void find_pos_enemy(s_map *map, int i, int col_p)
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
        find_pos_enemy(map, i, col_p);
        return;
    }
    map->enemies[i] = set_struct_sprite(PATH_BANDIT
    , col * BLOCK_SIZE, line * BLOCK_SIZE + 75);
    map->enemies[i]->sprite = set_sprite(PATH_BANDIT, map->enemies[i]->pos.x
    , map->enemies[i]->pos.y);
    sfSprite_setScale(map->enemies[i]->sprite, enemy_scale);
}

void set_enemies(s_map *map)
{
    int col_p = 0;

    for (int i = 0; map->grid[i]; i++) {
        for (int j = 0; map->grid[i][j]; j++)
            map->grid[i][j] == '0' ? col_p = j + 4 : 0;
    }
    map->nb_enemies = (map->nb_col - col_p) / 8;
    map->enemies = malloc(sizeof(s_sprite *) * map->nb_enemies);
    for (int i = 0; i < map->nb_enemies; i++) {
        find_pos_enemy(map, i, col_p);
        map->enemies[i]->image = rand() % 4;
    }
    set_coins(map);
}
