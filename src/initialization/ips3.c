/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ips3
*/

#include "../../include/my_defender.h"

void set_wave_text(play_scene *play_scene)
{
    play_scene->wave_text = sfText_create();
    play_scene->wave_number = sfText_create();
    sfText_setPosition(play_scene->wave_text, (sfVector2f){280, 900});
    sfText_setString(play_scene->wave_text, "Wave :");
    sfText_setPosition(play_scene->wave_number, (sfVector2f){400, 900});
    sfText_setString(play_scene->wave_number,
    my_itoa(play_scene->wave_max, play_scene->wave_max_str));
    play_scene->wave_button = sfText_create();
    sfText_setPosition(play_scene->wave_button, (sfVector2f){1370 - 510, 906});
    sfText_setString(play_scene->wave_button, "Next Wave / Force Next Wave");
    play_scene->setting_txt = sfText_create();
    sfText_setPosition(play_scene->setting_txt, (sfVector2f){1454 - 200, 906});
    sfText_setString(play_scene->setting_txt, "Menu");

}

void set_dnd_texts(play_scene *play_scene)
{
    play_scene->dragndrop.price_text = sfText_create();
    sfText_setPosition(play_scene->dragndrop.price_text,
    (sfVector2f){1580, 184});
    sfText_setString(play_scene->dragndrop.price_text, my_itoa
    (play_scene->turret_price.bomb, play_scene->dragndrop.money_str));
    play_scene->victory_txt = sfText_create();
    play_scene->loose_txt = sfText_create();
    play_scene->yr_score_txt = sfText_create();
    play_scene->score = sfText_create();
    sfText_setPosition(play_scene->victory_txt, (sfVector2f){500, 900});
    sfText_setPosition(play_scene->loose_txt, (sfVector2f){500, 900});
    sfText_setPosition(play_scene->yr_score_txt, (sfVector2f){500, 950});
    sfText_setPosition(play_scene->score, (sfVector2f){825, 950});
    sfText_setString(play_scene->victory_txt, "You Win !");
    sfText_setString(play_scene->loose_txt, "You Lost...");
    sfText_setString(play_scene->yr_score_txt, "Your Final Score :");
}

void set_texts(play_scene *play_scene)
{
    play_scene->player_infos.money_text = sfText_create();
    play_scene->player_infos.health_text = sfText_create();
    play_scene->player_infos.score_text = sfText_create();
    play_scene->score_text_dot = sfText_create();
    sfText_setPosition(play_scene->player_infos.money_text,
    (sfVector2f){1580, 56});
    sfText_setPosition(play_scene->player_infos.health_text,
    (sfVector2f){1580, 120});
    sfText_setPosition(play_scene->score_text_dot,
    (sfVector2f){1525, 750});
    sfText_setPosition(play_scene->player_infos.score_text,
    (sfVector2f){1610, 800});
    sfText_setString(play_scene->player_infos.money_text, my_itoa
    (play_scene->player_infos.money, play_scene->player_infos.money_str));
    sfText_setString(play_scene->player_infos.health_text, my_itoa
    (play_scene->player_infos.health, play_scene->player_infos.health_str));
    sfText_setString(play_scene->player_infos.score_text, my_itoa
    (play_scene->player_infos.score, play_scene->player_infos.score_str));
    sfText_setString(play_scene->score_text_dot, "Score");
    set_wave_text(play_scene);
}

void set_turret_node(play_scene *scene)
{
    scene->turrets_placed.texture = sfTexture_createFromFile
    ("img/play_scene/towers/turrets.png", NULL);
    scene->turrets_placed.turrets = NULL;
    scene->turrets_placed.turrets = malloc(sizeof(turret_t));
    scene->turrets_placed.turrets->range = -1;
}

int set_enemy_health(int type)
{
    switch (type) {
        case 1 : return (1);
        case 2 : return (2);
        case 3 : return (3);
        case 4 : return (4);
        case 5 : return (5);
        case 6 : return (6);
        case 7 : return (7);
        case 8 : return (8);
        default : return (1);
    }
}