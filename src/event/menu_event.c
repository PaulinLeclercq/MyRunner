/*
** EPITECH PROJECT, 2022
** menu_event.c
** File description:
** menu_event
*/

#include "../../include/prototypes.h"

void update_volume_text(s_window *window, s_menu *menu)
{
    int nb = 0;
    int volume_mus = sfMusic_getVolume(window->music[0]);
    int volume_sou = sfSound_getVolume(window->sounds[0]->sound);
    int len_mus = my_len_nbr(volume_mus);
    int len_sou = my_len_nbr(volume_sou);

    for (int i = 0; i < len_mus; i++) {
        nb = volume_mus % 10;
        volume_mus /= 10;
        sfSprite_setTextureRect(menu->music_vol[i]->sprite, int_nb[nb]);
    }
    for (int i = 0; i < len_sou; i++) {
        nb = volume_sou % 10;
        volume_sou /= 10;
        sfSprite_setTextureRect(menu->sound_vol[i]->sprite, int_nb[nb]);
    }
}

void update_volume(s_window *window, s_menu *menu, int plus, int is_music)
{
    float volume = is_music ? sfMusic_getVolume(window->music[0]) :
    sfSound_getVolume(window->sounds[0]->sound);

    if (plus)
        volume += (int) volume < 100 ? 1 : 0;
    else
        volume -= (int) volume > 0 ? 1 : 0;
    if (is_music) {
        sfMusic_setVolume(window->music[0], volume);
        sfMusic_setVolume(window->music[1], volume);
    } else {
        sfSound_setVolume(window->sounds[0]->sound, volume);
        sfSound_setVolume(window->sounds[1]->sound, volume);
        sfSound_setVolume(window->sounds[2]->sound, volume);
        sfSound_setVolume(window->sounds[3]->sound, volume);
        sfSound_setVolume(window->sounds[4]->sound, volume);
        sfSound_setVolume(window->sounds[5]->sound, volume);
    }
    update_volume_text(window, menu);
}

void choose_volume(s_window *window, s_menu *menu, sfEvent *event)
{
    for (int i = 0; i < 2; i++) {
        if (is_in_button(window, event, menu->music_arr[i]))
            update_volume(window, menu, i, 1);
        if (is_in_button(window, event, menu->sound_arr[i]))
            update_volume(window, menu, i, 0);
    }
}

int end_event(s_window *window, s_player *player, sfEvent *event)
{
    if ((*event).type == sfEvtClosed) {
        end_game(window);
        return 2;
    }
    if ((*event).type == sfEvtKeyPressed && (*event).key.code == sfKeyEnter) {
        menu(window, player, 1);
        return 1;
    }
    if ((*event).type == sfEvtMouseButtonPressed &&
    (*event).mouseButton.button == sfMouseLeft) {
        if (is_in_button(window, event, window->menu)) {
            menu(window, player, 1);
            return 1;
        }
        if (is_in_button(window, event, window->exit)) {
            end_game(window);
            return 1;
        }
    }
    return 0;
}

int menu_event(s_window *window, s_player *player, sfEvent *event)
{
    if ((*event).type == sfEvtClosed) {
        end_game(window);
        return 1;
    }
    if ((*event).type == sfEvtKeyPressed && (*event).key.code == sfKeyEnter)
        return 2;
    if (((*event).type == sfEvtMouseButtonPressed &&
    (*event).mouseButton.button == sfMouseLeft)) {
        if (is_in_button(window, event, window->smenu->settings)
        && settings(window, player, window->smenu)
        || is_in_button(window, event, window->smenu->play))
            return 2;
        if (is_in_button(window, event, window->smenu->exit)) {
            end_game(window);
            return 1;
        }
    }
    return 0;
}
