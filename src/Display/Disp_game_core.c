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
}

void d_settings_background(settings_ui *ui, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, ui->background.background_sprite, NULL);
    sfRenderWindow_drawSprite(window, ui->fps_bg.background_sprite, NULL);
}

void d_settings(menu_scene *menu_scene)
{
    d_settings_background(&menu_scene->opt_ui, menu_scene->window);
    d_settings_ui(&menu_scene->opt_ui,menu_scene->window);
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
}

void d_menu_scene(menu_scene *menu_scene)
{
    d_menu_background(&menu_scene->menu_background, menu_scene->window);
    d_menu_ui(&menu_scene->ui, menu_scene->window);
    if (menu_scene->opt_state == 1) {
        d_settings(menu_scene);
    }
    if (menu_scene->choice_state == 1) {
        d_choice_menu(menu_scene);
    }
}

void d_play_hud(menu_background *bg, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, bg->background_sprite, NULL);

}

//void d_play_scene(play_scene *play_scene)
//{
//    d_play_hud(play_scene);
//    d_play_map();
// }

void d_cursor(game_core *game_core)
{
    sfRenderWindow_drawSprite(game_core->window, game_core->mouse_cursor.sprite,
    NULL);
}

void d_game_core(game_core *game_core, sfRenderWindow *window)
{
    if (game_core->game_state == MENU)
        d_menu_scene(&game_core->menu_scene);
    //if (game_core->game_state == PLAY)
        //d_play_scene(&game_core->play_scene);
    sfRenderWindow_display(window);
}