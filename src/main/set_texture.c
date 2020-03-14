/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** set_texture
*/

#include "../../include/my_defender.h"

void settexture_state(button *button)
{
    switch (button->state) {
        case IDLE : sfSprite_setTexture(button->sprite, button->texture_idle,
        sfTrue);
            break;
        case HOVER : sfSprite_setTexture(button->sprite, button->texture_hover,
        sfTrue);
            break;
        case CLICKING : sfSprite_setTexture(button->sprite,
        button->texture_click, sfTrue);
            break;
    }
}

void settexture_allbuttons(menu_scene *menu_scene)
{
    settexture_state(&menu_scene->ui.play_btn);
    settexture_state(&menu_scene->ui.hiscore_btn);
    settexture_state(&menu_scene->ui.settings_btn);
    settexture_state(&menu_scene->ui.quit_btn);
    settexture_state(&menu_scene->settings_ui.close_button);
    settexture_state(&menu_scene->choice_menu.close_btn);
    settexture_state(&menu_scene->choice_menu.map_one_btn);
    settexture_state(&menu_scene->choice_menu.map_two_btn);
    settexture_state(&menu_scene->choice_menu.map_three_btn);
}