/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** game
*/

#include "../include/prototypes.h"

void update_score(s_window *window)
{
    int p_col = (-window->map->first) / BLOCK_SIZE / 2;
    int len = my_len_nbr(p_col + window->bonus);
    int len_max = my_len_nbr(window->score_max_nb);
    int tmp_score[2] = {p_col + window->bonus, window->score_max_nb};
    int nb[2] = {0, 0};

    window->score_nb = p_col + window->bonus;
    for (int i = 0; i < len; i++) {
        nb[0] = tmp_score[0] % 10;
        tmp_score[0] /= 10;
        sfSprite_setTextureRect(window->score[i]->sprite
        , int_nb[nb[0]]);
    }
    for (int i = 0; i < len_max; i++) {
        nb[1] = tmp_score[1] % 10;
        tmp_score[1] /= 10;
        sfSprite_setTextureRect(window->score_max[len_max - 1 - i]->sprite
        , int_nb[nb[1]]);
    }
}

void free_game(s_window *window, s_player *player
, s_clock **clocks, s_menu *smenu)
{
    destroy_sprites(0, 3, window->pause, window->died, window->score_name);
    destroy_sprites(1, 9, window->menu, window->exit, smenu->play, smenu->exit,
    smenu->menu_text, smenu->res_text, smenu->fps_text, smenu->settings
    , smenu->fullscreen);
    for (int i = 0; i < 5; i++)
        destroy_sprites(1, 1, window->parall[i]);
    for (int i = 0; i < my_len_nbr(window->score_nb); i++)
        destroy_sprites(1, 1, window->score[i]);
    for (int i = 0; i < 3; i++)
        destroy_sprites(1, 2, smenu->res[i], smenu->fps[i]);
    for (int i = 0; i < window->map->nb_block; i++)
        destroy_sprites(1, 1, window->map->blocks[i]);
    for (int i = 0; i < window->map->nb_enemies; i++)
        destroy_sprites(1, 1, window->map->enemies[i]);
    for (int i = 0; i < window->map->nb_line; i++)
        free(window->map->grid[i]);
    sfRectangleShape_destroy(smenu->rect);
    sfRenderWindow_destroy(window->r_window);
    free(window->map);
    free(window->smenu);
}

void draw_sprites(sfRenderWindow *window, int nb, ...)
{
    va_list list_arg;

    va_start(list_arg, nb);
    for (int i = 0; i < nb; i++)
        sfRenderWindow_drawSprite(window, va_arg(list_arg, sfSprite *), NULL);
    va_end(list_arg);
}

float get_seconds(sfClock *clock)
{
    return sfClock_getElapsedTime(clock).microseconds / 1000000.0;
}

int game(char *path)
{
    s_clock **clocks = set_clock(4);
    s_player *player = set_player(0, 0);
    s_window *window = set_window(1, path);

    menu(window, player, 2);
    set_score(window);
    while (sfRenderWindow_isOpen(window->r_window)) {
        if (window->error == 84) {
            end_game(window);
            return 84;
        }
        update_score(window);
        anim_player(window, clocks, player);
        display_game(window, player);
        analyse_events(window, clocks, player);
        if (check_end(window, player) == 2)
            break;
    }
    free_game(window, player, clocks, window->smenu);
    return 0;
}
