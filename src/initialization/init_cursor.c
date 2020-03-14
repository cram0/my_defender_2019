/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_cursor
*/

#include "../../include/my_defender.h"

void i_cursor(game_core *gc)
{
    sfRenderWindow_setMouseCursorVisible(gc->window, sfFalse);
    gc->mouse_cursor.sprite = sfSprite_create();
    gc->mouse_cursor.texture = sfTexture_createFromFile
    ("img/cursor/cur.png", NULL);
    sfSprite_setTexture(gc->mouse_cursor.sprite, gc->mouse_cursor.texture,
    sfTrue);
    gc->mouse_cursor.pos.x = sfMouse_getPositionRenderWindow(gc->window).x;
    gc->mouse_cursor.pos.y = sfMouse_getPositionRenderWindow(gc->window).y;
}