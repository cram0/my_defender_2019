/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_dragndrop
*/

#include "../../include/my_defender.h"

void i_dragndrop(play_scene *scene)
{
    scene->dragndrop.sprite = sfSprite_create();
    scene->dragndrop.texture = sfTexture_createFromFile
    ("img/play_scene/towers/turrets.png", NULL);
    sfSprite_setTexture(scene->dragndrop.sprite, scene->dragndrop.texture,
    sfFalse);
    scene->dragndrop.display = false;
    scene->dragndrop.turret_selected = -1;
    scene->dragndrop.pos = (sfVector2f){0, 0};
    scene->dragndrop.circle = sfCircleShape_create();
    sfCircleShape_setFillColor(scene->dragndrop.circle,
    sfColor_fromRGBA(255, 255, 255, 128));
    set_dnd_texts(scene);
}