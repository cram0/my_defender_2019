/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_play_scene
*/

#include "../../include/my_defender.h"

void set_play_values(play_scene *play_scene)
{
    play_scene->general_clock = sfClock_create();
    sfClock_restart(play_scene->general_clock);
    play_scene->movement_clock = sfClock_create();
    sfClock_restart(play_scene->movement_clock);
    play_scene->attack_clock = sfClock_create();
    sfClock_restart(play_scene->attack_clock);
    play_scene->pause_state = 0;
    play_scene->playing = true;
    play_scene->map.coord->index = -1;
    fill_map_texture(play_scene);
    set_map_coord(&play_scene->map);
    i_player_infos(play_scene);
    i_font(play_scene);
    i_text_out_thick(play_scene);
    set_turret_node(play_scene);
    i_wave_index(play_scene);
    set_waves(play_scene);
    set_waves_positions(play_scene);
}