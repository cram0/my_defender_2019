/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_player_info
*/

#include "../../include/my_defender.h"

void i_player_infos(play_scene *play_scene)
{
    play_scene->player_infos.score = 1;
    set_difficulty(play_scene);
    set_money(play_scene);
    set_texts(play_scene);
    sfText_setString(play_scene->score, my_itoa
    (play_scene->player_infos.score, play_scene->player_infos.score_str));
}