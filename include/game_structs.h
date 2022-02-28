/*
** EPITECH PROJECT, 2021
** game_structs.h
** File description:
** game_structs
*/

#ifndef __STRUCT__
    #define __STRUCT__

    #include "prototypes.h"

typedef struct {
    sfClock *g_clock;
    float (*get_sec)(sfClock *g_clock);
} s_clock;

typedef struct {
    sfSound *sound;
    sfSoundBuffer *buffer;
}s_sound;

typedef struct {
    int image;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfFloatRect (*dim)(sfSprite *sprite);
} s_sprite;

typedef struct {
    int is_bonus;
    int is_touched;
    s_sprite *struct_spr;
} s_coin;

typedef struct {
    int jump;
    int image;
    int height;
    int p_jump;
    int is_red;
    int is_jump;
    int is_fall;
    char const *path;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect *rect;
    sfTexture **run_text;
    sfTexture **jump_text;
    sfSprite *sprite;
    sfFloatRect (*dim)(sfSprite *sprite);
} s_player;

typedef struct {
    int first;
    int nb_col;
    int nb_line;
    int nb_block;
    int nb_coins;
    int nb_enemies;
    char *path;
    char **grid;
    s_coin **coins;
    s_sprite **blocks;
    s_sprite **enemies;
} s_map;

typedef struct {
    int is_full;
    int is_vsync;
    int act_fps;
    sfRectangleShape *rect;
    s_sprite *red;
    s_sprite *play;
    s_sprite *exit;
    s_sprite *green;
    s_sprite *vsync;
    s_sprite **music_arr;
    s_sprite **sound_arr;
    s_sprite **music_vol;
    s_sprite **sound_vol;
    s_sprite *music_text;
    s_sprite *sound_text;
    s_sprite *menu_text;
    s_sprite *res_text;
    s_sprite *fps_text;
    s_sprite *settings;
    s_sprite *fullscreen;
    s_sprite **res;
    s_sprite **fps;
} s_menu;

typedef struct {
    char *path;
    int error;
    int bonus;
    int is_full;
    int score_nb;
    int score_max_nb;
    sfRenderWindow *r_window;
    sfMusic **music;
    sfSprite *pause;
    sfSprite *died;
    sfSprite *win;
    sfSprite *score_name;
    sfSprite *score_max_name;
    s_sprite **parall;
    s_sprite **score;
    s_sprite **score_max;
    s_sprite *menu;
    s_sprite *exit;
    s_sound **sounds;
    s_menu *smenu;
    s_map *map;
} s_window;

#endif
