/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ups4
*/

#include "../../include/my_defender.h"

void u_hud(play_scene *scene)
{
    u_turret_hud(scene);
    u_turret_click_hud(scene);
    if (scene->pause_state == 0) {
        u_pause_button(scene);
        u_wave_button(scene);
    }
    if (scene->pause_state == 1) {
        u_pause_menu(scene);
        u_pause_menu_interactions(scene);
    }
    u_hud_text(scene);
}

int turret_damage(turret_t *turret)
{
    switch (turret->type) {
        case SIMPLE_TURRET : return (1);
        case FREEZE_TURRET : return (0);
        case BOMB_TURRET : return (2);
        case SNIPER_TURRET : return (3);
        default : return (1);
    }
}

void u_turret_attack(enemy_t *enemy, turret_t *turret, sfClock *clock)
{
    sfVector2f pos = enemy->pos;
    int x1 = turret->pos.x;
    int y1 = turret->pos.y;
    int x2 = pos.x;
    int y2 = pos.y;
    int dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    if (dist <= turret->range && enemy->health != 0) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 1) {
            turret->can_attack = true;
        }
        if (turret->can_attack == true && enemy->health > 0) {
            enemy->health -= turret_damage(turret);
            turret->can_attack = false;
        }
    }
}

void u_turret_direction(enemy_t *enemy, turret_t *turret)
{
    sfVector2f pos = enemy->pos;
    int x1 = turret->pos.x;
    int y1 = turret->pos.y;
    int x2 = pos.x;
    int y2 = pos.y;
    int dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double angle = atan2(y2 - y1, x2 - x1) * 180 / PI;
    if (dist <= turret->range && enemy->health > 0) {
        sfSprite_setRotation(turret->sprite, angle + 90);
    }
}

bool is_mouse_in_map(play_scene *scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
    int x = pos.x;
    int y = pos.y;
    if (x >= 236 && x <= 1496 && y >= 0 && y <= 871) {
        return true;
    }
    return false;
}