/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ips5
*/

#include "../../include/my_defender.h"

void add_wave_existing(play_scene *scene, int index, int *e_list)
{
    scene->waves->index = index;
    scene->waves->texture = scene->enemy_texture;
    for (int i = 0; i < 20; i++)
        add_enemy_node(scene, e_list, i);
    scene->waves->previous = NULL;
    scene->waves->next = NULL;
}

void add_wave_non_existing(play_scene *scene, int index, int *e_list)
{
    while (scene->waves->next != NULL)
        scene->waves = scene->waves->next;
    wave_t *temp = NULL;
    temp = malloc(sizeof(wave_t));
    temp->enemy = NULL;
    temp->enemy = malloc(sizeof(enemy_t));
    temp->enemy->health = -1;
    temp->index = index;
    temp->texture = scene->enemy_texture;
    for (int i = 0; i < 20; i++)
        add_enemy_node(scene, e_list, i);
    scene->waves->next = temp;
    temp->previous = scene->waves;
    temp->next = NULL;
}

void add_wave_node(play_scene *scene, int index, int *e_list)
{
    if (scene->waves->index == -1) {
        add_wave_existing(scene, index, e_list);
    } else {
        add_wave_non_existing(scene, index, e_list);
    }
}

void set_waves(play_scene *scene)
{
    int wave_nb = 10;
    int enemy_list[10][20] =
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}};
    scene->waves->index = -1;
    scene->waves->enemy->health = -1;
    for (int i = 0; i < wave_nb; i++)
        add_wave_node(scene, i, enemy_list[i]);
}

void set_waves_positions_index(enemy_t *enemy, int index)
{
    switch (index) {
        case 1 :
            enemy->pos = (sfVector2f){655 + 235, -90};
            sfSprite_setPosition(enemy->sprite, enemy->pos);
            break;
        case 2 :
            enemy->pos = (sfVector2f){621 + 235, 950};
            sfSprite_setPosition(enemy->sprite, enemy->pos);
            break;
        case 3 :
            enemy->pos = (sfVector2f){184 + 235, -90};
            sfSprite_setPosition(enemy->sprite, enemy->pos);
            break;
    }
}