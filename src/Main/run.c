/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** run
*/

#include "../../include/my_defender.h"

void run(void)
{
    game_core game_core;
    i_game_core(&game_core);
    while (sfRenderWindow_isOpen(game_core.window)) {
        u_game_core(&game_core);
        d_game_core(&game_core, game_core.window);
    }
}