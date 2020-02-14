/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_menu_scene
*/

#include "../../include/my_defender.h"

button create_button(char *file_path)
{
    button temp;
    temp.sprite = sfSprite_create();
    temp.texture = sfTexture_createFromFile(file_path, NULL);
    temp.pos = (sfVector2f){0, 0};
    temp.state = IDLE;
    return (temp);
}

void i_menu_ui(menu_ui *menu_ui)
{
    menu_ui->play_btn = create_button("img/buttons/play_idle.png");
    menu_ui->hiscore_btn = create_button("img/buttons/highscores_idle.png");
    menu_ui->settings_btn = create_button("img/buttons/settings_idle.png");
    menu_ui->quit_btn = create_button("img/buttons/quit_idle.png");
}

void i_menu_background(menu_background *menu_background)
{
    menu_background->background_sprite = sfSprite_create();
    menu_background->background_texture = sfTexture_createFromFile("img/menu_scene/bg_placeholder.png", NULL);
    menu_background->pos = (sfVector2f){0.0, 0.0};
    sfSprite_setPosition(menu_background->background_sprite, menu_background->pos);
    sfSprite_setTexture(menu_background->background_sprite, menu_background->background_texture, sfTrue);
}

void i_menu_scene(menu_scene *menu_scene, sfRenderWindow *window)
{
    i_menu_background(&menu_scene->menu_background);
}