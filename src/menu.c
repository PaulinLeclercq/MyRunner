/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** menu
*/

#include "../include/prototypes.h"

int reset_game(s_window *window, s_player *player, int reset)
{
    if (!reset) {
        window->music[1] ? sfMusic_pause(window->music[1]) : 0;
        return 0;
    } else
        window->music[1] ? sfMusic_stop(window->music[1]) : 0;
    window->music[0] ? sfMusic_play(window->music[0]) : 0;
    if (reset_map(window, player, reset) == 84)
        return 84;
    get_score_max(window, str_to_long(window->path));
    window->score_nb = 0;
    player->is_fall = 0;
    player->is_jump = 0;
    player->jump = PLAYER_JUMP;
    to_run(player);
}

void choose_full(s_window *window, s_menu *menu, sfEvent *event, int prev)
{
    sfVector2u size = sfRenderWindow_getSize(window->r_window);

    if (is_in_button(window, event, menu->fullscreen))
        menu->is_full = (menu->is_full == 1) ? 0 : 1;
    if (prev != menu->is_full) {
        menu->fullscreen = set_struct_sprite
        (menu->is_full ? PATH_FULL2 : PATH_FULL, 300, 690);
        sfRenderWindow_destroy(window->r_window);
        window->r_window = sfRenderWindow_create(mode, "My Runner"
        , menu->is_full ? sfFullscreen : sfClose, NULL);
        sfRenderWindow_setVerticalSyncEnabled(window->r_window,
        menu->is_vsync ? sfTrue : sfFalse);
        sfRenderWindow_setFramerateLimit(window->r_window
        , GET_FPS(window->smenu->act_fps));
        sfRenderWindow_setSize(window->r_window, menu->is_full ?
        res_size[2] : size);
    }
}

void choose_param(s_window *window, s_menu *menu, sfEvent *event, int i)
{
    if (is_in_button(window, event, menu->res[i])) {
        if (menu->is_full && i < 2) {
            menu->is_full = 0;
            choose_full(window, menu, event, 1);
        }
        sfRenderWindow_setSize(window->r_window, res_size[i]);
    }
    if (is_in_button(window, event, menu->fps[i])) {
        sfRenderWindow_setFramerateLimit(window->r_window, GET_FPS(i));
        menu->fps[menu->act_fps] = set_struct_sprite(path_fps[menu->act_fps][0]
        , 1215 + menu->act_fps * 200, 540);
        menu->fps[i] = set_struct_sprite(path_fps[i][1]
        , 1215 + i * 200, 540);
        menu->act_fps = i;
    }
}

int settings(s_window *window, s_player *player, s_menu *smenu)
{
    sfEvent event;
    s_clock **clock = set_clock(1);
    sfVector2f rect_prev = player->pos;
    int end_settings = 0;

    sfSprite_setPosition(player->sprite, (sfVector2f) {910, 80});
    sfRenderWindow_setMouseCursorVisible(window->r_window, 1);
    while (1) {
        if (get_seconds(clock[0]->g_clock) > 0.06) {
            move_player(player);
            sfClock_restart(clock[0]->g_clock);
        }
        if (sfRenderWindow_pollEvent(window->r_window, &event))
            end_settings = settings_event(window, smenu, player, &event);
        if (end_settings > 0)
            break;
        display_settings(window, smenu, player);
    }
    player->pos = rect_prev;
    return (end_settings != 0 ? end_settings - 1 : 0);
}

void menu(s_window *window, s_player *player, int reset)
{
    sfEvent event;
    int end_menu = 0;

    sfRenderWindow_setMouseCursorVisible(window->r_window, 1);
    if (reset_game(window, player, reset) == 84)
        return;
    while (1) {
        if (sfRenderWindow_pollEvent(window->r_window, &event))
            end_menu = menu_event(window, player, &event);
        if (end_menu == 1)
            return;
        if (end_menu == 2)
            break;
        end_menu = 0;
        display_menu(window, window->smenu);
    }
    sfRenderWindow_setMouseCursorVisible(window->r_window, 0);
    window->music[0] ? sfMusic_stop(window->music[0]) : 0;
    window->music[1] ? sfMusic_play(window->music[1]) : 0;
}
