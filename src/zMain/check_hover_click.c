/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** check_hover_click
*/

#include "../../include/my_defender.h"

void check_hover_click_ui(menu_scene *menu_scene)
{
    if (menu_scene->ui.play_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->ui.play_btn.state = CLICK;
    if (menu_scene->ui.hiscore_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->ui.hiscore_btn.state = CLICK;
    if (menu_scene->ui.settings_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->ui.settings_btn.state = CLICK;
    if (menu_scene->ui.quit_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->ui.quit_btn.state = CLICK;
}

void check_hover_click_choice_menu(menu_scene *menu_scene)
{
    if (menu_scene->choice_menu.close_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft) && menu_scene->choice_state == 1)
        menu_scene->choice_menu.close_btn.state = CLICK;
    if (menu_scene->choice_menu.map_one_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft) && menu_scene->choice_state == 1) {
        *menu_scene->map_index = 1;
    }
    if (menu_scene->choice_menu.map_two_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft) && menu_scene->choice_state == 1) {
        *menu_scene->map_index = 2;
    }
    if (menu_scene->choice_menu.map_three_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft) && menu_scene->choice_state == 1) {
        *menu_scene->map_index = 3;
    }

}
void check_hover_click_options_menu(menu_scene *menu_scene)
{
    if (menu_scene->opt_ui.close_button.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft) && menu_scene->choice_state == 1)
        menu_scene->opt_ui.close_button.state = CLICK;
}

void check_hover_click(menu_scene *menu_scene)
{
    check_hover_click_ui(menu_scene);
    check_hover_click_options_menu(menu_scene);
    check_hover_click_choice_menu(menu_scene);
}