/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ips6
*/

#include "../../include/my_defender.h"

void set_waves_positions(play_scene *scene)
{
    while (scene->waves->previous != NULL)
        scene->waves = scene->waves->previous;
    while (scene->waves->next != NULL) {
        while (scene->waves->enemy->previous != NULL)
            scene->waves->enemy = scene->waves->enemy->previous;
        while (scene->waves->enemy->next != NULL) {
            set_waves_positions_index(scene->waves->enemy, scene->map.map_index)
            ;
            scene->waves->enemy = scene->waves->enemy->next;
        }
        set_waves_positions_index(scene->waves->enemy, scene->map.map_index);
        scene->waves = scene->waves->next;
    }
}

void i_pause_menu(play_scene *scene)
{
    scene->pause_menu.background = set_simple_entity
    ("img/play_scene/in_game/pause_menu.png",
    (sfFloatRect){700, 125, 447, 634});
    scene->pause_menu.resume = create_button("img/buttons/resume_",
    (sfFloatRect){760, 300, 314, 82});
    scene->pause_menu.restart = create_button("img/buttons/restart_",
    (sfFloatRect){760, 400, 314, 82});
    scene->pause_menu.main_menu = create_button("img/buttons/mainmenu_",
    (sfFloatRect){760, 500, 314, 82});
    scene->pause_menu.quit = create_button("img/buttons/quit_",
    (sfFloatRect){760, 600, 314, 82});
}

void set_hbars_enemy(enemy_t *enemy)
{
    enemy->hbar_max = sfRectangleShape_create();
    sfRectangleShape_setPosition(enemy->hbar_max,
    (sfVector2f){enemy->pos.x, enemy->pos.y - 30});
    sfRectangleShape_setSize(enemy->hbar_max, (sfVector2f){40, 7});
    sfRectangleShape_setOrigin(enemy->hbar_max, (sfVector2f){20, 3.5});
    sfRectangleShape_setFillColor(enemy->hbar_max, sfRed);
    enemy->hbar = sfRectangleShape_create();
    sfRectangleShape_setPosition(enemy->hbar,
    (sfVector2f){enemy->pos.x, enemy->pos.y - 30});
    sfRectangleShape_setSize(enemy->hbar,
    (sfVector2f){enemy->health / enemy->max_health * 40, 7});
    sfRectangleShape_setOrigin(enemy->hbar, (sfVector2f){20, 3.5});
    sfRectangleShape_setFillColor(enemy->hbar, sfGreen);
}

void i_wave_index(play_scene *scene)
{
    scene->waves = NULL;
    scene->waves = malloc(sizeof(wave_t));
    scene->waves->index = -1;
    scene->waves->enemy = NULL;
    scene->waves->enemy = malloc(sizeof(enemy_t));
    scene->waves->enemy->health = -1;
    scene->enemy_texture =
    sfTexture_createFromFile("img/play_scene/enemies/enemies.png", NULL);
    scene->waves->texture = scene->enemy_texture;
    scene->waves->spawn_rate = 0;
    scene->wave_max = 0;
}

void i_play_scene(play_scene *play_scene, sfRenderWindow *window)
{
    play_scene->window = window;
    play_scene->sound_state = 0;
    i_hud(play_scene);
    i_map(play_scene);
    i_turrets_price(play_scene);
    i_turret_hud(play_scene);
    i_dragndrop(play_scene);
    i_pause_menu(play_scene);
    i_wave_index(play_scene);
}