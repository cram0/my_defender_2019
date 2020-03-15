/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ups2
*/

#include "../../include/my_defender.h"

void u_waves_two(play_scene *scene)
{
    if (scene->waves->enemy->previous == NULL) {
        scene->waves->enemy->moving = true;
    }
    else {
        if (scene->waves->enemy->previous->moving == true && sfTime_asSeconds
        (sfClock_getElapsedTime(scene->movement_clock)) >= 1 &&
        scene->waves->enemy->moving == false) {
            scene->waves->enemy->moving = true;
            sfClock_restart(scene->movement_clock);
        }
    }
}

void u_waves_four(play_scene *scene)
{
    if (scene->waves->enemy->pos.x < scene->map.coord->pos.x &&
    scene->waves->enemy->moving == true)
        scene->waves->enemy->pos.x += 0.06 * sfTime_asMilliseconds
        (sfClock_getElapsedTime(scene->general_clock));
    if (scene->waves->enemy->pos.x > scene->map.coord->pos.x &&
    scene->waves->enemy->moving == true)
        scene->waves->enemy->pos.x -= 0.06 * sfTime_asMilliseconds
        (sfClock_getElapsedTime(scene->general_clock));
    if (scene->waves->enemy->pos.y < scene->map.coord->pos.y &&
    scene->waves->enemy->moving == true)
        scene->waves->enemy->pos.y += 0.06 * sfTime_asMilliseconds
        (sfClock_getElapsedTime(scene->general_clock));
    if (scene->waves->enemy->pos.y > scene->map.coord->pos.y &&
    scene->waves->enemy->moving == true)
        scene->waves->enemy->pos.y -= 0.06 * sfTime_asMilliseconds
        (sfClock_getElapsedTime(scene->general_clock));
}

void u_waves_three(play_scene *scene)
{
    if (scene->map.coord->index - 1 == scene->waves->enemy->index_reached) {
        if (scene->waves->enemy->pos.x >= scene->map.coord->pos.x - 4 &&
        scene->waves->enemy->pos.x <= scene->map.coord->pos.x + 4 &&
        scene->waves->enemy->pos.y >=
        scene->map.coord->pos.y - 4 && scene->waves->enemy->pos.y <=
        scene->map.coord->pos.y + 4) {
            scene->waves->enemy->index_reached += 1;
        }
        u_waves_four(scene);
        sfSprite_setPosition(scene->waves->enemy->sprite,
        scene->waves->enemy->pos);
    }
}

void u_waves_five(play_scene *scene)
{
    if (scene->waves->enemy->previous == NULL) {
        scene->waves->enemy->moving = true;
    }
    else {
        if (scene->waves->enemy->previous->moving == true &&
        sfTime_asSeconds(sfClock_getElapsedTime(scene->movement_clock)) >= 1 &&
        scene->waves->enemy->moving == false) {
            scene->waves->enemy->moving = true;
            sfClock_restart(scene->movement_clock);
        }
    }
}

void u_waves(play_scene *scene)
{
    while (scene->waves->previous != NULL)
        scene->waves = scene->waves->previous;
    while (scene->waves->index != scene->wave_max) {
        while (scene->waves->enemy->previous != NULL)
            scene->waves->enemy = scene->waves->enemy->previous;
        while (scene->waves->enemy->next != NULL) {
            u_waves_two(scene);
            while (scene->map.coord->previous != NULL)
                scene->map.coord = scene->map.coord->previous;
            while (scene->map.coord->next != NULL) {
                u_waves_three(scene);
                scene->map.coord = scene->map.coord->next;
            }
            scene->waves->enemy = scene->waves->enemy->next;
        }
        u_waves_five(scene);
        scene->waves = scene->waves->next;
    }
}