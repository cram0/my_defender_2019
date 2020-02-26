/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_game_core_pointers
*/

#include "../../include/my_defender.h"

void i_game_core_pointers(game_core *game_core)
{
    game_core->menu_scene.game_state = malloc(sizeof(int));
    game_core->play_scene.game_state = malloc(sizeof(int));
    game_core->menu_scene.game_state = &game_core->game_state;
    game_core->play_scene.game_state = &game_core->game_state;
    game_core->menu_scene.map_index = malloc(sizeof(int));
    game_core->menu_scene.map_index = &game_core->play_scene.map.map_index;
    game_core->menu_scene.event = malloc(sizeof(sfEvent));
    game_core->menu_scene.event = &game_core->event;
    game_core->play_scene.event = malloc(sizeof(sfEvent));
    game_core->play_scene.event = &game_core->event;
}