/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_menu_scene
*/

#include "../../include/my_defender.h"

void u_menu_scene(menu_scene *menu_scene)
{
    hovering_button(menu_scene);
    hovering_settings_buttons(menu_scene);
    hovering_choice_menu_buttons(menu_scene);
    check_hover_click(menu_scene);
    settexture_allbuttons(menu_scene);
    setscale_allbuttons(menu_scene);
    mouse_click_interaction(menu_scene);
    u_pepe_ui(&menu_scene->settings_ui);
}