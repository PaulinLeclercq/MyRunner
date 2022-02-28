/*
** EPITECH PROJECT, 2022
** settings_event.c
** File description:
** settings_event
*/

#include "../../include/prototypes.h"

void set_arrows(s_menu *menu)
{
    menu->music_arr = malloc(sizeof(s_sprite *) * 2);
    menu->sound_arr = malloc(sizeof(s_sprite *) * 2);
    for (int i = 0; i < 2; i++) {
        menu->music_arr[i] = set_struct_sprite(path_arr[i]
        , (!i ? 360 : 535), 240);
        menu->sound_arr[i] = set_struct_sprite(path_arr[i]
        , (!i ? 1400 : 1570), 240);
    }
}

void set_volume(s_menu *menu)
{
    int nb = 0;
    int volume = VOLUME;
    int len = my_len_nbr(volume);
    menu->sound_vol = malloc(sizeof(s_sprite *) * 3);
    menu->music_vol = malloc(sizeof(s_sprite *) * 3);

    for (int i = 0; i < len; i++) {
        nb = volume % 10;
        volume /= 10;
        menu->sound_vol[i] = set_struct_sprite(PATH_NB_W, 1510 - i * 30, 240);
        menu->music_vol[i] = set_struct_sprite(PATH_NB_W, 475 - i * 30, 240);
        sfSprite_setTextureRect(menu->sound_vol[i]->sprite, int_nb[nb]);
        sfSprite_setTextureRect(menu->music_vol[i]->sprite, int_nb[nb]);
    }
    menu->sound_vol[2] = set_struct_sprite(PATH_NB_W, 1510 - 2 * 30, 240);
    menu->music_vol[2] = set_struct_sprite(PATH_NB_W, 475 - 2 * 30, 240);
    sfSprite_setTextureRect(menu->sound_vol[2]->sprite, int_nb[1]);
    sfSprite_setTextureRect(menu->music_vol[2]->sprite, int_nb[1]);
    set_arrows(menu);
}

void choose_vsync(s_window *window, s_menu *menu, sfEvent *event)
{
    int prev = menu->is_vsync;

    if (is_in_button(window, event, menu->vsync))
        menu->is_vsync = (menu->is_vsync == 1) ? 0 : 1;
    if (prev != menu->is_vsync) {
        sfRenderWindow_setVerticalSyncEnabled(window->r_window,
        menu->is_vsync ? sfTrue : sfFalse);
        menu->vsync = set_struct_sprite
        (menu->is_vsync ? PATH_VSYNC2 : PATH_VSYNC, 1410, 690);
    }
}

void change_player_color(s_window *window, s_player *player, sfEvent *event)
{
    int prev = player->is_red;

    if (is_in_button(window, event, window->smenu->green) && player->is_red)
        player->is_red = 0;
    if (is_in_button(window, event, window->smenu->red) && !player->is_red)
        player->is_red = 1;
    if (prev != player->is_red) {
        sfSprite_setTexture(player->sprite, (player->is_jump || player->is_fall
        ? player->jump_text[player->is_red] : player->run_text[player->is_red])
        , sfTrue);
        sfSprite_setTextureRect(player->sprite, (player->is_jump || player->
        is_fall ? int_player_j[player->image] : int_player_r[player->image]));
        window->smenu->green = set_struct_sprite
        (player->is_red ? PATH_GREEN : PATH_GREEN2, 810, 290);
        window->smenu->red = set_struct_sprite
        (player->is_red ? PATH_RED2 : PATH_RED, 1010, 290);
    }
}

int settings_event(s_window *window, s_menu *smenu, s_player *player
, sfEvent *event)
{
    if ((*event).type == sfEvtClosed) {
        end_game(window);
        return 2;
    }
    if ((*event).type == sfEvtKeyPressed && (*event).key.code == sfKeyEscape)
        return 1;
    if ((*event).type == sfEvtMouseButtonPressed &&
    (*event).mouseButton.button == sfMouseLeft) {
        if (is_in_button(window, event, smenu->menu_text))
            return 1;
        choose_vsync(window, smenu, event);
        choose_volume(window, smenu, event);
        change_player_color(window, player, event);
        choose_full(window, smenu, event, smenu->is_full);
        for (int i = 0; i < 3; i++)
            choose_param(window, smenu, event, i);
    }
    return 0;
}
