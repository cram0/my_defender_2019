/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** check_hover_click
*/

#include "../../include/my_defender.h"

void check_hover_click_choice_menu(menu_scene *menu_scene)
{
    check_difficulty(menu_scene);
    if (menu_scene->choice_menu.close_btn.state == HOVER &&
    sfMouse_isButtonPressed(sfMouseLeft) && menu_scene->choice_state == 1) {
        menu_scene->choice_menu.close_btn.state = CLICKING;
        if (menu_scene->sound_state == 0) {
            sfSound_play(menu_scene->click_sound.sound);
            menu_scene->sound_state = 1;
        }
    }
    if (menu_scene->choice_menu.close_btn.state == HOVER &&
    menu_scene->event->mouseButton.type == sfEvtMouseButtonReleased &&
    menu_scene->choice_state == 1) {
            menu_scene->choice_menu.close_btn.state = CLICKED;
            menu_scene->sound_state = 0;
    }
    check_hover_click_choice_menu_two(menu_scene);
}

void volume_selection(menu_scene *scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
    sfRectangleShape *rect = scene->settings_ui.volume_rect;
    float rect_y = sfRectangleShape_getSize(scene->settings_ui.volume_rect).y;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (pos.x >= 1242 && pos.x <= 1744 && pos.y >= 397 && pos.y <= 451) {
            sfMouse_setPositionRenderWindow((sfVector2i){pos.x, 420},
            scene->window);
            sfRectangleShape_setSize(rect, (sfVector2f){pos.x - 1242, rect_y});
            sfMusic_setVolume(scene->music, ((pos.x - 1242) * 0.10));
        }
    }
}

void check_hover_click_settings_menu(menu_scene *menu_scene)
{
    if (menu_scene->settings_ui.close_button.state == HOVER &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        menu_scene->settings_ui.close_button.state = CLICKING;
        if (menu_scene->sound_state == 0) {
            sfSound_play(menu_scene->click_sound.sound);
            menu_scene->sound_state = 1;
        }
    }
    if (menu_scene->settings_ui.close_button.state == HOVER &&
    menu_scene->event->mouseButton.type == sfEvtMouseButtonReleased &&
    menu_scene->settings_state == 1) {
        menu_scene->settings_ui.close_button.state = CLICKED;
        menu_scene->sound_state = 0;
    }
    if (menu_scene->settings_state == 1) {
        fps_selection(menu_scene);
        volume_selection(menu_scene);
    }
}

void check_hover_click(menu_scene *menu_scene)
{
    if (menu_scene->settings_state == 0 && menu_scene->choice_state == 0)
        check_hover_click_ui(menu_scene);
    if (menu_scene->settings_state == 1 && menu_scene->choice_state == 0)
        check_hover_click_settings_menu(menu_scene);
    if (menu_scene->choice_state == 1 && menu_scene->settings_state == 0)
        check_hover_click_choice_menu(menu_scene);
}