/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ups11
*/

#include "../../include/my_defender.h"

void u_tt_bloon(play_scene *scene)
{
    if (is_the_ballons_in_map(scene->waves->enemy)) {
        u_turret_direction(scene->waves->enemy, scene->turrets_placed.turrets);
        u_turret_attack(scene->waves->enemy, scene->turrets_placed.turrets,
        scene->attack_clock);
    }
}

void u_tt_three(play_scene *scene)
{
    while (scene->waves->enemy->previous != NULL) {
        if (is_the_ballons_in_map(scene->waves->enemy)) {
            u_turret_direction(scene->waves->enemy,
            scene->turrets_placed.turrets);
            u_turret_attack(scene->waves->enemy,
            scene->turrets_placed.turrets, scene->attack_clock);
            u_turret_direction(scene->waves->enemy,
            scene->turrets_placed.turrets->next);
            u_turret_attack(scene->waves->enemy,
            scene->turrets_placed.turrets->next, scene->attack_clock);
        }
        scene->waves->enemy = scene->waves->enemy->previous;
    }
}

void u_tt_two(play_scene *scene)
{
    while (scene->turrets_placed.turrets->next != NULL) {
        while (scene->waves->previous != NULL)
            scene->waves = scene->waves->previous;
        while (scene->waves->next != NULL) {
            while (scene->waves->enemy->next != NULL)
                scene->waves->enemy = scene->waves->enemy->next;
            u_tt_bloon(scene);
            u_tt_three(scene);
            u_tt_bloon(scene);
            scene->waves = scene->waves->next;
        }
        u_tt_bloon(scene);
        scene->turrets_placed.turrets = scene->turrets_placed.turrets->next;
    }
}