/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_menu_ui
*/

#include "../../include/my_defender.h"

void i_menu_ui(menu_ui *menu_ui)
{
    menu_ui->play_btn = create_button("img/buttons/play_",
    (sfFloatRect){800, 400, 285, 60});
    sfSprite_setPosition(menu_ui->play_btn.sprite,  menu_ui->play_btn.pos);
    menu_ui->hiscore_btn = create_button("img/buttons/highscores_",
    (sfFloatRect){800, 500, 285, 60});
    sfSprite_setPosition(menu_ui->hiscore_btn.sprite, menu_ui->hiscore_btn.pos);
    menu_ui->settings_btn = create_button("img/buttons/settings_",
    (sfFloatRect){800, 600, 285, 60});
    sfSprite_setPosition(menu_ui->settings_btn.sprite,
    menu_ui->settings_btn.pos);
    menu_ui->quit_btn = create_button("img/buttons/quit_",
    (sfFloatRect){800, 700, 285, 60});
    sfSprite_setPosition(menu_ui->quit_btn.sprite,  menu_ui->quit_btn.pos);
}