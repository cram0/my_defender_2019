/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_game_core
*/

#include "../../include/my_defender.h"

void i_game_core(game_core *game_core)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){1600, 900, 32}
    , "TOWER DEFENSE", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    game_core->window = window;
    i_menu_scene(&game_core->menu_scene, window);
    i_play_scene(&game_core->play_scene, window);
}