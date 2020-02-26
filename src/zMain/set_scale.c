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
        case IDLE : sfSprite_setScale(button->sprite, (sfVector2f){0.95, 0.95});
            break;
        case HOVER : sfSprite_setScale(button->sprite, (sfVector2f){1.0, 1.0});
            break;
        case CLICKING : sfSprite_setScale(button->sprite, (sfVector2f){0.90, 0.90});
            break;
    }

}

void setscale_allbuttons(menu_scene *menu_scene)
{
    setscale_state(&menu_scene->opt_ui.close_button);
    setscale_state(&menu_scene->choice_menu.close_btn);
    setscale_state(&menu_scene->ui.hiscore_btn);
    setscale_state(&menu_scene->ui.play_btn);
    setscale_state(&menu_scene->ui.quit_btn);
    setscale_state(&menu_scene->ui.settings_btn);
}