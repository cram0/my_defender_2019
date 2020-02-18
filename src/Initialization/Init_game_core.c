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
    , "TOWER DEFENSE", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    game_core->window = window;
    game_core->game_state = MENU;
    game_core->menu_scene.game_state = malloc(sizeof(int));
    game_core->play_scene.game_state = malloc(sizeof(int));
    game_core->menu_scene.game_state = &game_core->game_state;
    game_core->play_scene.game_state = &game_core->game_state;
    i_menu_scene(&game_core->menu_scene, window);
    i_play_scene(&game_core->play_scene, window);
}