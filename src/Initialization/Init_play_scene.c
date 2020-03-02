/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_play_scene
*/

#include "../../include/my_defender.h"

void i_hud(play_scene *play_scene)
{
    play_scene->background.background_sprite = sfSprite_create();
    play_scene->background.background_texture = sfTexture_createFromFile("img/play_scene/in_game/game_hud.png", NULL);
    play_scene->background.pos = (sfVector2f){0.0, 0.0};
    sfSprite_setPosition(play_scene->background.background_sprite, play_scene->background.pos);
    sfSprite_setTexture(play_scene->background.background_sprite, play_scene->background.background_texture, sfTrue);
}

void fill_map_texture(play_scene *play_scene)
{
    switch (play_scene->map.map_index) {
        case 1 : sfSprite_setTexture(play_scene->map.sprite,    play_scene->map.texture_one, sfTrue);
            break;
        case 2 : sfSprite_setTexture(play_scene->map.sprite,    play_scene->map.texture_two, sfTrue);
            break;
        case 3 : sfSprite_setTexture(play_scene->map.sprite,    play_scene->map.texture_three, sfTrue);
            break;
        default : break;
    }
}

void i_map(play_scene *play_scene)
{
    play_scene->map.sprite = sfSprite_create();
    play_scene->map.pos = (sfVector2f){235, 0};
    play_scene->difficulty = NORMAL;
    play_scene->map.map_index = 0;
    play_scene->map.coord = malloc(sizeof(coord));
    play_scene->map.coord->index = -1;
    play_scene->map.texture_one = sfTexture_createFromFile("img/play_scene/maps/map1.png", NULL);
    play_scene->map.texture_two = sfTexture_createFromFile("img/play_scene/maps/map2.png", NULL);
    play_scene->map.texture_three = sfTexture_createFromFile("img/play_scene/maps/map3.png", NULL);
    sfSprite_setPosition(play_scene->map.sprite, play_scene->map.pos);
}

void set_difficulty(play_scene *play_scene)
{
    switch (play_scene->difficulty) {
        case EASY : play_scene->player_infos.health = 150;
            break;
        case NORMAL : play_scene->player_infos.health = 100;
            break;
        case HARD : play_scene->player_infos.health = 50;
            break;
    }
}

void set_money(play_scene *play_scene)
{
    play_scene->player_infos.money = 100;
}

void set_texts(play_scene *play_scene)
{
    play_scene->player_infos.money_text = sfText_create();
    play_scene->player_infos.health_text = sfText_create();
    sfText_setPosition(play_scene->player_infos.money_text, (sfVector2f){1580, 56});
    sfText_setPosition(play_scene->player_infos.health_text, (sfVector2f){1580, 120});
    sfText_setString(play_scene->player_infos.money_text, my_itoa
    (play_scene->player_infos.money, play_scene->player_infos.money_str));
    sfText_setString(play_scene->player_infos.health_text, my_itoa
    (play_scene->player_infos.health, play_scene->player_infos.health_str));
}

void i_player_infos(play_scene *play_scene)
{
    set_difficulty(play_scene);
    set_money(play_scene);
    set_texts(play_scene);
}

void set_play_values(play_scene *play_scene)
{
    play_scene->general_clock = sfClock_create();
    fill_map_texture(play_scene);
    set_map_coord(&play_scene->map);
    i_player_infos(play_scene);
    i_font(play_scene);
}

void i_font(play_scene *play_scene)
{
    play_scene->font = sfFont_createFromFile("font/font.TTF");
    sfText_setFont(play_scene->player_infos.health_text, play_scene->font);
    sfText_setFont(play_scene->player_infos.money_text, play_scene->font);
}

void i_dragndrop(play_scene *scene)
{
    scene->dragndrop.sprite = sfSprite_create();
    scene->dragndrop.texture = sfTexture_createFromFile("img/play_scene/towers/turrets.png", NULL);
    sfSprite_setTexture(scene->dragndrop.sprite, scene->dragndrop.texture, sfFalse);
    scene->dragndrop.display = false;
    scene->dragndrop.turret_selected = -1;
    scene->dragndrop.pos = (sfVector2f){0, 0};
}

void i_play_scene(play_scene *play_scene, sfRenderWindow *window)
{
    play_scene->window = window;
    i_hud(play_scene);
    i_map(play_scene);
    i_turrets_price(play_scene);
    i_turret_hud(play_scene);
    i_dragndrop(play_scene);
}