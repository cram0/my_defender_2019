/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** d_game_core
*/

#include "../../include/my_defender.h"

void d_menu_ui(menu_ui *ui, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, ui->play_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->hiscore_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->settings_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->quit_btn.sprite, NULL);
}

void d_menu_background(menu_background *bg, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, bg->background_sprite, NULL);
}

void d_menu_scene(menu_scene *menu_scene)
{
    d_menu_background(&menu_scene->menu_background, menu_scene->window);
    d_menu_ui(&menu_scene->ui, menu_scene->window);
}

void d_game_core(game_core *game_core, sfRenderWindow *window)
{
    d_menu_scene(&game_core->menu_scene);
    sfRenderWindow_display(window);
}