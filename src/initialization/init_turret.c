/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_turret
*/

#include "../../include/my_defender.h"

void i_turret_hud_two(play_scene *scene)
{
    turret_hud *hud = &scene->turret_hud;
    hud->simple = sfSprite_create();
    hud->bomb = sfSprite_create();
    hud->freeze = sfSprite_create();
    hud->sniper = sfSprite_create();
    sfSprite_setTexture(hud->simple, hud->sheet, sfTrue);
    sfSprite_setTexture(hud->bomb, hud->sheet, sfTrue);
    sfSprite_setTexture(hud->freeze, hud->sheet, sfTrue);
    sfSprite_setTexture(hud->sniper, hud->sheet, sfTrue);
    sfSprite_setTextureRect(hud->simple, (sfIntRect){79, 0, 79, 86});
    sfSprite_setTextureRect(hud->bomb, (sfIntRect){74, 86, 73, 85});
    sfSprite_setTextureRect(hud->freeze, (sfIntRect){66, 171, 67, 78});
    sfSprite_setTextureRect(hud->sniper, (sfIntRect){71, 249, 71, 113});
    sfSprite_setOrigin(hud->simple, (sfVector2f){79 / 2, 86 / 2});
    sfSprite_setOrigin(hud->bomb, (sfVector2f){73 / 2, 85 / 2});
    sfSprite_setOrigin(hud->freeze, (sfVector2f){67 / 2, 78 / 2});
    sfSprite_setOrigin(hud->sniper, (sfVector2f){71 / 2, 113 / 2});
}

void i_turret_hud(play_scene *scene)
{
    turret_hud *hud = &scene->turret_hud;
    hud->sheet =
    sfTexture_createFromFile("img/play_scene/in_game/turret_hud.png", NULL);
    i_turret_hud_two(scene);
    sfSprite_setPosition(hud->simple, (sfVector2f){1551, 225});
    sfSprite_setPosition(hud->bomb, (sfVector2f){1638, 225});
    sfSprite_setPosition(hud->freeze, (sfVector2f){1552, 309});
    sfSprite_setPosition(hud->sniper, (sfVector2f){1638, 309});
}

void i_turrets_price(play_scene *scene)
{
    scene->turret_price.simple = 100;
    scene->turret_price.freeze = 75;
    scene->turret_price.bomb = 200;
    scene->turret_price.sniper = 250;
}