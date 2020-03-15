/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** dgc2
*/

#include "../../include/my_defender.h"

void d_menu_background(menu_background *bg, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, bg->sprite, NULL);
}

void d_choice_menu_btns(choice_menu *choice, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, choice->close_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, choice->map_one_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, choice->map_two_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, choice->map_three_btn.sprite, NULL);
}

void d_choice_menu(menu_scene *menu_scene)
{
    d_choice_menu_bg(&menu_scene->choice_menu.background, menu_scene->window);
    d_choice_menu_btns(&menu_scene->choice_menu, menu_scene->window);
    sfRenderWindow_drawSprite(menu_scene->window,
    menu_scene->choice_menu.difficulty_check.sprite, NULL);
}

void d_menu_scene(menu_scene *menu_scene)
{
    d_menu_background(&menu_scene->menu_background, menu_scene->window);
    d_menu_ui(&menu_scene->ui, menu_scene->window);
    if (menu_scene->settings_state == 1)
        d_settings(menu_scene);
    if (menu_scene->choice_state == 1)
        d_choice_menu(menu_scene);
}

void d_play_hud(play_scene *scene)
{
    sfRenderWindow_drawSprite(scene->window, scene->background.sprite, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->turret_hud.bomb, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->turret_hud.simple, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->turret_hud.freeze, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->turret_hud.sniper, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->pause_btn.sprite, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->wave_btn.sprite, NULL);
}