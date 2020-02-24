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

button create_button(char *file_path, sfFloatRect rect)
{
    button temp;
    temp.sprite = sfSprite_create();
    fill_button_textures(&temp, file_path);
    temp.pos.x = rect.left;
    temp.pos.y  = rect.top;
    temp.state = IDLE;
    sfSprite_setPosition(temp.sprite, temp.pos);
    sfSprite_setTexture(temp.sprite, temp.texture_idle, sfTrue);
    temp.height = rect.height;
    temp.width = rect.width;
    return (temp);
}

void i_menu_ui(menu_ui *menu_ui)
{
    menu_ui->play_btn = create_button("img/buttons/play_", (sfFloatRect){800, 400, 285, 60});
    sfSprite_setPosition(menu_ui->play_btn.sprite,  menu_ui->play_btn.pos);
    menu_ui->hiscore_btn = create_button("img/buttons/highscores_", (sfFloatRect){800, 500, 285, 60});
    sfSprite_setPosition(menu_ui->hiscore_btn.sprite, menu_ui->hiscore_btn.pos);
    menu_ui->settings_btn = create_button("img/buttons/settings_", (sfFloatRect){800, 600, 285, 60});
    sfSprite_setPosition(menu_ui->settings_btn.sprite,
    menu_ui->settings_btn.pos);
    menu_ui->quit_btn = create_button("img/buttons/quit_", (sfFloatRect){800, 700, 285, 60});
    sfSprite_setPosition(menu_ui->quit_btn.sprite,  menu_ui->quit_btn.pos);
}

void i_opt_background(menu_background *menu_background)
{
    menu_background->background_sprite = sfSprite_create();
    menu_background->background_texture = sfTexture_createFromFile("img/menu_scene/settings_bg.png", NULL);
    menu_background->pos = (sfVector2f){570.0, 210.0};
    sfSprite_setTexture(menu_background->background_sprite, menu_background->background_texture, sfTrue);
    sfSprite_setPosition(menu_background->background_sprite, menu_background->pos);
    sfSprite_setScale(menu_background->background_sprite, (sfVector2f){1.35, 1.35});
}

void i_fps_background(menu_background *menu_background)
{
    menu_background->background_sprite = sfSprite_create();
    menu_background->background_texture = sfTexture_createFromFile("img/menu_scene/fps_bg.png", NULL);
    menu_background->pos = (sfVector2f){720.0, 320.0};
    sfSprite_setTexture(menu_background->background_sprite, menu_background->background_texture, sfTrue);
    sfSprite_setPosition(menu_background->background_sprite, menu_background->pos);
    sfSprite_setScale(menu_background->background_sprite, (sfVector2f){0.40, 0.40});
}

void i_settings_ui(settings_ui *opt_ui)
{
    i_opt_background(&opt_ui->background);
    i_fps_background(&opt_ui->fps_bg);
    opt_ui->close_button = create_button("img/in_game_buttons/close_", (sfFloatRect){1220.0, 280.0, 75, 75});
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

void i_choice_menu(choice_menu *choice_menu)
{
    choice_menu->background = set_simple_entity("img/menu_scene/choice_menu/choice_menu_bg.png", (sfFloatRect){200, 50, 1521, 900});
    choice_menu->close_btn = create_button("img/buttons/close_", (sfFloatRect){1600, 100, 64, 64});
    choice_menu->map_one_btn = create_button("img/menu_scene/choice_menu/map1_",(sfFloatRect){400, 200, 300, 200});
    choice_menu->map_two_btn = create_button("img/menu_scene/choice_menu/map2_",(sfFloatRect){800, 200, 300, 200});
    choice_menu->map_three_btn = create_button("img/menu_scene/choice_menu/map3_",(sfFloatRect){1200, 200, 300, 200});
}

void i_menu_scene(menu_scene *menu_scene, sfRenderWindow *window)
{
    menu_scene->window = window;
    menu_scene->opt_state = 0;
    i_menu_background(&menu_scene->menu_background);
    i_settings_ui(&menu_scene->opt_ui);
    i_menu_ui(&menu_scene->ui);
    i_choice_menu(&menu_scene->choice_menu);
}