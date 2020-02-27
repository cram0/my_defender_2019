/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_menu_scene
*/

#include "../../include/my_defender.h"

void i_menu_scene(menu_scene *menu_scene, sfRenderWindow *window)
{
    menu_scene->window = window;
    menu_scene->settings_state = 0;
    menu_scene->choice_state = 0;
    i_menu_background(&menu_scene->menu_background);
    i_settings_ui(&menu_scene->settings_ui);
    i_menu_ui(&menu_scene->ui);
    i_choice_menu(&menu_scene->choice_menu);
}