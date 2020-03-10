/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_game_core
*/

#include "../../include/my_defender.h"

void i_game_core(game_core *game_core)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}
    , "Bloons TD 5", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    game_core->window = window;
    game_core->game_state = MENU;
    i_game_core_pointers(game_core);
    i_cursor(game_core);
    i_music(game_core);
    i_menu_scene(&game_core->menu_scene, window);
    i_play_scene(&game_core->play_scene, window);
}