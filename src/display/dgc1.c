/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** dgc1
*/

#include "../../include/my_defender.h"

void d_menu_ui(menu_ui *ui, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, ui->play_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->hiscore_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->settings_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->quit_btn.sprite, NULL);
}

void d_settings_ui(settings_ui *ui, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, ui->close_button.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->check_mark.sprite, NULL);
    sfRenderWindow_drawRectangleShape(window, ui->volume_rect, NULL);
}

void d_settings_background(settings_ui *ui, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, ui->background.sprite, NULL);
}

void d_settings(menu_scene *menu_scene)
{
    d_settings_background(&menu_scene->settings_ui, menu_scene->window);
    d_settings_ui(&menu_scene->settings_ui, menu_scene->window);
    sfRenderWindow_drawSprite(menu_scene->window, menu_scene->
    settings_ui.pepe_sprite, NULL);
}

void d_choice_menu_bg(simple_entity *background, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, background->sprite, NULL);
}