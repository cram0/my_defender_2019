/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** fps_selection
*/

#include "../../include/my_defender.h"

int fps_selection_two(sfVector2i pos, simple_entity check)
{
    if (pos.x >= 1215 && pos.x <= 1215 + 60 && pos.y >= 560 && pos.y <= 720) {
        sfSprite_setPosition(check.sprite, (sfVector2f){1235, 560});
        return (1);
    }
    if (pos.x >= 1337 && pos.x <= 1337 + 60 && pos.y >= 560 && pos.y <= 720) {
        sfSprite_setPosition(check.sprite, (sfVector2f){1357, 560});
        return (2);
    }
    if (pos.x >= 1456 && pos.x <= 1456 + 60 && pos.y >= 560 && pos.y <= 720) {
        sfSprite_setPosition(check.sprite, (sfVector2f){1476, 560});
        return (3);
    }
    if (pos.x >= 1586 && pos.x <= 1586 + 60 && pos.y >= 560 && pos.y <= 720) {
        sfSprite_setPosition(check.sprite, (sfVector2f){1606, 560});
        return (4);
    }
    return (-1);
}

void fps_selection(menu_scene *menu_scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(menu_scene->window);
    simple_entity check = menu_scene->settings_ui.check_mark;
    if (menu_scene->event->mouseButton.type == sfEvtMouseButtonPressed) {
        switch (fps_selection_two(pos, check)) {
            case 1: sfRenderWindow_setFramerateLimit(menu_scene->window, 30);
                break;
            case 2: sfRenderWindow_setFramerateLimit(menu_scene->window, 60);
                break;
            case 3: sfRenderWindow_setFramerateLimit(menu_scene->window, 120);
                break;
            case 4: sfRenderWindow_setFramerateLimit(menu_scene->window, 0);
                break;
        }
    }
}
