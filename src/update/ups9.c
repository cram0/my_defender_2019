/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ups9
*/

#include "../../include/my_defender.h"

void u_turret_click_hud_two(play_scene *scene)
{
    if (scene->dragndrop.display == true) {
        change_origin_dnd(scene);
        change_texture_dnd(scene);
        change_origin_circle(scene);
        change_price_dnd(scene);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
            sfSprite_setPosition(scene->dragndrop.sprite,
            (sfVector2f){pos.x, pos.y});
            sfCircleShape_setPosition(scene->dragndrop.circle,
            (sfVector2f){pos.x, pos.y});
            sfText_setPosition(scene->dragndrop.price_text,
            (sfVector2f){pos.x - 50, pos.y - 100});
        }
    }
}

void u_turret_click_hud_pos_two(play_scene *scene, sfVector2i pos)
{
    if (pos.x >= 1513 && pos.x <= 1588 && pos.y >= 277 && pos.y <= 352 &&
    scene->turret_hud.is_buyable_freeze) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = FREEZE_TURRET;
    }
    if (pos.x >= 1600 && pos.x <= 1675 && pos.y >= 277 && pos.y <= 352 &&
    scene->turret_hud.is_buyable_sniper) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = SNIPER_TURRET;
    }
}

void u_turret_click_hud_pos(play_scene *scene, sfVector2i pos)
{
    if (pos.x >= 1513 && pos.x <= 1588 && pos.y >= 193 && pos.y <= 256 &&
    scene->turret_hud.is_buyable_simple) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = SIMPLE_TURRET;
    }
    if (pos.x >= 1600 && pos.x <= 1675 && pos.y >= 193 && pos.y <= 256 &&
    scene->turret_hud.is_buyable_bomb) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = BOMB_TURRET;
    }
    u_turret_click_hud_pos_two(scene, pos);
}

int set_turret_range(int turret_type)
{
    switch (turret_type) {
        case SIMPLE_TURRET : return (150);
        case BOMB_TURRET : return (90);
        case FREEZE_TURRET : return (100);
        case SNIPER_TURRET : return (900);
        default : return (0);
    }
}

void set_turret_texture(sfSprite *sprite, int turret_type, sfTexture *tx)
{
    sfSprite_setTexture(sprite, tx, sfFalse);
    switch (turret_type) {
        case SIMPLE_TURRET : sfSprite_setTextureRect(sprite,
        (sfIntRect){0, 0, 67, 69});
            break;
        case BOMB_TURRET : sfSprite_setTextureRect(sprite,
        (sfIntRect){0, 167, 73, 83});
            break;
        case FREEZE_TURRET : sfSprite_setTextureRect(sprite,
        (sfIntRect){0, 250, 99, 99});
            break;
        case SNIPER_TURRET : sfSprite_setTextureRect(sprite,
        (sfIntRect){0, 69, 67, 98});
            break;
    }
}