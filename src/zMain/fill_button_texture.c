/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** fill_button_texture
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