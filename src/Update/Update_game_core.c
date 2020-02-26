/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_game_core
*/

#include "../../include/my_defender.h"

void close_events(game_core *game_core)
{
    if (game_core->event.type == sfEvtClosed)
            sfRenderWindow_close(game_core->window);
    if (game_core->game_state == MENU && sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(game_core->window);
    }
}

void u_cursor(game_core *game_core)
{
    game_core->mouse_cursor.pos.x = sfMouse_getPositionRenderWindow(game_core->window).x;
    game_core->mouse_cursor.pos.y = sfMouse_getPositionRenderWindow(game_core->window).y;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        sfSprite_setTextureRect(game_core->mouse_cursor.sprite, (sfIntRect){0,
        64, 64, 64});
    else
        sfSprite_setTextureRect(game_core->mouse_cursor.sprite, (sfIntRect){0,
        0, 64, 64});
    sfSprite_setPosition(game_core->mouse_cursor.sprite, game_core->mouse_cursor.pos);
}

void u_game_core(game_core *game_core)
{
    u_cursor(game_core);
    while (sfRenderWindow_pollEvent(game_core->window, &game_core->event)) {
        close_events(game_core);
        game_core->mouse_pos = get_mouse_pos(game_core->window);
    }
    if (game_core->game_state == MENU)
        u_menu_scene(&game_core->menu_scene);
    if (game_core->game_state == PLAY)
        u_play_scene(&game_core->play_scene);
}