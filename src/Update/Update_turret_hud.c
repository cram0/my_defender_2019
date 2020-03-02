/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_turret_hud
*/

#include "../../include/my_defender.h"

void u_turret_hud_money(play_scene *scene)
{
    if (scene->player_infos.money < scene->turret_price.simple)
        scene->turret_hud.is_buyable_simple = false;
    else
        scene->turret_hud.is_buyable_simple = true;
    if (scene->player_infos.money < scene->turret_price.bomb)
        scene->turret_hud.is_buyable_bomb = false;
    else
        scene->turret_hud.is_buyable_bomb = true;
    if (scene->player_infos.money < scene->turret_price.freeze)
        scene->turret_hud.is_buyable_freeze = false;
    else
        scene->turret_hud.is_buyable_freeze = true;
    if (scene->player_infos.money < scene->turret_price.sniper)
        scene->turret_hud.is_buyable_sniper = false;
    else
        scene->turret_hud.is_buyable_sniper = true;
}

void check_is_buyable(play_scene *scene)
{
    if (scene->turret_hud.is_buyable_simple)
        sfSprite_setTextureRect(scene->turret_hud.simple, (sfIntRect){0, 0, 79,
        86});
    if (scene->turret_hud.is_buyable_bomb)
        sfSprite_setTextureRect(scene->turret_hud.bomb, (sfIntRect){0, 86, 74,
        85});
    if (scene->turret_hud.is_buyable_freeze)
        sfSprite_setTextureRect(scene->turret_hud.freeze, (sfIntRect){0, 171,
        66, 79});
    if (scene->turret_hud.is_buyable_sniper)
        sfSprite_setTextureRect(scene->turret_hud.sniper, (sfIntRect){0, 250,
        71, 113});
}

void check_is_n_buyable(play_scene *scene)
{
    if (!scene->turret_hud.is_buyable_simple)
        sfSprite_setTextureRect(scene->turret_hud.simple, (sfIntRect){79, 0, 79,
        86});
    if (!scene->turret_hud.is_buyable_bomb)
        sfSprite_setTextureRect(scene->turret_hud.bomb, (sfIntRect){74, 86, 73, 85});
    if (!scene->turret_hud.is_buyable_freeze)
        sfSprite_setTextureRect(scene->turret_hud.freeze, (sfIntRect){66, 171, 67, 78});
    if (!scene->turret_hud.is_buyable_sniper)
        sfSprite_setTextureRect(scene->turret_hud.sniper, (sfIntRect){71, 249, 71, 113});
}

void u_turret_hud(play_scene *scene)
{
    u_turret_hud_money(scene);
    check_is_buyable(scene);
    check_is_n_buyable(scene);
}