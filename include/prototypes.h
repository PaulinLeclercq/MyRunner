/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my
*/

#ifndef __PROTO__
    #define __PROTO__

    #include <time.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Types.h>
    #include "game_stats.h"
    #include "game_paths.h"
    #include "game_structs.h"
    #include "my.h"

int game(char *path);
void analyse_events(s_window *window, s_clock **clocks, s_player *player);
sfSprite *set_sprite(char const *path, int x, int y);
s_clock **set_clock(int nb);
float get_seconds(sfClock *clock);
s_window *set_window(int fullscreen, char *path);
s_player *set_player(int x, int y);
void anim_player(s_window *window, s_clock **clocks, s_player *player);
s_sprite *set_struct_sprite(char const *path, int x, int y);
void pause_game(s_window *window, s_clock **clocks, s_player *player);
void display_game(s_window *window, s_player *player);
int get_map(char *path, s_map *map, s_player *player);
void set_blocks(s_map *map);
int collisions(s_window *window, s_player *player);
void jump_player(s_window *window, s_player *player);
int is_in_col(s_sprite *block, s_player *player);
int is_in_line(s_sprite *block, s_player *player);
void move_bg(s_window *window);
int check_end(s_window *window, s_player *player);
void set_score(s_window *window);
int get_first_block(s_map *map);
void draw_sprites(sfRenderWindow *window, int nb, ...);
void menu(s_window *window, s_player *player, int reset);
int is_in_button(s_window *window, sfEvent *event, s_sprite *button);
s_menu *set_menu(int fullscreen);
void set_enemies(s_map *map);
void move_enemies(s_map *map);
void display_end(s_window *window, s_player *player);
void display_menu(s_window *window, s_menu *menu);
void display_settings(s_window *window, s_menu *menu, s_player *player);
void to_jump(s_player *player);
void to_run(s_player *player);
int error_map(char *path);
int try_open(char *path);
int error_enemies(s_map *map);
int set_music(s_window *window);
int start_end(s_window *window, s_player *player);
int is_in_enemy(s_window *window, s_player *player, s_sprite *enemy);
void end_game(s_window *window);
int menu_event(s_window *window, s_player *player, sfEvent *event);
int settings(s_window *window, s_player *player, s_menu *smenu);
int settings_event(s_window *window, s_menu *smenu, s_player *player
, sfEvent *event);
void choose_param(s_window *window, s_menu *menu, sfEvent *event, int i);
void choose_full(s_window *window, s_menu *menu, sfEvent *event, int prev);
int end_event(s_window *window, s_player *player, sfEvent *event);
void destroy_sprites(int is_struct, int nb, ...);
int reset_map(s_window *window, s_player *player, int reset);
void get_pos_player(s_map *map, s_player *player, int reset_blocks);
s_sprite **set_parall(void);
int check_win(s_window *window, s_player *player);
int error_buff(char *buff);
void create_file(void);
void get_score_max(s_window *window, int level);
void set_coins(s_map *map);
int is_in_coin(s_window *window, s_player *player, s_coin *coin);
int set_sounds(s_window *window);
void move_player(s_player *player);
void set_volume(s_menu *menu);
void choose_volume(s_window *window, s_menu *menu, sfEvent *event);

#endif
