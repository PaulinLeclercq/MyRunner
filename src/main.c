/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../include/prototypes.h"

int handle_map(char *path)
{
    if (my_strcmp(path, "-i") != 0)
        return game(path);
    else
        return game("endless.txt");
}

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac == 2 && my_strcmp(av[1], "-h") != 0)
        return handle_map(av[1]);
    else if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        write(1, "Finite runner created with CSFML\n\nUSAGE\n  ./my_runner"
        " map_number.txt\n\nUSER INTERACTIONS\n  SPACE_KEY     jump\n"
        "  ESCAPE_KEY    pause game / exit settings\n  ENTER_KEY     launch or"
        " resume game\n\nDESCRIPTION\n    The goal of the game is to go"
        " at the end of the level without dying.\n    Enemies appear randomly "
        "on the map. If you touch them, you die!\n    Gold coins give you two"
        " points and red coins removes you two points. Be careful which one "
        "you take!\n\nSETTINGS\n    You can change the resolution of the "
        "window, the fps, the character color,\n    set the window to "
        "fullscreen or not and enable or disable the vsync in the settings via"
        " the menu.\n", 639);
    } else {
        my_printf("Wrong argument.\nUse -h to see the usage.\n");
        return 84;
    }
    return 0;
}
