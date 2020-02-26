/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** interactions
*/

#include "../../include/my_defender.h"

void quit_interaction(menu_scene *menu_scene)
{
    if (menu_scene->ui.quit_btn.state == CLICKED && menu_scene->opt_state == 0 &&
    menu_scene->choice_state == 0) {
        sfRenderWindow_close(menu_scene->window);
    }
}

void settings_interaction(menu_scene *menu_scene)
{
    if (menu_scene->ui.settings_btn.state == CLICKED && menu_scene->choice_state == 0) {
        menu_scene->opt_state = 1;
    }
    if (menu_scene->opt_ui.close_button.state == CLICKED) {
        menu_scene->opt_state = 0;
    }
}

void play_interaction(menu_scene *menu_scene)
{
    if (menu_scene->ui.play_btn.state == CLICKED && menu_scene->opt_state == 0) {
        menu_scene->choice_state = 1;
    }
    if (menu_scene->choice_menu.close_btn.state == CLICKED) {
        menu_scene->choice_state = 0;
    }
}

void mouse_click_interaction(menu_scene *menu_scene)
{
    quit_interaction(menu_scene);
    settings_interaction(menu_scene);
    play_interaction(menu_scene);
}
