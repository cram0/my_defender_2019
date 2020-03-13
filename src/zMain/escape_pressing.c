/*
** EPITECH PROJECT, 2020
** escape_interaction.c
** File description:
** will close subwindows while pressing escape
*/

#include "../../include/my_defender.h"

void u_escape_interaction(play_scene *play_scene)
{
    if (play_scene->event->type == sfEvtKeyPressed && play_scene->pause_state == 0) {
        play_scene->pause_state = 1;
        sfSound_play(play_scene->click_sound.sound);
    } else if (play_scene->event->type == sfEvtKeyPressed && play_scene->pause_state == 1) {
        play_scene->pause_state = 0;
        sfSound_play(play_scene->click_sound.sound);
    }
}