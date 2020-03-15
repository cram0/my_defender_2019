/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ups6
*/

#include "../../include/my_defender.h"

int sub_money(play_scene *scene)
{
    switch (scene->dragndrop.turret_selected) {
        case SIMPLE_TURRET : return (100);
        case FREEZE_TURRET : return (75);
        case BOMB_TURRET : return (200);
        case SNIPER_TURRET : return (250);
        default : return (0);
    }
}

void u_turret_click_hud(play_scene *scene)
{
    if (scene->event->mouseButton.type == sfEvtMouseButtonPressed) {
        sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
        u_turret_click_hud_pos(scene, pos);
    }
    if (scene->event->mouseButton.type == sfEvtMouseButtonReleased) {
        if (scene->dragndrop.turret_selected != NONE) {
            if (is_the_cursor_in_zones(scene) == 1) {
                place_turret(scene, scene->dragndrop.turret_selected,
                sfMouse_getPositionRenderWindow(scene->window),
                scene->turrets_placed.texture);
                scene->player_infos.money -= sub_money(scene);
                sfSound_play(scene->set_turret_sound.sound);
            }
        }
        scene->dragndrop.display = false;
        scene->dragndrop.turret_selected = NONE;
    }
    u_turret_click_hud_two(scene);
}

void u_wave_button(play_scene *scene)
{
    if (is_hovering(scene->wave_btn, scene->window))
        scene->wave_btn.state = HOVER;
    else
        scene->wave_btn.state = IDLE;
    if (scene->wave_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        scene->wave_btn.state = CLICKING;
    if (scene->wave_btn.state == HOVER &&
    scene->event->type == sfEvtMouseButtonReleased) {
        scene->wave_btn.state = CLICKED;
        scene->wave_max += 1;
        if (scene->wave_max >= 9)
            scene->wave_max = 9;
    }
    setscale_state(&scene->wave_btn);
}

void u_pause_button(play_scene *scene)
{
    if (is_hovering(scene->pause_btn, scene->window))
        scene->pause_btn.state = HOVER;
    else
        scene->pause_btn.state = IDLE;
    if (scene->pause_btn.state == HOVER &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        scene->pause_btn.state = CLICKING;
        if (scene->sound_state == 0) {
            sfSound_play(scene->click_sound.sound);
            scene->sound_state = 1;
        }
    }
    if (scene->pause_btn.state == HOVER && scene->event->mouseButton.type
    == sfEvtMouseButtonReleased) {
            scene->pause_btn.state = CLICKED;
            scene->pause_state = 1;
            scene->sound_state = 0;
    }
    setscale_state(&scene->pause_btn);
}

void u_hud_interaction(play_scene *scene)
{
    if (scene->pause_btn.state == CLICKED && scene->pause_state == 0)
        scene->pause_state = 1;
}