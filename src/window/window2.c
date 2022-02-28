/*
** EPITECH PROJECT, 2022
** window2.c
** File description:
** window2
*/

#include "../../include/prototypes.h"

void end_game(s_window *window)
{
    for (int i = 0; i < 6; i++) {
        sfSoundBuffer_destroy(window->sounds[i]->buffer);
        sfSound_destroy(window->sounds[i]->sound);
    }
    sfMusic_destroy(window->music[0]);
    sfMusic_destroy(window->music[1]);
    window->music[0] = 0;
    window->music[1] = 0;
    sfRenderWindow_close(window->r_window);
}

void create_file(void)
{
    int error = 0;
    int nb_level = 1;
    char *name_level = my_strset(8);
    int file2 = open("score.txt", O_WRONLY);

    for (; error != -1; nb_level++) {
        my_strcat(my_strcat(name_level, long_to_str(nb_level)), ".txt");
        error = open(name_level, O_RDONLY);
        if (error == -1)
            break;
        free(name_level);
        name_level = my_strset(8);
    }
    close(error);
    for (int i = 0; i < nb_level - 1; i++)
        write(file2, "0000\n", 5);
    free(name_level);
}

int error_buff(char *buff)
{
    for (int i = 0; i < 4; i++) {
        if (buff[i] < '0' || buff[i] > '9')
            return 1;
    }
    if (buff[4] != '\n')
        return 1;
    return 0;
}

int save_score(s_window *window, int level)
{
    char *buff = my_strset(100);
    int file = open("score.txt", O_RDWR | O_CREAT, S_IROTH | S_IRGRP
    | S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH);

    for (int i = 1; i < level; i++) {
        if (read(file, buff, 5) == -1 || error_buff(buff)) {
            create_file();
            break;
        }
    }
    close(file);
    file = open("score.txt", O_RDWR);
    for (int i = 1; i < level && read(file, buff, 5); i++);
    for (int i = 0; i < 4 - my_len_nbr(window->score_nb); i++)
        write(file, "0", 1);
    write(file, long_to_str(window->score_nb)
    , my_len_nbr(window->score_nb));
    close(file);
    free(buff);
    return 0;
}

int start_end(s_window *window, s_player *player)
{
    int is_dead = 0;
    int bonus = window->bonus;

    for (int i = 0; i < window->map->nb_coins; i++) {
        window->bonus += is_in_coin(window, player, window->map->coins[i]);
        bonus < window->bonus ? sfSound_play(window->sounds[2]->sound) : 0;
        bonus > window->bonus ? sfSound_play(window->sounds[3]->sound) : 0;
    }
    for (int i = 0; i < window->map->nb_enemies && !is_dead; i++)
        is_dead += is_in_enemy(window, player, window->map->enemies[i]);
    if (ABS(collisions(window, player)) != 1 && !is_dead)
        return -1;
    window->music[1] ? sfMusic_stop(window->music[1]) : 0;
    get_score_max(window, str_to_long(window->path));
    if (window->score_nb > window->score_max_nb)
        return save_score(window, str_to_long(window->path));
    else
        return 0;
}
