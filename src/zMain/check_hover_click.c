/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** check_hover_click
*/

#include "../../include/my_defender.h"

void check_hover_click_ui(menu_scene *menu_scene)
{
    button *buttons[4];
    buttons[0] = &menu_scene->ui.play_btn;
    buttons[1] = &menu_scene->ui.hiscore_btn;
    buttons[2] = &menu_scene->ui.settings_btn;
    buttons[3] = &menu_scene->ui.quit_btn;
    for (int i = 0; i < 4; i++)
        if (buttons[i]->state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
            buttons[i]->state = CLICKING;
    for (int i = 0; i < 4; i++)
        if (buttons[i]->state == HOVER && menu_scene->event->mouseButton.type == sfEvtMouseButtonReleased)
            buttons[i]->state = CLICKED;
}

void check_hover_click_choice_menu(menu_scene *menu_scene)
{
    if (menu_scene->choice_menu.close_btn.state == HOVER &&
    sfMouse_isButtonPressed(sfMouseLeft) && menu_scene->choice_state == 1)
        menu_scene->choice_menu.close_btn.state = CLICKING;
    if (menu_scene->choice_menu.close_btn.state == HOVER &&
    menu_scene->event->mouseButton.type == sfEvtMouseButtonReleased &&
    menu_scene->choice_state == 1)
            menu_scene->choice_menu.close_btn.state = CLICKED;
    if (menu_scene->choice_menu.map_one_btn.state == HOVER &&
    sfMouse_isButtonPressed(sfMouseLeft) && menu_scene->choice_state == 1)
        *menu_scene->map_index = 1;
    if (menu_scene->choice_menu.map_two_btn.state == HOVER &&
    sfMouse_isButtonPressed(sfMouseLeft) && menu_scene->choice_state == 1)
        *menu_scene->map_index = 2;
    if (menu_scene->choice_menu.map_three_btn.state == HOVER &&
    sfMouse_isButtonPressed(sfMouseLeft) && menu_scene->choice_state == 1)
        *menu_scene->map_index = 3;
    if (*menu_scene->map_index != 0) {
        change_map_values(&menu_scene->game_core->play_scene);
        *menu_scene->game_state = PLAY;
    }
}

void volume_selection(menu_scene *scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
    sfRectangleShape *rect = scene->settings_ui.volume_rect;
    float rect_y = sfRectangleShape_getSize(scene->settings_ui.volume_rect).y;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (pos.x >= 1242 && pos.x <= 1744 && pos.y >= 397 && pos.y <= 451) {
            sfMouse_setPositionRenderWindow((sfVector2i){pos.x, 420}, scene->window);
            sfRectangleShape_setSize(rect, (sfVector2f){pos.x - 1242, rect_y});
        }
    }
}

void check_hover_click_settings_menu(menu_scene *menu_scene)
{
    if (menu_scene->settings_ui.close_button.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->settings_ui.close_button.state = CLICKING;
    if (menu_scene->settings_ui.close_button.state == HOVER && menu_scene->event->mouseButton.type == sfEvtMouseButtonReleased && menu_scene->settings_state == 1)
        menu_scene->settings_ui.close_button.state = CLICKED;
    if (menu_scene->settings_state == 1) {
        fps_selection(menu_scene);
        volume_selection(menu_scene);
    }
}

void check_hover_click(menu_scene *menu_scene)
{
    check_hover_click_ui(menu_scene);
    check_hover_click_settings_menu(menu_scene);
    check_hover_click_choice_menu(menu_scene);
}