/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_game_core
*/

#include "../../include/my_defender.h"

void close_events(game_core *game_core)
{
    if (game_core->event.type == sfEvtClosed)
            sfRenderWindow_close(game_core->window);
    if (game_core->game_state == MENU && sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(game_core->window);
    }

}

void u_game_core(game_core *game_core)
{
    while (sfRenderWindow_pollEvent(game_core->window, &game_core->event)) {
        close_events(game_core);
        game_core->mouse_pos = get_mouse_pos(game_core->window);
    }
    if (game_core->game_state == MENU)
        u_menu_scene(&game_core->menu_scene);
}