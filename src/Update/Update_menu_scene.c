/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_menu_scene
*/

#include "../../include/my_defender.h"

bool is_hovering(button button, sfRenderWindow *window)
{
    if ((get_mouse_pos(window).x > button.pos.x && get_mouse_pos(window).x < (button.pos.x + 285)) &&
    (get_mouse_pos(window).y > button.pos.y && get_mouse_pos(window).y < (button.pos.y + 60))) {
        return (true);
    }
    return (false);
}

sfVector2i get_mouse_pos(sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    return cursor;
}

void button_mouse_interaction(menu_scene *menu_scene)
{

}

void hovering_button(menu_scene *menu_scene)
{
    if (is_hovering(menu_scene->ui.play_btn, menu_scene->window)) {
        menu_scene->ui.play_btn.state = HOVER;
    }
    if (is_hovering(menu_scene->ui.hiscore_btn, menu_scene->window)) {
        menu_scene->ui.hiscore_btn.state = HOVER;
    }
    if (is_hovering(menu_scene->ui.quit_btn, menu_scene->window)) {
        menu_scene->ui.quit_btn.state = HOVER;
    }
    if (is_hovering(menu_scene->ui.settings_btn, menu_scene->window)) {
        menu_scene->ui.settings_btn.state = HOVER;
    }
}

void u_menu_scene(menu_scene *menu_scene)
{
    hovering_button(menu_scene);
    button_mouse_interaction(menu_scene);
}