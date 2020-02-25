/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** set_scale
*/

#include "../../include/my_defender.h"

void setscale_state(button *button)
{
    switch (button->state) {
        case IDLE : sfSprite_setScale(button->sprite, (sfVector2f){1.0, 1.0});
            break;
        case HOVER : sfSprite_setScale(button->sprite, (sfVector2f){1.15, 1.15});
            break;
        case CLICK : sfSprite_setScale(button->sprite, (sfVector2f){0.85, 0.85});
            break;
    }

}

void setscale_allbuttons(menu_scene *menu_scene)
{
    setscale_state(&menu_scene->opt_ui.close_button);
    setscale_state(&menu_scene->choice_menu.close_btn);
}