/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_play_scene
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

void u_turret_click_hud_two(play_scene *scene)
{
    if (scene->dragndrop.display == true) {
        change_origin_dnd(scene);
        change_texture_dnd(scene);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
            sfSprite_setPosition(scene->dragndrop.sprite, (sfVector2f){pos.x, pos.y});
            printf("DEBUG SPRITE POS X : %f, Y : %f\n", sfSprite_getPosition(scene->dragndrop.sprite).x ,sfSprite_getPosition(scene->dragndrop.sprite).y);
            printf("POS X %d, POS Y %d\n", pos.x, pos.y);
        }
    }
}

void u_turret_click_hud_pos_two(play_scene *scene, sfVector2i pos)
{
    if (pos.x >= 1513 && pos.x <= 1588 && pos.y >= 277 && pos.y <= 352 && scene->turret_hud.is_buyable_freeze) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = FREEZE_TURRET;
    }
    if (pos.x >= 1600 && pos.x <= 1675 && pos.y >= 277 && pos.y <= 352 && scene->turret_hud.is_buyable_sniper) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = SNIPER_TURRET;
    }
}

void u_turret_click_hud_pos(play_scene *scene, sfVector2i pos)
{
    if (pos.x >= 1513 && pos.x <= 1588 && pos.y >= 193 && pos.y <= 256 && scene->turret_hud.is_buyable_simple) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = SIMPLE_TURRET;
    }
    if (pos.x >= 1600 && pos.x <= 1675 && pos.y >= 193 && pos.y <= 256 && scene->turret_hud.is_buyable_bomb) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = BOMB_TURRET;
    }
    u_turret_click_hud_pos_two(scene, pos);
}

void u_turret_click_hud(play_scene *scene)
{
    if (scene->event->mouseButton.type == sfEvtMouseButtonPressed) {
        sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
        u_turret_click_hud_pos(scene, pos);
    }
    if (scene->event->mouseButton.type == sfEvtMouseButtonReleased)
        scene->dragndrop.display = false;
    u_turret_click_hud_two(scene);
}

void u_hud(play_scene *scene)
{
    u_turret_hud(scene);
    u_turret_click_hud(scene);
}

void u_play_scene(play_scene *scene)
{
    u_hud(scene);
}