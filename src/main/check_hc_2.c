/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** check_hc_2
*/

#include "../../include/my_defender.h"

void check_hover_click_ui(menu_scene *menu_scene)
{
    button *buttons[4];
    buttons[0] = &menu_scene->ui.play_btn;
    buttons[1] = &menu_scene->ui.hiscore_btn;
    buttons[2] = &menu_scene->ui.settings_btn;
    buttons[3] = &menu_scene->ui.quit_btn;
    for (int i = 0; i < 4; i++)
        if (buttons[i]->state == HOVER &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            buttons[i]->state = CLICKING;
            if (menu_scene->sound_state == 0) {
                sfSound_play(menu_scene->click_sound.sound);
                menu_scene->sound_state = 1;
            }
        }
    for (int i = 0; i < 4; i++)
        if (buttons[i]->state == HOVER && menu_scene->event->mouseButton.type
        == sfEvtMouseButtonReleased) {
            buttons[i]->state = CLICKED;
            menu_scene->sound_state = 0;
        }
}

void check_difficulty(menu_scene *menu_scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(menu_scene->window);
    sfSprite *check = menu_scene->choice_menu.difficulty_check.sprite;
    if ((menu_scene->event->mouseButton.type == sfEvtMouseButtonPressed) &&
    menu_scene->choice_state == 1) {
        if (pos.x >= 527 && pos.x <= 527 + 64 && pos.y >= 714 && pos.y <= 781) {
            sfSprite_setPosition(check, (sfVector2f){537, 724});
            menu_scene->game_core->play_scene.difficulty = EASY;
        }
        if (pos.x >= 865 && pos.x <= 865 + 64 && pos.y >= 714 && pos.y <= 781) {
            sfSprite_setPosition(check, (sfVector2f){875, 724});
            menu_scene->game_core->play_scene.difficulty = NORMAL;
        }
        if (pos.x >= 1203 && pos.x <= 1267 && pos.y >= 714 && pos.y <= 781) {
            sfSprite_setPosition(check, (sfVector2f){1213, 724});
            menu_scene->game_core->play_scene.difficulty = HARD;
        }
    }
}

void map_selection_click(menu_scene *scene)
{
    if (scene->choice_menu.map_one_btn.state == HOVER &&
    sfMouse_isButtonPressed(sfMouseLeft) && scene->choice_state == 1) {
        *scene->map_index = 1;
        sfSound_play(scene->click_sound.sound);
    }
    if (scene->choice_menu.map_two_btn.state == HOVER &&
    sfMouse_isButtonPressed(sfMouseLeft) && scene->choice_state == 1) {
        *scene->map_index = 2;
        sfSound_play(scene->click_sound.sound);
    }
    if (scene->choice_menu.map_three_btn.state == HOVER &&
    sfMouse_isButtonPressed(sfMouseLeft) && scene->choice_state == 1) {
        *scene->map_index = 3;
        sfSound_play(scene->click_sound.sound);
    }
}

void check_hover_click_choice_menu_two(menu_scene *menu_scene)
{
    map_selection_click(menu_scene);
    if (*menu_scene->map_index != 0) {
        menu_scene->choice_state = 0;
        menu_scene->sound_state = 0;
        set_play_values(&menu_scene->game_core->play_scene);
        *menu_scene->game_state = PLAY;
    }
}