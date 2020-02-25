/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_button
*/

#include "../../include/my_defender.h"

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