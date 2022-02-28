/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** error
*/

#include "../include/prototypes.h"

int try_open(char *path)
{
    if (errno == ENOENT) {
        write(2, "my_runner: ", 11);
        write(2, path, my_strlen(path));
        write(2, ": Map doesn't exist\n", 20);
        return 84;
    }
    if (errno == EACCES) {
        write(2, "my_runner: ", 11);
        write(2, path, my_strlen(path));
        write(2, ": Permission denied\n", 20);
        return 84;
    }
    return 0;
}

int get_top(char **grid, int col)
{
    int top = 0;

    for (int i = 0; i <= 6; i++) {
        if (grid[i][col] != ' ' && grid[i][col] != '0')
            return grid[i][col];
    }
    return top;
}

int error_enemies(s_map *map)
{
    int nb = 0;
    int top = 0;

    for (int i = 0; i < map->nb_col; i++) {
        top = get_top(map->grid, i);
        if (top != '1')
            nb++;
        else
            nb = 0;
        if (nb > 7) {
            write(2, "Enemies could not be placed\n", 28);
            return 84;
        }
    }
    return 0;
}

int error_map(char *path)
{
    int i = 0;
    int size = 1;
    int len_line = 0;
    int nb_lines = 0;
    int file = open(path, O_RDONLY);
    char *buffer = my_strset(2);

    for (; size && i >= 0 && i <= 10000; i++) {
        size = read(file, buffer, 1);
        len_line += nb_lines == 0;
        if (buffer[0] == '\n') {
            nb_lines += 1;
            i = ((i + 1) % len_line == 0) ? i : -2;
        }
        i = (nb_lines > 6 || !is_in_str(buffer[0], " 012345678\n")) ? -2 : i;
    }
    if (i = nb_lines != 6 || i % len_line != 0 ? -2 : i && i < 0 || i > 10000)
        write(2, "Wrong map format\n", 17);
    close(file);
    return i < 0 || i > 10000 ? 84 : 0;
}
