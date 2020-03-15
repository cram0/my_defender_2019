/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_text_out_thick
*/

#include "../../include/my_defender.h"

void i_text_out_thick(play_scene *play_scene)
{
    sfText_setOutlineThickness(play_scene->player_infos.health_text, 2);
    sfText_setOutlineThickness(play_scene->player_infos.money_text, 2);
    sfText_setOutlineThickness(play_scene->player_infos.score_text, 2);
    sfText_setOutlineThickness(play_scene->dragndrop.price_text, 2);
    sfText_setOutlineThickness(play_scene->score_text_dot, 2);
    sfText_setOutlineThickness(play_scene->wave_text, 2);
    sfText_setOutlineThickness(play_scene->wave_number, 2);
    sfText_setOutlineThickness(play_scene->setting_txt, 2);
    sfText_setOutlineThickness(play_scene->wave_button, 2);
}