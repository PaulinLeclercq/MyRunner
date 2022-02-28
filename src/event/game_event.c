/*
** EPITECH PROJECT, 2022
** game_event.c
** File description:
** game_event
*/

#include "../../include/prototypes.h"

int is_in_coin(s_window *window, s_player *player, s_coin *coin)
{
    int pad = player->is_jump ? 25 : 15;
    sfFloatRect c_pos = coin->struct_spr->dim(coin->struct_spr->sprite);
    sfFloatRect p_pos = player->dim(player->sprite);

    if (coin->is_touched)
        return 0;
    if (c_pos.top > p_pos.top && c_pos.top < p_pos.top + p_pos.height) {
        if (c_pos.left > p_pos.left + pad &&
        c_pos.left < p_pos.left - 20 + p_pos.width) {
            coin->is_touched = 1;
            return GET_BONUS(coin->is_bonus);
        }
        if (c_pos.left + c_pos.width > p_pos.left + pad &&
        c_pos.left + c_pos.width < p_pos.left - 20 + p_pos.width) {
            coin->is_touched = 1;
            return GET_BONUS(coin->is_bonus);
        }
    }
    return 0;
}

int is_in_button(s_window *window, sfEvent *event, s_sprite *button)
{
    sfMouseButtonEvent mouse;
    sfFloatRect coord = sfSprite_getGlobalBounds(button->sprite);
    sfVector2u size = sfRenderWindow_getSize(window->r_window);

    mouse.x = (*event).mouseButton.x * WINDOW_WIDTH / size.x;
    mouse.y = (*event).mouseButton.y * WINDOW_HEIGHT / size.y;
    if (mouse.x >= button->pos.x && mouse.x <= button->pos.x + coord.width) {
        if (mouse.y >= button->pos.y && mouse.y <= button->pos.y +
        coord.height) {
            event->type = sfEvtJoystickMoved;
            return 1;
        }
    }
    return 0;
}

int check_win(s_window *window, s_player *player)
{
    int x_first = window->map->first;
    int p_col_r = (player->pos.x + player->dim(player->sprite).width - x_first)
    / BLOCK_SIZE;

    return p_col_r >= window->map->nb_col;
}

int check_end(s_window *window, s_player *player)
{
    int end = 0;
    sfEvent event;

    if (start_end(window, player) == -1)
        return 0;
    sfRenderWindow_setMouseCursorVisible(window->r_window, 1);
    sfSound_play(window->sounds[check_win(window, player) ? 5 : 0]->sound);
    while (1) {
        if (sfRenderWindow_pollEvent(window->r_window, &event))
            end = end_event(window, player, &event);
        if (end > 0)
            return end;
        display_end(window, player);
    }
    return 0;
}

void analyse_events(s_window *window, s_clock **clocks, s_player *player)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->r_window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            menu(window, player, 0);
        if (event.type == sfEvtClosed)
            end_game(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace
        && !player->is_jump && !player->is_fall) {
            sfSound_play(window->sounds[1]->sound);
            to_jump(player);
            player->is_jump = 1;
            jump_player(window, player);
        }
    }
}
