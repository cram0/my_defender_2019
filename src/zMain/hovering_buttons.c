/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** hovering_buttons
*/

#include "../../include/my_defender.h"

void hovering_button(menu_scene *menu_scene)
{
    button *buttons[4];
    buttons[0] = &menu_scene->ui.play_btn;
    buttons[1] = &menu_scene->ui.hiscore_btn;
    buttons[2] = &menu_scene->ui.settings_btn;
    buttons[3] = &menu_scene->ui.quit_btn;
    for (int i = 0; i < 4; i++) {
        if (is_hovering(*buttons[i], menu_scene->window))
            buttons[i]->state = HOVER;
        else
            buttons[i]->state = IDLE;
    }
}

void hovering_choice_menu_buttons(menu_scene *menu_scene)
{
    button *buttons[4];
    buttons[0] = &menu_scene->choice_menu.close_btn;
    buttons[1] = &menu_scene->choice_menu.map_one_btn;
    buttons[2] = &menu_scene->choice_menu.map_two_btn;
    buttons[3] = &menu_scene->choice_menu.map_three_btn;
    for (int i = 0; i < 4; i++) {
        if (is_hovering(*buttons[i], menu_scene->window))
            buttons[i]->state = HOVER;
        else
            buttons[i]->state = IDLE;
    }
}

void hovering_settings_buttons(menu_scene *menu_scene)
{
    if (is_hovering(menu_scene->opt_ui.close_button, menu_scene->window)) {
        menu_scene->opt_ui.close_button.state = HOVER;
    } else
        menu_scene->opt_ui.close_button.state = IDLE;
}