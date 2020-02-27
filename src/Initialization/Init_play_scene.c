/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_play_scene
*/

#include "../../include/my_defender.h"

void add_coord_node(coord *node, sfVector2f pos, int index)
{
    if (node->index == -1) {
        node->index = 0;
        node->pos.x = pos.x;
        node->pos.y = pos.y;
        node->previous = NULL;
        node->next = NULL;
    } else {
        coord *temp = malloc(sizeof(coord));
        while (node->next != NULL)
            node = node->next;
        temp->pos.x = pos.x;
        temp->pos.y = pos.y;
        node->next = temp;
        temp->previous = node;
        temp->next = NULL;
        temp->index = index;
    }
}

void add_coord(map *map, sfVector2f list[], int len)
{
    for (int i = 0; i < len; i++) {
        add_coord_node(map->coord, list[i], len);
    }
    while (map->coord->next != NULL) {
        printf("Coord[] X : %f | Y : %f\n", map->coord->pos.x , map->coord->pos.y);
        map->coord = map->coord->next;
    }
    printf("Coord[] X : %f | Y : %f\n", map->coord->pos.x , map->coord->pos.y);
}

void fill_coord_one(map *map)
{
    sfVector2f list[] = {{655, 0}, {621, 93}, {255, 104}, {250, 645}, {850, 643}, {850, 330}, {661, 326}, {644, 524}, {454, 521}, {447, 218}, {1049, 221}, {1049, 762}, {669, 775}, {665, 878}};
    add_coord(map, list, 14);
}

void fill_coord_two(map *map)
{
    sfVector2f list[] = {{621, 883}, {627, 825}, {624, 748}, {700, 1051}, {519, 628}, {435, 630}, {381, 669}, {309, 732}, {228, 760}, {165, 745}, {121, 700}, {108, 624}, {136, 549}, {217, 498}, {294, 457}, {342, 396}, {358, 346}, {330, 228}, {273, 165}, {184, 132}, {91, 148}, {49, 207}, {49, 295}, {102, 352}, {196, 372}, {279, 348}, {351, 303}, {409, 219}, {478, 147}, {565, 120}, {661, 163}, {705, 238}, {754, 303}, {817, 367}, {849, 450}, {820, 541}, {744, 586}, {649, 582}, {586, 526}, {565, 448}, {601, 363}, {654, 307}, {705, 238}, {759, 160}, {823, 118}, {910, 118}, {985, 168}, {1015, 261}, {1005, 354}, {966, 444}, {921, 529}, {898, 618}, {930, 702}, {987, 753}, {1057, 774}, {1135, 762}, {1195, 724}, {1236, 610}, {1233, 546}, {1197, 442}, {1156, 349}, {1156, 256}, {1219, 174}, {1320, 145}};
    add_coord(map, list, 64);
}

void fill_coord_three(map *map)
{
    sfVector2f list[] = {{184, -19}, {187, 145}, {474, 155}, {481, 431}, {183, 435}, {181, 780}, {477, 781}, {485, 513}, {574, 513}, {567, 154}, {1103, 155}, {1105, 431}, {850, 435}, {851, 510}, {1102, 521}, {1104, 789}, {1302, 789}};
    add_coord(map, list, 17);
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
    }
}

void i_hud(play_scene *play_scene)
{
    play_scene->background.background_sprite = sfSprite_create();
    play_scene->background.background_texture = sfTexture_createFromFile("img/play_scene/in_game/game_hud.png", NULL);
    play_scene->background.pos = (sfVector2f){0.0, 0.0};
    sfSprite_setPosition(play_scene->background.background_sprite, play_scene->background.pos);
    sfSprite_setTexture(play_scene->background.background_sprite, play_scene->background.background_texture, sfTrue);
}

void fill_map_texture(play_scene *play_scene)
{
    switch (play_scene->map.map_index) {
        case 1 : sfSprite_setTexture(play_scene->map.sprite,    play_scene->map.texture_one, sfTrue);
            break;
        case 2 : sfSprite_setTexture(play_scene->map.sprite,    play_scene->map.texture_two, sfTrue);
            break;
        case 3 : sfSprite_setTexture(play_scene->map.sprite,    play_scene->map.texture_three, sfTrue);
            break;
        default : break;
    }
}

void i_map(play_scene *play_scene)
{
    play_scene->map.sprite = sfSprite_create();
    play_scene->map.pos = (sfVector2f){235, 0};
    play_scene->difficulty = EASY;
    play_scene->map.map_index = 0;
    play_scene->map.coord = malloc(sizeof(coord));
    play_scene->map.coord->index = -1;
    play_scene->map.texture_one = sfTexture_createFromFile("img/play_scene/maps/map1.png", NULL);
    play_scene->map.texture_two = sfTexture_createFromFile("img/play_scene/maps/map2.png", NULL);
    play_scene->map.texture_three = sfTexture_createFromFile("img/play_scene/maps/map3.png", NULL);
    sfSprite_setPosition(play_scene->map.sprite, play_scene->map.pos);
}

void change_map_values(play_scene *play_scene)
{
    fill_map_texture(play_scene);
    i_map_coord(&play_scene->map);
}

void i_play_scene(play_scene *play_scene, sfRenderWindow *window)
{
    play_scene->window = window;
    i_hud(play_scene);
    i_map(play_scene);
}