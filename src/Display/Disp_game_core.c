/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** d_game_core
*/

#include "../../include/my_defender.h"

void d_menu_ui(menu_ui *ui, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, ui->play_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->hiscore_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->settings_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->quit_btn.sprite, NULL);
}

void d_settings_ui(settings_ui *ui, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, ui->close_button.sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->check_mark.sprite, NULL);
    sfRenderWindow_drawRectangleShape(window, ui->volume_rect, NULL);
}

void d_settings_background(settings_ui *ui, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, ui->background.background_sprite, NULL);
}

void d_settings(menu_scene *menu_scene)
{
    d_settings_background(&menu_scene->settings_ui, menu_scene->window);
    d_settings_ui(&menu_scene->settings_ui,menu_scene->window);
}

void d_choice_menu_bg(simple_entity *background, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, background->sprite, NULL);
}

void d_menu_background(menu_background *bg, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, bg->background_sprite, NULL);
}

void d_choice_menu_btns(choice_menu *choice, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, choice->close_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, choice->map_one_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, choice->map_two_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window, choice->map_three_btn.sprite, NULL);
}

void d_choice_menu(menu_scene *menu_scene)
{
    d_choice_menu_bg(&menu_scene->choice_menu.background, menu_scene->window);
    d_choice_menu_btns(&menu_scene->choice_menu, menu_scene->window);
    sfRenderWindow_drawSprite(menu_scene->window,
    menu_scene->choice_menu.difficulty_check.sprite, NULL);
}

void d_menu_scene(menu_scene *menu_scene)
{
    d_menu_background(&menu_scene->menu_background, menu_scene->window);
    d_menu_ui(&menu_scene->ui, menu_scene->window);
    if (menu_scene->settings_state == 1)
        d_settings(menu_scene);
    if (menu_scene->choice_state == 1)
        d_choice_menu(menu_scene);
}

void d_play_hud(play_scene *scene)
{
    sfRenderWindow_drawSprite(scene->window, scene->background.background_sprite, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->turret_hud.bomb, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->turret_hud.simple, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->turret_hud.freeze, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->turret_hud.sniper, NULL);
}

void d_play_map(play_scene *play_scene)
{
    sfRenderWindow_drawSprite(play_scene->window, play_scene->map.sprite, NULL);
}

void d_player_infos(play_scene *play_scene)
{
    sfRenderWindow_drawText(play_scene->window,
    play_scene->player_infos.health_text, NULL);
    sfRenderWindow_drawText(play_scene->window,
    play_scene->player_infos.money_text, NULL);
}

void d_play_dragndrop(play_scene *scene)
{
    if (scene->dragndrop.display == true)
        sfRenderWindow_drawSprite(scene->window, scene->dragndrop.sprite, NULL);
}

void d_play_scene(play_scene *play_scene)
{
   d_play_map(play_scene);
   d_play_hud(play_scene);
   d_play_dragndrop(play_scene);
   d_player_infos(play_scene);
}

void d_cursor(game_core *game_core)
{
    sfRenderWindow_drawSprite(game_core->window, game_core->mouse_cursor.sprite,
    NULL);
}

void d_game_core(game_core *game_core, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    if (game_core->game_state == MENU)
        d_menu_scene(&game_core->menu_scene);
    if (game_core->game_state == PLAY)
        d_play_scene(&game_core->play_scene);
    d_cursor(game_core);
    sfRenderWindow_display(window);
}