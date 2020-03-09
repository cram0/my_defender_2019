/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_font
*/

#include "../../include/my_defender.h"

void i_font(play_scene *play_scene)
{
    play_scene->font = sfFont_createFromFile("font/font.TTF");
    sfText_setFont(play_scene->player_infos.health_text, play_scene->font);
    sfText_setFont(play_scene->player_infos.money_text, play_scene->font);
}