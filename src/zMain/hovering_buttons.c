/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** hovering_buttons
*/

#include "../../include/my_defender.h"

void hovering_button(menu_scene *menu_scene)
{
    if (is_hovering(menu_scene->ui.play_btn, menu_scene->window))
        menu_scene->ui.play_btn.state = HOVER;
    else
        menu_scene->ui.play_btn.state = IDLE;
    if (is_hovering(menu_scene->ui.hiscore_btn, menu_scene->window))
        menu_scene->ui.hiscore_btn.state = HOVER;
    else
        menu_scene->ui.hiscore_btn.state = IDLE;
    if (is_hovering(menu_scene->ui.quit_btn, menu_scene->window))
        menu_scene->ui.quit_btn.state = HOVER;
    else
        menu_scene->ui.quit_btn.state = IDLE;
    if (is_hovering(menu_scene->ui.settings_btn, menu_scene->window))
        menu_scene->ui.settings_btn.state = HOVER;
    else
        menu_scene->ui.settings_btn.state = IDLE;
}

void hovering_choice_menu_buttons(menu_scene *menu_scene)
{
    if (is_hovering(menu_scene->choice_menu.close_btn, menu_scene->window)) {
        menu_scene->choice_menu.close_btn.state = HOVER;
    } else
        menu_scene->choice_menu.close_btn.state = IDLE;
    if (is_hovering(menu_scene->choice_menu.map_one_btn, menu_scene->window)) {
        menu_scene->choice_menu.map_one_btn.state = HOVER;
    } else
        menu_scene->choice_menu.map_one_btn.state = IDLE;
    if (is_hovering(menu_scene->choice_menu.map_two_btn, menu_scene->window)) {
        menu_scene->choice_menu.map_two_btn.state = HOVER;
    } else
        menu_scene->choice_menu.map_two_btn.state = IDLE;
}

void hovering_settings_buttons(menu_scene *menu_scene)
{
    if (is_hovering(menu_scene->opt_ui.close_button, menu_scene->window)) {
        menu_scene->opt_ui.close_button.state = HOVER;
    } else
        menu_scene->opt_ui.close_button.state = IDLE;
}