/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_settings_ui
*/

#include "../../include/my_defender.h"

void i_settings_ui(settings_ui *ui)
{
    i_settings_background(&ui->background);
    ui->close_button = create_button("img/in_game_buttons/close_", (sfFloatRect){1730.0, 280.0, 75, 75});
    ui->check_mark = set_simple_entity("img/menu_scene/checked.png", (sfFloatRect){1357, 560, 48, 50});
    ui->volume_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(ui->volume_rect, (sfVector2f){1242, 397});
    sfRectangleShape_setSize(ui->volume_rect, (sfVector2f){250, 54});
}