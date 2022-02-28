/*
** EPITECH PROJECT, 2022
** displays2.c
** File description:
** displays2
*/

#include "../../include/prototypes.h"

void display_settings2(s_window *window, s_menu *menu, s_player *player)
{
    for (int i = 0; i < my_len_nbr(sfMusic_getVolume(window->music[0])); i++)
        draw_sprites(window->r_window, 1, menu->music_vol[i]->sprite);
    for (int i = 0; i < my_len_nbr(sfSound_getVolume(window->sounds[0]->sound))
    ; i++)
        draw_sprites(window->r_window, 1, menu->sound_vol[i]->sprite);
    for (int i = 0; i < 2; i++) {
        draw_sprites(window->r_window, 2, menu->music_arr[i]->sprite
        , menu->sound_arr[i]->sprite);
    }
    draw_sprites(window->r_window, 10, menu->menu_text->sprite, menu->
    fullscreen->sprite, menu->res_text->sprite, menu->fps_text->sprite
    , player->sprite, menu->red->sprite, menu->green->sprite, menu->
    vsync->sprite, menu->music_text->sprite, menu->sound_text->sprite);
}

void display_settings(s_window *window, s_menu *menu, s_player *player)
{
    sfRenderWindow_display(window->r_window);
    sfRenderWindow_clear(window->r_window, sfBlack);
    for (int i = 4; i >= 0; i--)
        draw_sprites(window->r_window, 1, window->parall[i]->sprite);
    for (int i = 0; i < window->map->nb_block; i++)
        draw_sprites(window->r_window, 1, window->map->blocks[i]->sprite);
    sfRenderWindow_drawRectangleShape(window->r_window
    , window->smenu->rect, NULL);
    for (int i = 0; i < 3; i++) {
        draw_sprites(window->r_window, 2, menu->res[i]->sprite
        , menu->fps[i]->sprite);
    }
    display_settings2(window, menu, player);
}
