/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_play_scene
*/

#include "../../include/my_defender.h"

void u_turret_tracking(play_scene *scene)
{
    if (scene->turrets_placed.turrets->range != -1) {
        while (scene->turrets_placed.turrets->previous != NULL)
            scene->turrets_placed.turrets =
            scene->turrets_placed.turrets->previous;
        u_tt_two(scene);
    }
}

void u_clock_restart(play_scene *scene)
{
    sfClock_restart(scene->general_clock);
    if (sfTime_asSeconds(sfClock_getElapsedTime(scene->attack_clock)) >= 1) {
        sfClock_restart(scene->attack_clock);
    }
}

void u_victory_lose(play_scene *scene)
{
    if (scene->player_infos.health <= 0 && scene->playing == true) {
        scene->playing = false;
    }
    if (scene->player_infos.score >= 9550 && scene->playing == true) {
        scene->playing = false;
    }
}

void u_play_scene(play_scene *scene)
{
    u_hud(scene);
    if (scene->playing == true) {
        u_waves(scene);
        u_turret_tracking(scene);
        u_waves_health(scene);
    }
    if (scene->pause_state == 0)
        scene->playing = true;
    else
        scene->playing = false;
    u_enemy_damage(scene);
    u_victory_lose(scene);
    u_clock_restart(scene);
}