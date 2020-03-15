/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ups7
*/

#include "../../include/my_defender.h"

int is_out_path_1(int x, int y)
{
    if ((x >= 853 && x <= 924 && y >= 0 && y <= 138) || (x >= 440 && x <= 924 &&
        y >= 60 && y <= 138) || (x >= 440 && x <= 524 && y >= 60 && y <= 685) ||
        (x >= 440 && x <= 1133 && y >= 603 && y <= 685) ||
        (x >= 1040 && x <= 1133 && y >= 283 && y <= 685) ||
        (x >= 850 && x <= 1133 && y >= 283 && y <= 359) ||
        (x >= 850 && x <= 935 && y >= 283 && y <= 565) ||
        (x >= 635 && x <= 935 && y >= 486 && y <= 565) ||
        (x >= 635 && x <= 724 && y >= 175 && y <= 565) ||
        (x >= 635 && x <= 1333 && y >= 175 && y <= 249) ||
        (x >= 1243 && x <= 1333 && y >= 175 && y <= 805) ||
        (x >= 860 && x <= 1333 && y >= 726 && y <= 805) ||
        (x >= 860 && x <= 944 && y >= 726 && 870)) {
            return (0);
        }
    return 1;
}

int is_out_path_3(int x, int y)
{
    if ((x >= 390 && x <= 445 && y >= 0 && y <= 180) || (x >= 390 && x <= 748 &&
        y >= 124 && y <= 179) || (x >= 690 && x <= 748 && y >= 124 && y <= 467)
        ||
        (x >= 390 && x <= 748 && y >= 394 && y <= 467) ||
        (x >= 390 && x <= 452 && y >= 400 && y <= 816) ||
        (x >= 390 && x <= 745 && y >= 762 && y <= 816) ||
        (x >= 683 && x <= 745 && y >= 488 && y <= 816) ||
        (x >= 685 && x <= 838 && y >= 488 && y <= 544) ||
        (x >= 776 && x <= 838 && y >= 126 && y <= 544) ||
        (x >= 776 && x <= 1373 && y >= 126 && y <= 187) ||
        (x >= 1312 && x <= 1373 && y >= 126 && y <= 462) ||
        (x >= 1062 && x <= 1373 && y >= 404 && y <= 462) ||
        (x >= 1062 && x <= 1117 && y >= 404 && y <= 544) ||
        (x >= 1062 && x <= 1373 && y >= 488 && y <= 544) ||
        (x >= 1300 && x <= 1373 && y >= 488 && y <= 822) ||
        (x >= 1300 && x <= 1500 && y >= 756 && y <= 822)) {
            return (0);
        }
    return 1;
}

bool is_the_ballons_in_map(enemy_t *enemy)
{
    int x = enemy->pos.x;
    int y = enemy->pos.y;
    if (x >= 236 && x <= 1496 && y >= 0 && y <= 871) {
        return true;
    }
    return false;
}

int is_the_cursor_in_zones(play_scene *scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
    int x = pos.x;
    int y = pos.y;
    if (is_mouse_in_map(scene)) {
        if (scene->map.map_index == 1) {
            if (is_out_path_1(x, y) == 1)
                return (1);
        }
        if (scene->map.map_index == 2) {
            return (1);
        }
        if (scene->map.map_index == 3) {
            if (is_out_path_3(x, y) == 1)
                return (1);
        }
    }
    return (-1);
}

void u_turret_range_color(play_scene *scene)
{
    if (is_the_cursor_in_zones(scene) > 0) {
        sfCircleShape_setFillColor(scene->dragndrop.circle,
        sfColor_fromRGBA(218, 128, 128, 128));
    } else {
        sfCircleShape_setFillColor(scene->dragndrop.circle,
        sfColor_fromRGBA(255, 255, 255, 128));
    }
}