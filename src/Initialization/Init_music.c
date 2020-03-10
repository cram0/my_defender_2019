/*
** EPITECH PROJECT, 2020
** Init_music.c
** File description:
** initialisation of the game music
*/

#include "../../include/my_defender.h"

void i_menu_music(menu_scene *scene)
{
    scene->music = sfMusic_createFromFile("music/main_theme.ogg");
    sfMusic_setVolume(scene->music, 20.0);
    sfMusic_play(scene->music);
    sfMusic_setLoop(scene->music, sfTrue);
}

void i_sound_buttons(game_core *game_core)
{
    game_core->menu_scene.sound_buffer = sfSoundBuffer_createFromFile("music/soft_click.wav");
    game_core->play_scene.sound_buffer = sfSoundBuffer_createFromFile("music/soft_click.wav");
    game_core->menu_scene.sound = sfSound_create();
    game_core->play_scene.sound = sfSound_create();
    sfSound_setBuffer(game_core->menu_scene.sound, game_core->menu_scene.sound_buffer);
    sfSound_setBuffer(game_core->play_scene.sound, game_core->play_scene.sound_buffer);
    sfSound_setVolume(game_core->menu_scene.sound, 90.0);
    sfSound_setVolume(game_core->play_scene.sound, 90.0);
    sfSound_setPitch(game_core->menu_scene.sound, 1.50);
    sfSound_setPitch(game_core->play_scene.sound, 1.50);
}

void i_music(game_core *game_core)
{
    i_sound_buttons(game_core);
    i_menu_music(&game_core->menu_scene);
}