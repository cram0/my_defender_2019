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
    temp.height = rect.height;
    temp.width = rect.width;
    temp.pos.x = rect.left + (rect.width / 2);
    temp.pos.y  = rect.top + (rect.height / 2);
    temp.state = IDLE;
    sfSprite_setOrigin(temp.sprite, (sfVector2f){rect.width / 2, rect.height / 2});
    sfSprite_setPosition(temp.sprite, temp.pos);
    sfSprite_setTexture(temp.sprite, temp.texture_idle, sfTrue);
    return (temp);
}