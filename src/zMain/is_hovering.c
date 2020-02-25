/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** is_hovering
*/

#include "../../include/my_defender.h"

bool is_hovering(button button, sfRenderWindow *window)
{
    if ((get_mouse_pos(window).x > button.pos.x && get_mouse_pos(window).x < (button.pos.x + button.width)) &&
    (get_mouse_pos(window).y > button.pos.y && get_mouse_pos(window).y < (button.pos.y + button.height))) {
        return (true);
    }
    return (false);
}