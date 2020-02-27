/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_play_scene
*/

#include "../../include/my_defender.h"

void u_play_scene(play_scene *play_scene)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(play_scene->general_clock)) > 1.0) {
        printf("%f\n", sfTime_asSeconds(sfClock_getElapsedTime(play_scene->general_clock)));
        sfClock_restart(play_scene->general_clock);
        play_scene->player_infos.money += 1;
        sfText_setString(play_scene->player_infos.money_text, my_itoa
        (play_scene->player_infos.money, play_scene->player_infos.money_str));
    }
}