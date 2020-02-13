/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_game_core
*/

#include "../../include/my_defender.h"

void u_game_core(game_core *game_core)
{
    while (sfRenderWindow_pollEvent(game_core->window, &game_core->event)) {
        if (game_core->event.type == sfEvtClosed)
            sfRenderWindow_close(game_core->window);
    }
}