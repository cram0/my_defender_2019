/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_play_scene
*/

#include "../../include/my_defender.h"

void add_coord(map *map)
{

}

void fill_coord_one(map *map)
{
    sfVector2f list[] = {{655, 0}, {621, 93}, {255, 104}, {250, 645}, {850, 643}, {850, 330}, {661, 326}, {644, 524}, {454, 521}, {447, 218}, {1049, 221}, {1049, 762}, {669, 775}, {665, 878}};

}

void fill_coord_two(map *map)
{
    sfVector2f list[] = {{621, 883}, {627, 825}, {624, 748}, {700, 1051}, {519, 628}, {435, 630}, {381, 669}, {309, 732}, {228, 760}, {165, 745}, {121, 700}, {108, 624}, {136, 549}, {217, 498}, {294, 457}, {342, 396}, {358, 346}, {330, 228}, {273, 165}, {184, 132}, {91, 148}, {49, 207}, {49, 295}, {102, 352}, {196, 372}, {279, 348}, {351, 303}, {409, 219}, {478, 147}, {565, 120}, {661, 163}, {705, 238}, {754, 303}, {817, 367}, {849, 450}, {820, 541}, {744, 586}, {649, 582}, {586, 526}, {565, 448}, {601, 363}, {654, 307}, {705, 238}, {759, 160}, {823, 118}, {910, 118}, {985, 168}, {1015, 261}, {1005, 354}, {966, 444}, {921, 529}, {898, 618}, {930, 702}, {987, 753}, {1057, 774}, {1135, 762}, {1195, 724}, {1236, 610}, {1233, 546}, {1197, 442}, {1156, 349}, {1156, 256}, {1219, 174}, {1320, 145}};
}

void fill_coord_three(map *map)
{
    sfVector2f list[] = {{184, -19}, {187, 145}, {474, 155}, {481, 431}, {183, 435}, {181, 780}, {477, 781}, {485, 513}, {574, 513}, {567, 154}, {1103, 155}, {1105, 431}, {850, 435}, {851, 510}, {1102, 521}, {1104, 789}, {1302, 789}};
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