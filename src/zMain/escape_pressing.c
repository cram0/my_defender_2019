/*
** EPITECH PROJECT, 2020
** escape_interaction.c
** File description:
** will close subwindows while pressing escape
*/

#include "../../include/my_defender.h"

void u_escape_interaction(play_scene *play_scene)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && play_scene->pause_state == 1)
        play_scene->pause_state = 0;
}