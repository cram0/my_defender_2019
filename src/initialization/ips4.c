/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ips4
*/

#include "../../include/my_defender.h"

void set_txt_en_rect(sfSprite *sprite, sfTexture *texture, sfIntRect rect)
{
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
}

void set_texture_enemy(sfSprite *sprite, sfTexture *texture, int e_list)
{
    switch (e_list) {
        case 1 : set_txt_en_rect(sprite, texture, (sfIntRect){0, 0, 49, 65});
            break;
        case 2 : set_txt_en_rect(sprite, texture, (sfIntRect){49, 0, 50, 65});
            break;
        case 3 : set_txt_en_rect(sprite, texture, (sfIntRect){99, 0, 49, 65});
            break;
        case 4 : set_txt_en_rect(sprite, texture, (sfIntRect){148, 0, 49, 65});
            break;
        case 5 : set_txt_en_rect(sprite, texture, (sfIntRect){197, 0, 49, 65});
            break;
        case 6 : set_txt_en_rect(sprite, texture, (sfIntRect){246, 0, 50, 65});
            break;
        case 7 : set_txt_en_rect(sprite, texture, (sfIntRect){296, 0, 49, 65});
            break;
        case 8 : set_txt_en_rect(sprite, texture, (sfIntRect){345, 0, 49, 65});
            break;
    }
}

void add_enemy_node_non_existing(play_scene *scene, int *e_list, int index)
{
    scene->waves->enemy->sprite = sfSprite_create();
    scene->waves->enemy->hitbox = (sfIntRect){0, 0, 49, 65};
    set_texture_enemy(scene->waves->enemy->sprite, scene->waves->texture,
    e_list[index]);
    sfSprite_setOrigin(scene->waves->enemy->sprite,
    (sfVector2f){49 / 2, 65 / 2});
    scene->waves->enemy->moving = false;
    scene->waves->enemy->index_reached = -1;
    scene->waves->enemy->pos = (sfVector2f){-1000, -1000};
    scene->waves->enemy->hitbox = (sfIntRect){0, 0, 49, 65};
    scene->waves->enemy->health = set_enemy_health(e_list[index]);
    scene->waves->enemy->max_health = set_enemy_health(e_list[index]);
    scene->waves->enemy->type = e_list[index];
    set_hbars_enemy(scene->waves->enemy);
    scene->waves->enemy->previous = NULL;
    scene->waves->enemy->next = NULL;
}

void add_enemy_node_existing(play_scene *scene, int *e_list, int index)
{
    while (scene->waves->enemy->next != NULL)
        scene->waves->enemy = scene->waves->enemy->next;
    enemy_t *temp = NULL;
    temp = malloc(sizeof(enemy_t));
    temp->sprite = sfSprite_create();
    set_texture_enemy(temp->sprite, scene->waves->texture, e_list[index]);
    sfSprite_setOrigin(temp->sprite, (sfVector2f){49 / 2, 65 / 2});
    temp->moving = false;
    temp->pos = (sfVector2f){-1000, -1000};
    temp->hitbox = (sfIntRect){0, 0, 49, 65};
    temp->type = e_list[index];
    temp->health = set_enemy_health(e_list[index]);
    temp->max_health = set_enemy_health(e_list[index]);
    temp->index_reached = -1;
    set_hbars_enemy(temp);
    scene->waves->enemy->next = temp;
    temp->previous = scene->waves->enemy;
    temp->next = NULL;
}

void add_enemy_node(play_scene *scene, int *e_list, int index)
{
    if (scene->waves->enemy->health == -1)
        add_enemy_node_non_existing(scene, e_list, index);
    else
        add_enemy_node_existing(scene, e_list, index);
}