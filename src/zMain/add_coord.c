/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** add_coord
*/

#include "../../include/my_defender.h"

void add_coord_node(coord *node, sfVector2f pos, int index)
{
    if (node->index == -1) {
        node->index = 0;
        node->pos.x = pos.x + 235;
        node->pos.y = pos.y;
        node->previous = NULL;
        node->next = NULL;
    } else {
        coord *temp = malloc(sizeof(coord));
        while (node->next != NULL)
            node = node->next;
        temp->pos.x = pos.x + 235;
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
}