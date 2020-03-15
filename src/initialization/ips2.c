/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ips2
*/

#include "../../include/my_defender.h"

void i_hud(play_scene *scene)
{
    scene->background.sprite = sfSprite_create();
    scene->background.texture = sfTexture_createFromFile
    ("img/play_scene/in_game/game_hud.png", NULL);
    scene->background.pos = (sfVector2f){0.0, 0.0};
    sfSprite_setPosition(scene->background.sprite, scene->background.pos);
    sfSprite_setTexture(scene->background.sprite, scene->background.texture,
    sfTrue);
    scene->pause_btn = create_button("img/in_game_buttons/settings_",
    (sfFloatRect){1454, 891, 75, 75});
    scene->wave_btn = create_button("img/in_game_buttons/wave_",
    (sfFloatRect){1370, 891, 75, 76});
}

void fill_map_texture(play_scene *play_scene)
{
    switch (play_scene->map.map_index) {
        case 1 : sfSprite_setTexture(play_scene->map.sprite,
        play_scene->map.texture_one, sfTrue);
            break;
        case 2 : sfSprite_setTexture(play_scene->map.sprite,
        play_scene->map.texture_two, sfTrue);
            break;
        case 3 : sfSprite_setTexture(play_scene->map.sprite,
        play_scene->map.texture_three, sfTrue);
            break;
        default : break;
    }
}

void i_map(play_scene *play_scene)
{
    play_scene->map.sprite = sfSprite_create();
    play_scene->map.pos = (sfVector2f){235, 0};
    play_scene->difficulty = NORMAL;
    play_scene->map.map_index = 0;
    play_scene->map.coord = NULL;
    play_scene->map.coord = malloc(sizeof(coord));
    play_scene->map.coord->index = -1;
    play_scene->map.texture_one = sfTexture_createFromFile
    ("img/play_scene/maps/map1.png", NULL);
    play_scene->map.texture_two = sfTexture_createFromFile
    ("img/play_scene/maps/map2.png", NULL);
    play_scene->map.texture_three = sfTexture_createFromFile
    ("img/play_scene/maps/map3.png", NULL);
    sfSprite_setPosition(play_scene->map.sprite, play_scene->map.pos);
}

void set_difficulty(play_scene *play_scene)
{
    switch (play_scene->difficulty) {
        case EASY : play_scene->player_infos.health = 150;
            break;
        case NORMAL : play_scene->player_infos.health = 100;
            break;
        case HARD : play_scene->player_infos.health = 50;
            break;
    }
}

void set_money(play_scene *play_scene)
{
    play_scene->player_infos.money = 500;
}