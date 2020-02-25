/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_settings_ui
*/

#include "../../include/my_defender.h"

void i_settings_ui(settings_ui *opt_ui)
{
    i_opt_background(&opt_ui->background);
    i_fps_background(&opt_ui->fps_bg);
    opt_ui->close_button = create_button("img/in_game_buttons/close_", (sfFloatRect){1220.0, 280.0, 75, 75});
    sfSprite_setPosition(opt_ui->close_button.sprite, opt_ui->close_button.pos);
}