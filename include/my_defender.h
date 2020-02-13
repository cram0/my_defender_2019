/*
** EPITECH PROJECT, 2020
** my_defender.h
** File description:
** my defender header file
*/

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <math.h>

enum game_state {
    PLAY,
    MENU,
    PAUSE
} ;

typedef struct map {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} map;

typedef struct menu_scene {
    sfRenderWindow *window;
} menu_scene;

typedef struct play_scene {
    sfRenderWindow *window;
} play_scene;

typedef struct game_core {
    sfRenderWindow *window;
    play_scene play_scene;
    menu_scene menu_scene;
    sfEvent event;
} game_core;

void run(void);

//INITIALISATION
void i_game_core(game_core *game_core);
void i_play_scene(play_scene *, sfRenderWindow *);

//UPDATE
void u_game_core(game_core *game_core);

//DISPLAY
void d_game_core(game_core *, sfRenderWindow *);
#endif /* !MY_DEFENDER_H_ */
