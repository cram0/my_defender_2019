/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ups10
*/

#include "../../include/my_defender.h"

void change_texture_dnd(play_scene *scene)
{
    dragndrop *dnd = &scene->dragndrop;
    if (dnd->turret_selected == SIMPLE_TURRET)
        sfSprite_setTextureRect(dnd->sprite, (sfIntRect){0, 0, 67, 69});
    if (dnd->turret_selected == BOMB_TURRET)
        sfSprite_setTextureRect(dnd->sprite, (sfIntRect){0, 167, 73, 83});
    if (dnd->turret_selected == FREEZE_TURRET)
        sfSprite_setTextureRect(dnd->sprite, (sfIntRect){0, 250, 99, 99});
    if (dnd->turret_selected == SNIPER_TURRET)
        sfSprite_setTextureRect(dnd->sprite, (sfIntRect){0, 69, 67, 98});
}

void change_origin_dnd(play_scene *scene)
{
    dragndrop *dnd = &scene->dragndrop;
    if (dnd->turret_selected == SIMPLE_TURRET)
        sfSprite_setOrigin(dnd->sprite, (sfVector2f){67 / 2, 69 / 2});
    if (dnd->turret_selected == BOMB_TURRET)
        sfSprite_setOrigin(dnd->sprite, (sfVector2f){73 / 2, 83 / 2});
    if (dnd->turret_selected == FREEZE_TURRET)
        sfSprite_setOrigin(dnd->sprite, (sfVector2f){99 / 2, 99 / 2});
    if (dnd->turret_selected == SNIPER_TURRET)
        sfSprite_setOrigin(dnd->sprite, (sfVector2f){67 / 2, 98 / 2});
}

void change_origin_circle(play_scene *scene)
{
    dragndrop *dnd = &scene->dragndrop;
    if (dnd->turret_selected == SIMPLE_TURRET) {
        sfCircleShape_setOrigin(dnd->circle, (sfVector2f){150, 150});
        sfCircleShape_setRadius(dnd->circle, 150);
    }
    if (dnd->turret_selected == BOMB_TURRET) {
        sfCircleShape_setOrigin(dnd->circle, (sfVector2f){90, 90});
        sfCircleShape_setRadius(dnd->circle, 90);
    }
    if (dnd->turret_selected == FREEZE_TURRET) {
        sfCircleShape_setOrigin(dnd->circle, (sfVector2f){100, 100});
        sfCircleShape_setRadius(dnd->circle, 100);
    }
    if (dnd->turret_selected == SNIPER_TURRET) {
        sfCircleShape_setOrigin(dnd->circle, (sfVector2f){900, 900});
        sfCircleShape_setRadius(dnd->circle, 900);
    }
}

void change_price_dnd( play_scene *scene)
{
    dragndrop *dnd = &scene->dragndrop;
    if (dnd->turret_selected == SIMPLE_TURRET) {
        sfText_setString(scene->dragndrop.price_text,
        my_itoa(scene->turret_price.simple, scene->dragndrop.money_str));
    }
    if (dnd->turret_selected == BOMB_TURRET) {
        sfText_setString(scene->dragndrop.price_text,
        my_itoa(scene->turret_price.bomb, scene->dragndrop.money_str2));
    }
    if (dnd->turret_selected == FREEZE_TURRET) {
        sfText_setString(scene->dragndrop.price_text,
        my_itoa(scene->turret_price.freeze, scene->dragndrop.money_str3));
    }
    if (dnd->turret_selected == SNIPER_TURRET) {
        sfText_setString(scene->dragndrop.price_text,
        my_itoa(scene->turret_price.sniper, scene->dragndrop.money_str4));
    }
}