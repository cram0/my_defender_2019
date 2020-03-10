/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_game_core
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
    game_core->menu_scene.sound = sfSound_create();
    sfSound_setBuffer(game_core->menu_scene.sound, game_core->menu_scene.sound_buffer);
}

void i_music(game_core *game_core)
{
    i_sound_buttons(game_core);
    i_menu_music(&game_core->menu_scene);
}

void i_game_core(game_core *game_core)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}
    , "Bloons TD 5", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    game_core->window = window;
    game_core->game_state = MENU;
    i_game_core_pointers(game_core);
    i_cursor(game_core);
    i_music(game_core);
    i_menu_scene(&game_core->menu_scene, window);
    i_play_scene(&game_core->play_scene, window);
}