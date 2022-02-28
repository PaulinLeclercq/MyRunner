/*
** EPITECH PROJECT, 2021
** window.c
** File description:
** window
*/

#include "../../include/prototypes.h"

void destroy_sprites(int is_struct, int nb, ...)
{
    va_list list_arg;
    s_sprite *sprite;

    va_start(list_arg, nb);
    for (int i = 0; i < nb; i++) {
        if (is_struct) {
            sprite = va_arg(list_arg, s_sprite *);
            sfTexture_destroy(sprite->texture);
            sfSprite_destroy(sprite->sprite);
            free(sprite);
        } else
            sfSprite_destroy(va_arg(list_arg, sfSprite *));
    }
    va_end(list_arg);
}

int is_in_enemy(s_window *window, s_player *player, s_sprite *enemy)
{
    int pad = player->is_jump ? 25 : 15;
    sfFloatRect e_pos = enemy->dim(enemy->sprite);
    sfFloatRect p_pos = player->dim(player->sprite);

    if (e_pos.top > p_pos.top && e_pos.top < p_pos.top + p_pos.height) {
        if (e_pos.left > p_pos.left + pad &&
        e_pos.left < p_pos.left - 20 + p_pos.width)
            return 1;
        if (e_pos.left + e_pos.width > p_pos.left + pad &&
        e_pos.left + e_pos.width < p_pos.left - 20 + p_pos.width)
            return 1;
    }
    return 0;
}

void get_score_max(s_window *window, int level)
{
    int i = 1;
    char *buff = my_strset(100);
    int file = open("score.txt", O_RDWR | O_CREAT, S_IROTH | S_IRGRP
    | S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH);

    for (; i < level; i++) {
        if (read(file, buff, 5) == -1 || error_buff(buff)) {
            create_file();
            break;
        }
    }
    close(file);
    file = open("score.txt", O_RDWR);
    for (int i = 1; i <= level && read(file, buff, 5); i++);
    window->score_max_nb = str_to_long(buff);
    close(file);
    free(buff);
}

void set_window2(s_window *window)
{
    window->exit = set_struct_sprite(PATH_EXIT, WINDOW_WIDTH / 2 + 24, 700);
    window->menu = set_struct_sprite(PATH_MENU, WINDOW_WIDTH / 2 - 196, 700);
    window->score_name = set_sprite(PATH_SCORE, 1765, 20);
    window->score_max_name = set_sprite(PATH_SCORE_MAX, 20, 20);
    window->pause = set_sprite(PATH_PAUSE, 370, 230);
    window->died = set_sprite(PATH_DIED, 330, 440);
    window->win = set_sprite(PATH_WIN, 290, 440);
    sfSprite_setScale(window->exit->sprite, scale);
    sfSprite_setScale(window->died, (sfVector2f) {2, 2});
    sfSprite_setScale(window->win, (sfVector2f) {2, 2});
}

s_window *set_window(int fullscreen, char *path)
{
    s_window *window = malloc(sizeof(s_window));

    window->error = 0;
    window->bonus = 0;
    window->path = path;
    window->score_nb = 0;
    window->smenu = set_menu(fullscreen);
    window->score = malloc(sizeof(sfSprite *) *  9);
    window->score_max = malloc(sizeof(sfSprite *) *  9);
    window->parall = set_parall();
    set_window2(window);
    set_music(window) == 84 ? window->error = 84 : 0;
    set_sounds(window) == 84 ? window->error = 84 : 0;
    get_score_max(window, str_to_long(path));
    window->r_window = sfRenderWindow_create(mode, "My Runner"
    , fullscreen ? sfFullscreen : sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->r_window, FRAME_RATE);
    return window;
}
