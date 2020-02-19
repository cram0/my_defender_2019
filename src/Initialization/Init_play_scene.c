/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_play_scene
*/

#include "../../include/my_defender.h"

void fill_coord_one(map *map)
{
    sfVector2f list[] = 
}

void i_map_coord(map *map)
{
    switch (map->map_index) {
        case 1 : fill_coord_one(map);
            break;
        case 2 : fill_coord_two(map);
            break;
        case 3 : fill_coord_three(map);
            break;
        default :
            break;
    }
}

void i_map(play_scene *play_scene)
{
    play_scene->map.sprite = sfSprite_create();
    play_scene->map.pos = (sfVector2f){500, 500};
    play_scene->difficulty = EASY;

}

void i_play_scene(play_scene *play_scene, sfRenderWindow *window)
{
    play_scene->window = window;
    i_map(play_scene);
}