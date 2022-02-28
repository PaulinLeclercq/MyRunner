/*
** EPITECH PROJECT, 2021
** displays.c
** File description:
** displays
*/

#include "../../include/prototypes.h"

void display_end(s_window *window, s_player *player)
{
    display_game(window, player);
    sfRenderWindow_drawRectangleShape(window->r_window
    , window->smenu->rect, NULL);
    draw_sprites(window->r_window, 3, check_win(window, player) ?
    window->win : window->died, window->exit->sprite
    , window->menu->sprite);
}

void display_menu(s_window *window, s_menu *menu)
{
    sfRenderWindow_display(window->r_window);
    sfRenderWindow_clear(window->r_window, sfBlack);
    for (int i = 4; i >= 0; i--)
        draw_sprites(window->r_window, 1, window->parall[i]->sprite);
    for (int i = 0; i < window->map->nb_block; i++)
        draw_sprites(window->r_window, 1, window->map->blocks[i]->sprite);
    sfRenderWindow_drawRectangleShape(window->r_window
    , window->smenu->rect, NULL);
    draw_sprites(window->r_window, 3, menu->exit->sprite, menu->play->sprite
    , menu->settings->sprite);
}

void display_game2(s_window *window)
{
    for (int i = 0; i < window->map->nb_enemies; i++)
        draw_sprites(window->r_window, 1, window->map->enemies[i]->sprite);
    for (int i = 0; i < window->map->nb_coins; i++) {
        if (window->map->coins[i]->is_touched == 0) {
            draw_sprites(window->r_window, 1, window->map->coins[i]->
            struct_spr->sprite);
        }
    }
}

void display_game(s_window *window, s_player *player)
{
    sfRenderWindow_display(window->r_window);
    sfRenderWindow_clear(window->r_window, sfBlack);
    for (int i = 4; i >= 0; i--)
        draw_sprites(window->r_window, 1, window->parall[i]->sprite);
    for (int i = 0; i < window->map->nb_block; i++) {
        if (window->map->blocks[i]->pos.x >= -135 &&
        window->map->blocks[i]->pos.x <= 2055)
            draw_sprites(window->r_window, 1, window->map->blocks[i]->sprite);
    }
    for (int i = 0; i < my_len_nbr(window->score_nb); i++)
        draw_sprites(window->r_window, 1, window->score[i]->sprite);
    for (int i = 0; i < my_len_nbr(window->score_max_nb); i++)
        draw_sprites(window->r_window, 1, window->score_max[i]->sprite);
    display_game2(window);
    draw_sprites(window->r_window, 3, player->sprite, window->score_name
    , window->score_max_name);
}
