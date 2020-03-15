/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** d_game_core
*/

#include "../../include/my_defender.h"

void d_game_core(game_core *game_core, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    if (game_core->game_state == MENU)
        d_menu_scene(&game_core->menu_scene);
    if (game_core->game_state == PLAY)
        d_play_scene(&game_core->play_scene);
    d_cursor(game_core);
    sfRenderWindow_display(window);
}