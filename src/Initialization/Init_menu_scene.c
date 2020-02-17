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
    temp.pos = (sfVector2f){500, 500};
    temp.state = IDLE;
    sfSprite_setPosition(temp.sprite, temp.pos);
    sfSprite_setTexture(temp.sprite, temp.texture, sfTrue);
    return (temp);
}

void i_menu_ui(menu_ui *menu_ui)
{
    menu_ui->play_btn = create_button("img/buttons/play_");
    menu_ui->hiscore_btn = create_button("img/buttons/highscores_");
    menu_ui->settings_btn = create_button("img/buttons/settings_");
    menu_ui->quit_btn = create_button("img/buttons/quit_");
}

void i_menu_background(menu_background *menu_background)
{
    menu_background->background_sprite = sfSprite_create();
    menu_background->background_texture = sfTexture_createFromFile("img/menu_scene/bg_placeholder.png", NULL);
    menu_background->pos = (sfVector2f){0.0, 0.0};
    sfSprite_setTexture(menu_background->background_sprite, menu_background->background_texture, sfTrue);
    sfSprite_setPosition(menu_background->background_sprite, menu_background->pos);
}

void i_menu_scene(menu_scene *menu_scene, sfRenderWindow *window)
{
    menu_scene->window = window;
    i_menu_background(&menu_scene->menu_background);
    i_menu_ui(&menu_scene->ui);
}