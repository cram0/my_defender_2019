/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ups8
*/

#include "../../include/my_defender.h"

void set_turret_origin(sfSprite *sprite, int type)
{
    switch (type) {
        case SIMPLE_TURRET : sfSprite_setOrigin(sprite,
        (sfVector2f){67 / 2, 69 / 2});
            break;
        case BOMB_TURRET : sfSprite_setOrigin(sprite,
        (sfVector2f){73 / 2, 83 / 2});
            break;
        case FREEZE_TURRET : sfSprite_setOrigin(sprite,
        (sfVector2f){99 / 2, 99 / 2});
            break;
        case SNIPER_TURRET : sfSprite_setOrigin(sprite,
        (sfVector2f){67 / 2, 98 / 2});
            break;
    }
}

void add_turret_node_existing(play_scene *scene, int type, sfVector2i pos,
sfTexture *tx)
{
    scene->turrets_placed.turrets->sprite = sfSprite_create();
    scene->turrets_placed.turrets->pos = (sfVector2f){pos.x, pos.y};
    set_turret_texture(scene->turrets_placed.turrets->sprite, type, tx);
    set_turret_origin(scene->turrets_placed.turrets->sprite, type);
    sfSprite_setPosition(scene->turrets_placed.turrets->sprite,
    scene->turrets_placed.turrets->pos);
    scene->turrets_placed.turrets->type = type;
    scene->turrets_placed.turrets->range = set_turret_range(type);
    scene->turrets_placed.turrets->can_attack = true;
    scene->turrets_placed.turrets->previous = NULL;
    scene->turrets_placed.turrets->next = NULL;
}

void add_turret_node_non_existing(play_scene *scene, int type, sfVector2i pos,
sfTexture *tx)
{
    turret_t *temp = NULL;
    temp = malloc(sizeof(turret_t));
    while (scene->turrets_placed.turrets->next != NULL)
        scene->turrets_placed.turrets = scene->turrets_placed.turrets->next;
    temp->sprite = sfSprite_create();
    temp->pos = (sfVector2f){pos.x, pos.y};
    set_turret_texture(temp->sprite, type, tx);
    set_turret_origin(temp->sprite, type);
    sfSprite_setPosition(temp->sprite, temp->pos);
    temp->type = type;
    temp->range = set_turret_range(type);
    temp->can_attack = true;
    scene->turrets_placed.turrets->next = temp;
    temp->previous = scene->turrets_placed.turrets;
    temp->next = NULL;
}

void add_turret_node(play_scene *scene, int type, sfVector2i pos, sfTexture *tx)
{
    if (scene->turrets_placed.turrets->range == -1) {
        add_turret_node_existing(scene, type, pos, tx);
    } else {
        add_turret_node_non_existing(scene, type, pos, tx);
    }
}

void place_turret(play_scene *scene, int type, sfVector2i pos, sfTexture *tx)
{
    switch (type) {
        case SIMPLE_TURRET : add_turret_node(scene, SIMPLE_TURRET, pos, tx);
            break;
        case BOMB_TURRET : add_turret_node(scene, BOMB_TURRET, pos, tx);
            break;
        case FREEZE_TURRET : add_turret_node(scene, FREEZE_TURRET, pos, tx);
            break;
        case SNIPER_TURRET : add_turret_node(scene, SNIPER_TURRET, pos, tx);
            break;
    }
}