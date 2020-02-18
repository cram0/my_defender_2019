/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** set_simple_entity
*/

#include "../../include/my_defender.h"

simple_entity set_simple_entity(char *pathname, sfFloatRect size)
{
    simple_entity temp;
    temp.sprite = sfSprite_create();
    temp.texture = sfImage_createFromFile(pathname);
    sfSprite_setTexture(temp.sprite, temp.texture, sfTrue);
    temp.pos.x = size.left;
    temp.pos.y = size.top;
    temp.width = size.width;
    temp.height = size.height;
}