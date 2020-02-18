/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_menu_scene
*/

#include "../../include/my_defender.h"

void fill_button_textures(button *button, char *file_path)
{
    char name_idle[256] = {0};
    char name_hover[256] = {0};
    char name_click[256] = {0};
    my_strcat(name_idle, file_path);
    my_strcat(name_idle, "idle.png");
    my_strcat(name_hover, file_path);
    my_strcat(name_hover, "hover.png");
    my_strcat(name_click, file_path);
    my_strcat(name_click, "click.png");
    button->texture_idle = sfTexture_createFromFile(name_idle, NULL);
    button->texture_hover = sfTexture_createFromFile(name_hover, NULL);
    button->texture_click = sfTexture_createFromFile(name_click, NULL);
}

button create_button(char *file_path)
{
    button temp;
    temp.sprite = sfSprite_create();
    fill_button_textures(&temp, file_path);
    temp.pos = (sfVector2f){500, 500};
    temp.state = IDLE;
    sfSprite_setPosition(temp.sprite, temp.pos);
    sfSprite_setTexture(temp.sprite, temp.texture_idle, sfTrue);
    return (temp);
}

void i_menu_ui(menu_ui *menu_ui)
{
    menu_ui->play_btn = create_button("img/buttons/play_");
    menu_ui->play_btn.pos = (sfVector2f){50, 600};
    sfSprite_setPosition(menu_ui->play_btn.sprite,  menu_ui->play_btn.pos);
    menu_ui->hiscore_btn = create_button("img/buttons/highscores_");
    menu_ui->hiscore_btn.pos = (sfVector2f){50, 700};
    sfSprite_setPosition(menu_ui->hiscore_btn.sprite,  menu_ui->hiscore_btn.pos)
    ;
    menu_ui->settings_btn = create_button("img/buttons/settings_");
    menu_ui->settings_btn.pos = (sfVector2f){50, 800};
    sfSprite_setPosition(menu_ui->settings_btn.sprite,
    menu_ui->settings_btn.pos);
    menu_ui->quit_btn = create_button("img/buttons/quit_");
    menu_ui->quit_btn.pos = (sfVector2f){50, 900};
    sfSprite_setPosition(menu_ui->quit_btn.sprite,  menu_ui->quit_btn.pos);
}

void i_opt_background(menu_background *menu_background)
{
    menu_background->background_sprite = sfSprite_create();
    menu_background->background_texture = sfTexture_createFromFile("img/menu_scene/paper-cartoon.png", NULL);
    menu_background->pos = (sfVector2f){650.0, 210.0};
    sfSprite_setTexture(menu_background->background_sprite, menu_background->background_texture, sfTrue);
    sfSprite_setPosition(menu_background->background_sprite, menu_background->pos);
}

void i_fps_background(menu_background *menu_background)
{
    menu_background->background_sprite = sfSprite_create();
    menu_background->background_sprite = sfSprite_create();
    menu_background->background_texture = sfTexture_createFromFile("img/menu_scene/fps_bg.png", NULL);
    menu_background->pos = (sfVector2f){750.0, 280.0};
    sfSprite_setTexture(menu_background->background_sprite, menu_background->background_texture, sfTrue);
    sfSprite_setPosition(menu_background->background_sprite, menu_background->pos);
}

void i_settings_ui(settings_ui *opt_ui)
{
    i_opt_background(&opt_ui->background);
    i_fps_background(&opt_ui->fps_bg);
    opt_ui->close_button = create_button("img/buttons/close_");
    opt_ui->close_button.pos = (sfVector2f){1090.0, 320.0};
    sfSprite_setPosition(opt_ui->close_button.sprite, opt_ui->close_button.pos);
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
    i_settings_ui(&menu_scene->opt_ui);
    i_menu_ui(&menu_scene->ui);
}