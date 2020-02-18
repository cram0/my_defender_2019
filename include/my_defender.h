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
#include <stdbool.h>

enum game_state {
    PLAY,
    MENU
} ;

enum button_state {
    IDLE,
    HOVER,
    CLICK
} ;

typedef struct button {
    sfSprite *sprite;
    sfTexture *texture_idle;
    sfTexture *texture_hover;
    sfTexture *texture_click;
    sfVector2f pos;
    int width;
    int height;
    int state;
} button;

typedef struct simple_entity {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    float width;
    float height;
} simple_entity;

typedef struct choice_menu {
    simple_entity background;
    button close_btn;
    button map_one_btn;
} choice_menu;

typedef struct map {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} map;

typedef struct menu_ui {
    button play_btn;
    button hiscore_btn;
    button settings_btn;
    button quit_btn;
} menu_ui;

typedef struct menu_background {
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfVector2f pos;
} menu_background;

typedef struct settings_ui {
    button close_button;
    menu_background background;
    menu_background fps_bg;
    menu_background sound_bg;
} settings_ui;

typedef struct menu_scene {
    sfRenderWindow *window;
    menu_background menu_background;
    settings_ui opt_ui;
    menu_ui ui;
    choice_menu choice_menu;
    int opt_state;
    int choice_state;
    int *game_state;
} menu_scene;

typedef struct play_scene {
    sfRenderWindow *window;
    int *game_state;
} play_scene;

typedef struct game_core {
    sfRenderWindow *window;
    play_scene play_scene;
    menu_scene menu_scene;
    sfEvent event;
    sfVector2i mouse_pos;
    int game_state;
} game_core;

//OTHER
void run(void);
char *my_strcat(char *, char *);
int my_strlen(char *str);

//GET
sfVector2i get_mouse_pos(sfRenderWindow *window);

//SET
simple_entity set_simple_entity(char *pathname, sfFloatRect size);

//INITIALISATION
void i_game_core(game_core *game_core);
void i_play_scene(play_scene *, sfRenderWindow *);
void i_menu_scene(menu_scene *menu_scene, sfRenderWindow *);
void i_menu_background(menu_background *menu_background);
void i_menu_ui(menu_ui *menu_ui);

//UPDATE
void u_game_core(game_core *game_core);
void u_menu_scene(menu_scene *menu_scene);

//DISPLAY
void d_game_core(game_core *, sfRenderWindow *);

#endif /* !MY_DEFENDER_H_ */
