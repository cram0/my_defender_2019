/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** d_game_core
*/

#include "../../include/my_defender.h"

void d_victory(play_scene *scene)
{
    if (scene->playing == false && scene->waves->index == 9 &&
    scene->player_infos.score >= 9550) {
        sfRenderWindow_drawText(scene->window, scene->victory_txt, NULL);
        sfRenderWindow_drawText(scene->window, scene->yr_score_txt, NULL);
        sfRenderWindow_drawText(scene->window, scene->score, NULL);
    }
}

void d_defeat(play_scene *scene)
{
    if (scene->player_infos.health <= 0 && scene->playing == false) {
        sfRenderWindow_drawText(scene->window, scene->loose_txt, NULL);
        sfRenderWindow_drawText(scene->window, scene->yr_score_txt, NULL);
        sfRenderWindow_drawText(scene->window, scene->score, NULL);
    }
}

void d_game_core(game_core *game_core, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    if (game_core->game_state == MENU)
        d_menu_scene(&game_core->menu_scene);
    if (game_core->game_state == PLAY)
        d_play_scene(&game_core->play_scene);
    d_cursor(game_core);
    d_victory(&game_core->play_scene);
    sfRenderWindow_display(window);
}