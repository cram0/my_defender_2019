/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_settings_background
*/

#include "../../include/my_defender.h"

void i_settings_background(menu_background *menu_background)
{
    menu_background->sprite = sfSprite_create();
    menu_background->texture = sfTexture_createFromFile
    ("img/menu_scene/settings_bg.png", NULL);
    menu_background->pos = (sfVector2f){1200.0, 300.0};
    sfSprite_setTexture(menu_background->sprite, menu_background->texture,
    sfTrue);
    sfSprite_setPosition(menu_background->sprite, menu_background->pos);
}