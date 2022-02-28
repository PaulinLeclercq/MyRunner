/*
** EPITECH PROJECT, 2021
** game_stats.h
** File description:
** game_stats
*/

#ifndef __STATS__
    #define __STATS__

    #define ABS(value) value < 0 ? -value : value
    #define GET_FPS_I(value) value == 60 ? 0 : value == 144 ? 1 : 2
    #define GET_FPS(value) value == 0 ? 60 : value == 1 ? 144 : 240
    #define GET_BONUS(value) value ? 2 : -2

    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080
    #define WINDOW_SCALE 3.5
    #define WINDOW_GRASS 170 * WINDOW_SCALE
    #define SPEED 0.14
    #define FRAME_RATE 60
    #define VOLUME 100

    #define PLAYER_HEIGHT_J 185
    #define PLAYER_HEIGHT 170
    #define PLAYER_WIDTH 115
    #define PLAYER_JUMP 22

    #define BLOCK_SIZE 135

static const sfVideoMode mode =
{WINDOW_WIDTH, WINDOW_HEIGHT, 32};

static const sfVector2u res_size[3] =
{{1280, 720}, {1600, 900}, {1920, 1080}};

static const sfVector2f scale =
{WINDOW_SCALE, WINDOW_SCALE};
static const sfVector2f win_size =
{WINDOW_WIDTH, WINDOW_HEIGHT};
static const sfVector2f player_scale =
{5, 5};
static const sfVector2f enemy_scale =
{4, 4};
static const sfVector2f block_scale =
{2.8125, 2.8125};
static const sfVector2f bg_scale =
{1.5, 1.5};
static const sfVector2f reverse =
{-1, 1};

static const sfIntRect int_player_r[8] =
{{0, 0, 23, 34},
{23, 0, 21, 34},
{44, 0, 20, 34},
{64, 0, 22, 34},
{86, 0, 22, 34},
{108, 0, 20, 34},
{128, 0, 21, 34},
{149, 0, 23, 34}};

static const sfIntRect int_player_j[2] =
{{0, 0, 22, 37},
{22, 0, 22, 37}};

static const sfIntRect int_bandit[4] =
{{0, 0, 22, 17},
{22, 0, 22, 17},
{44, 0, 22, 17},
{66, 0, 22, 17}};

static const sfIntRect int_nb[10] =
{{0, 0, 7, 7},
{7, 0, 7, 7},
{15, 0, 7, 7},
{23, 0, 7, 7},
{31, 0, 7, 7},
{39, 0, 7, 7},
{47, 0, 7, 7},
{55, 0, 7, 7},
{63, 0, 7, 7},
{71, 0, 7, 7}};

static const sfIntRect int_coin[5] =
{{1, 0, 15, 16},
{17, 0, 15, 16},
{32, 0, 15, 16},
{49, 0, 15, 16},
{65, 0, 15, 16}};

#endif
