/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** dgc4
*/

#include "../../include/my_defender.h"

void d_pause_menu(play_scene *scene)
{
    if (scene->pause_state == 1) {
        sfRenderWindow_drawSprite(scene->window,
        scene->pause_menu.background.sprite, NULL);
        sfRenderWindow_drawSprite(scene->window,
        scene->pause_menu.resume.sprite, NULL);
        sfRenderWindow_drawSprite(scene->window,
        scene->pause_menu.restart.sprite, NULL);
        sfRenderWindow_drawSprite(scene->window,
        scene->pause_menu.main_menu.sprite, NULL);
        sfRenderWindow_drawSprite(scene->window,
        scene->pause_menu.quit.sprite, NULL);
    }
}

void d_waves_two(play_scene *scene)
{
    if (scene->waves->enemy->health > 0) {
        sfRenderWindow_drawSprite(scene->window,
        scene->waves->enemy->sprite, NULL);
        sfRenderWindow_drawRectangleShape(scene->window,
        scene->waves->enemy->hbar_max, NULL);
        sfRenderWindow_drawRectangleShape(scene->window,
        scene->waves->enemy->hbar, NULL);
    }
    scene->waves = scene->waves->next;
}

void d_waves(play_scene *scene)
{
    while (scene->waves->previous != NULL)
        scene->waves = scene->waves->previous;
    while (scene->waves->next != NULL) {
        while (scene->waves->enemy->previous != NULL)
            scene->waves->enemy = scene->waves->enemy->previous;
        while (scene->waves->enemy->next != NULL) {
            if (scene->waves->enemy->health > 0) {
                sfRenderWindow_drawSprite(scene->window,
                scene->waves->enemy->sprite, NULL);
                sfRenderWindow_drawRectangleShape(scene->window,
                scene->waves->enemy->hbar_max, NULL);
                sfRenderWindow_drawRectangleShape(scene->window,
                scene->waves->enemy->hbar, NULL);
            }
            scene->waves->enemy = scene->waves->enemy->next;
        }
        d_waves_two(scene);
    }
}

void d_play_scene(play_scene *play_scene)
{
    d_play_map(play_scene);
    d_waves(play_scene);
    d_play_dragndrop(play_scene);
    d_turret_placed(play_scene);
    d_play_hud(play_scene);
    d_price_dnd(play_scene);
    d_player_infos(play_scene);
    d_pause_menu(play_scene);
    d_victory(play_scene);
    d_defeat(play_scene);
}

void d_cursor(game_core *game_core)
{
    sfRenderWindow_drawSprite(game_core->window, game_core->mouse_cursor.sprite,
    NULL);
}