/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** dgc3
*/

#include "../../include/my_defender.h"

void d_play_map(play_scene *play_scene)
{
    sfRenderWindow_drawSprite(play_scene->window, play_scene->map.sprite, NULL);
}

void d_player_infos(play_scene *play_scene)
{
    sfRenderWindow_drawText(play_scene->window,
    play_scene->player_infos.health_text, NULL);
    sfRenderWindow_drawText(play_scene->window,
    play_scene->player_infos.money_text, NULL);
    sfRenderWindow_drawText(play_scene->window,
    play_scene->player_infos.score_text, NULL);
    sfRenderWindow_drawText(play_scene->window,
    play_scene->score_text_dot, NULL);
    sfRenderWindow_drawText(play_scene->window,
    play_scene->wave_text, NULL);
    sfRenderWindow_drawText(play_scene->window, play_scene->wave_number, NULL);
    if (play_scene->wave_btn.state == HOVER)
        sfRenderWindow_drawText(play_scene->window, play_scene->wave_button,
        NULL);
    if (play_scene->pause_btn.state == HOVER)
        sfRenderWindow_drawText(play_scene->window, play_scene->setting_txt,
        NULL);
}

void d_price_dnd(play_scene *scene)
{
    if (scene->dragndrop.display == true) {
        sfRenderWindow_drawText(scene->window,
        scene->dragndrop.price_text, NULL);
    }
}

void d_play_dragndrop(play_scene *scene)
{
    if (scene->dragndrop.display == true) {
        if (is_the_cursor_in_zones(scene) > 0) {
            sfCircleShape_setFillColor(scene->dragndrop.circle,
            sfColor_fromRGBA(255, 255, 255, 128));
        } else {
            sfCircleShape_setFillColor(scene->dragndrop.circle,
            sfColor_fromRGBA(228, 128, 128, 128));
        }
        sfRenderWindow_drawCircleShape(scene->window,
        scene->dragndrop.circle, NULL);
        sfRenderWindow_drawSprite(scene->window, scene->dragndrop.sprite, NULL);
    }
}

void d_turret_placed(play_scene *scene)
{
    turret_t *turret = scene->turrets_placed.turrets;
    if (turret->previous == NULL && turret->next == NULL && turret->range != -1)
            sfRenderWindow_drawSprite(scene->window, turret->sprite, NULL);
    else {
        if (turret->range != -1) {
            while (turret->previous != NULL)
                turret = turret->previous;
            while (turret->next != NULL) {
                sfRenderWindow_drawSprite(scene->window, turret->sprite, NULL);
                turret = turret->next;
            }
            sfRenderWindow_drawSprite(scene->window, turret->sprite, NULL);
        }
    }
}