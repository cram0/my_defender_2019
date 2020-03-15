/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ups5
*/

#include "../../include/my_defender.h"

void u_pause_menu_hover_click(play_scene *scene)
{
    button *buttons[4];
    buttons[0] = &scene->pause_menu.resume;
    buttons[1] = &scene->pause_menu.restart;
    buttons[2] = &scene->pause_menu.main_menu;
    buttons[3] = &scene->pause_menu.quit;
    for (int i = 0; i < 4; i++)
        if (buttons[i]->state == HOVER
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            buttons[i]->state = CLICKING;
            if (scene->sound_state == 0) {
                sfSound_play(scene->click_sound.sound);
                scene->sound_state = 1;
            }
        }
    for (int i = 0; i < 4; i++)
        if (buttons[i]->state == HOVER && scene->event->mouseButton.type
        == sfEvtMouseButtonReleased) {
            buttons[i]->state = CLICKED;
            scene->sound_state = 0;
        }
}

void u_pause_menu_hover(play_scene *scene)
{
    button *buttons[4];
    buttons[0] = &scene->pause_menu.resume;
    buttons[1] = &scene->pause_menu.restart;
    buttons[2] = &scene->pause_menu.main_menu;
    buttons[3] = &scene->pause_menu.quit;
    for (int i = 0; i < 4; i++) {
        if (is_hovering(*buttons[i], scene->window))
            buttons[i]->state = HOVER;
        else
            buttons[i]->state = IDLE;
    }
}

void u_pause_menu(play_scene *scene)
{
    u_pause_menu_hover(scene);
    u_pause_menu_hover_click(scene);
    setscale_state(&scene->pause_menu.resume);
    setscale_state(&scene->pause_menu.restart);
    setscale_state(&scene->pause_menu.main_menu);
    setscale_state(&scene->pause_menu.quit);
}

void u_pause_menu_interactions(play_scene *scene)
{
    if (scene->pause_menu.quit.state == CLICKED)
        sfRenderWindow_close(scene->window);
    if (scene->pause_menu.restart.state == CLICKED)
        set_play_values(scene);
    if (scene->pause_menu.resume.state == CLICKED)
        scene->pause_state = 0;
    if (scene->pause_menu.main_menu.state == CLICKED) {
        *scene->game_state = MENU;
        scene->map.map_index = 0;
        scene->pause_state = 0;
    }
}

void u_hud_text(play_scene *scene)
{
    sfText_setString(scene->wave_text, "Wave :");
    sfText_setString(scene->wave_number, my_itoa(scene->wave_max,
    scene->wave_max_str));
    sfText_setString(scene->player_infos.money_text, my_itoa
    (scene->player_infos.money, scene->player_infos.money_str));
    sfText_setString(scene->player_infos.health_text, my_itoa
    (scene->player_infos.health, scene->player_infos.health_str));
}