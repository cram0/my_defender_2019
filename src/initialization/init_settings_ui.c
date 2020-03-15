/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_settings_ui
*/

#include "../../include/my_defender.h"

void u_pepe_ui(settings_ui *ui)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(ui->pepe_clock)) >= 0.085) {
        if (ui->pepe_rect.left == 200 * 3)
            ui->pepe_rect.left = 0;
        sfSprite_setTextureRect(ui->pepe_sprite, ui->pepe_rect);
        ui->pepe_rect.left += 200;
        sfClock_restart(ui->pepe_clock);
    }
}

void i_settings_ui(settings_ui *ui)
{
    ui->pepe_sprite = sfSprite_create();
    ui->pepe_txt = sfTexture_createFromFile("img/menu_scene/pepe.png", NULL);
    ui->pepe_clock = sfClock_create();
    ui->gen_clock = sfClock_create();
    ui->pepe_rect = (sfIntRect){0, 0, 200, 193};
    sfSprite_setTexture(ui->pepe_sprite, ui->pepe_txt, sfFalse);
    sfSprite_setTextureRect(ui->pepe_sprite, ui->pepe_rect);
    sfSprite_setPosition(ui->pepe_sprite, (sfVector2f){1920 - 200, 1030 - 193});
    i_settings_background(&ui->background);
    ui->close_button = create_button("img/in_game_buttons/close_",
    (sfFloatRect){1730.0, 280.0, 75, 75});
    ui->check_mark = set_simple_entity("img/menu_scene/checked.png",
    (sfFloatRect){1357, 560, 48, 50});
    ui->volume_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(ui->volume_rect, (sfVector2f){1242, 397});
    sfRectangleShape_setSize(ui->volume_rect, (sfVector2f){250, 54});
}