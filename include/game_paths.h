/*
** EPITECH PROJECT, 2021
** game_paths.h
** File description:
** game_paths
*/

#ifndef __PATHS__
    #define __PATHS__

    #define PATH_EXIT "images/menu/exit.png"
    #define PATH_PLAY "images/menu/play.png"
    #define PATH_MENU "images/menu/menu.png"
    #define PATH_RES_T "images/menu/res_text.png"
    #define PATH_FPS_T "images/menu/fps_text.png"
    #define PATH_RED "images/menu/red.png"
    #define PATH_RED2 "images/menu/red2.png"
    #define PATH_GREEN "images/menu/green.png"
    #define PATH_VSYNC "images/menu/vsync.png"
    #define PATH_VSYNC2 "images/menu/vsync2.png"
    #define PATH_GREEN2 "images/menu/green2.png"
    #define PATH_FULL "images/menu/fullscreen.png"
    #define PATH_FULL2 "images/menu/fullscreen2.png"
    #define PATH_MUSIC_TEXT "images/menu/music_text.png"
    #define PATH_SOUND_TEXT "images/menu/sound_text.png"
    #define PATH_PAUSE "images/menu/pause.png"
    #define PATH_SCORE "images/menu/score.png"
    #define PATH_SCORE_MAX "images/menu/score_max.png"
    #define PATH_SET "images/menu/settings.png"
    #define PATH_DIED "images/menu/you_died.png"
    #define PATH_WIN "images/menu/you_won.png"
    #define PATH_NB_W "images/menu/white_numbers.png"

    #define PATH_MUSIC_M "musics/menu.ogg"
    #define PATH_MUSIC_G "musics/game.ogg"

    #define PATH_SOUND_WIN "musics/win.ogg"
    #define PATH_SOUND_DEAD "musics/dead.ogg"
    #define PATH_SOUND_JUMP "musics/jump.ogg"
    #define PATH_SOUND_LAND "musics/land.ogg"
    #define PATH_SOUND_BONUS "musics/coin_bonus.ogg"
    #define PATH_SOUND_MALUS "musics/coin_malus.ogg"

    #define PATH_PLAYER_R "images/jungle_sprite/character/run.png"
    #define PATH_PLAYER_J "images/jungle_sprite/character/fall.png"
    #define PATH_PLAYER_R_RED "images/jungle_sprite/character/run_red.png"
    #define PATH_PLAYER_J_RED "images/jungle_sprite/character/fall_red.png"

    #define PATH_BANDIT "images/enemies/bandit_idle.png"

    #define PATH_COIN_Y "images/coins/MonedaD.png"
    #define PATH_COIN_R "images/coins/MonedaR.png"

static const char *path_res[3] =
{"images/menu/1280.png",
"images/menu/1600.png",
"images/menu/1920.png"};

static const char *path_fps[3][2] =
{{"images/menu/60_fps_1.png", "images/menu/60_fps_2.png"},
{"images/menu/144_fps_1.png", "images/menu/144_fps_2.png"},
{"images/menu/240_fps_1.png", "images/menu/240_fps_2.png"}};

static const char *path_parall[5] =
{"images/jungle_sprite/parallax/plx-5.png",
"images/jungle_sprite/parallax/plx-4.png",
"images/jungle_sprite/parallax/plx-3.png",
"images/jungle_sprite/parallax/plx-2.png",
"images/jungle_sprite/parallax/plx-1.png"};

static const char *path_block[4] =
{"images/jungle_sprite/blocks/empty_block.png",
"images/jungle_sprite/blocks/grass_block.png",
"images/jungle_sprite/blocks/corner_block.png",
"images/jungle_sprite/blocks/corner2_block.png"};

static const char *path_arr[2] =
{"images/menu/minus.png",
"images/menu/plus.png"};

#endif
