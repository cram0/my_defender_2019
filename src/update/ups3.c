/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ups3
*/

#include "../../include/my_defender.h"

void u_enemy_damage_map(play_scene *scene)
{
    if (scene->map.map_index == 1 && scene->waves->enemy->index_reached == 13 &&
    scene->waves->enemy->health > 0) {
        scene->player_infos.health -= 1;
        scene->waves->enemy->health = 0;
    }
    if (scene->map.map_index == 2 && scene->waves->enemy->index_reached == 62 &&
    scene->waves->enemy->health > 0) {
        scene->player_infos.health -= 1;
        scene->waves->enemy->health = 0;
    }
    if (scene->map.map_index == 3 && scene->waves->enemy->index_reached == 16 &&
    scene->waves->enemy->health > 0) {
        scene->player_infos.health -= 1;
        scene->waves->enemy->health = 0;
    }
}

void u_enemy_damage(play_scene *scene)
{
    while (scene->waves->previous != NULL)
        scene->waves = scene->waves->previous;
    while (scene->waves->next != NULL) {
        while (scene->waves->enemy->previous != NULL)
            scene->waves->enemy = scene->waves->enemy->previous;
        while (scene->waves->enemy->next != NULL) {
            u_enemy_damage_map(scene);
            scene->waves->enemy = scene->waves->enemy->next;
        }
        u_enemy_damage_map(scene);
        scene->waves = scene->waves->next;
    }
}

void u_waves_hpbar(enemy_t *enemy)
{
    sfRectangleShape_setPosition(enemy->hbar_max,
    (sfVector2f){enemy->pos.x, enemy->pos.y - 30});
    sfRectangleShape_setPosition(enemy->hbar,
    (sfVector2f){enemy->pos.x, enemy->pos.y - 30});
    sfRectangleShape_setSize(enemy->hbar,
    (sfVector2f){(enemy->health / enemy->max_health) * 40, 7});
}

void u_waves_health(play_scene *scene)
{
    while (scene->waves->previous != NULL)
        scene->waves = scene->waves->previous;
    while (scene->waves->next != NULL) {
        while (scene->waves->enemy->previous != NULL)
            scene->waves->enemy = scene->waves->enemy->previous;
        while (scene->waves->enemy->next != NULL) {
            u_waves_hpbar(scene->waves->enemy);
            scene->waves->enemy = scene->waves->enemy->next;
        }
        u_waves_hpbar(scene->waves->enemy);
        scene->waves = scene->waves->next;
    }
}