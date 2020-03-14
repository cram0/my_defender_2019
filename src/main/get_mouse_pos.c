/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** get_mouse_pos
*/

#include "../../include/my_defender.h"

sfVector2i get_mouse_pos(sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    return cursor;
}