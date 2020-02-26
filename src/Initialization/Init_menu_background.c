/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_menu_background
*/

#include "../../include/my_defender.h"

void i_menu_background(menu_background *menu_background)
{
    menu_background->background_sprite = sfSprite_create();
    menu_background->background_texture = sfTexture_createFromFile("img/menu_scene/background.png", NULL);
    menu_background->pos = (sfVector2f){0.0, 0.0};
    sfSprite_setTexture(menu_background->background_sprite, menu_background->background_texture, sfTrue);
    sfSprite_setPosition(menu_background->background_sprite, menu_background->pos);
}