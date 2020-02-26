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
    CLICKING,
    CLICKED
} ;

enum game_difficulty {
    EASY,
    NORMAL,
    HARD
} ;

typedef struct cursor {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} cursor;

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
    button map_two_btn;
    button map_three_btn;
    simple_entity map1_name_holder;
    simple_entity map2_name_holder;
    simple_entity map3_name_holder;
} choice_menu;

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
    bool map_selected;
    int opt_state;
    int choice_state;
    int *game_state;
    int *map_index;
    sfEvent *event;
} menu_scene;

typedef struct coord {
    int index;
    sfVector2f pos;
    struct coord *previous;
    struct coord *next;
} coord;

typedef struct map {
    sfSprite *sprite;
    sfTexture *texture_one;
    sfTexture *texture_two;
    sfTexture *texture_three;
    sfVector2f pos;
    int map_index;
    struct coord coord;
} map;

typedef struct play_scene {
    sfRenderWindow *window;
    map map;
    menu_background background;
    int difficulty;
    int *game_state;
    sfEvent *event;
} play_scene;

typedef struct game_core {
    sfRenderWindow *window;
    play_scene play_scene;
    menu_scene menu_scene;
    sfEvent event;
    sfVector2i mouse_pos;
    int game_state;
    cursor mouse_cursor;
} game_core;

//OTHER
void run(void);
char *my_strcat(char *, char *);
int my_strlen(char *str);
button create_button(char *file_path, sfFloatRect rect);
void check_hover_click_ui(menu_scene *menu_scene);
void check_hover_click_opt(menu_scene *menu_scene);
void check_hover_click_options_menu(menu_scene *menu_scene);
void check_hover_click(menu_scene *menu_scene);
void check_hover_click_choosing_map(menu_scene *menu_scene);
void fill_button_textures(button *button, char *file_path);
void hovering_button(menu_scene *menu_scene);
void hovering_choice_menu_buttons(menu_scene *menu_scene);
void hovering_settings_buttons(menu_scene *menu_scene);
bool is_hovering(button button, sfRenderWindow *window);
void quit_interaction(menu_scene *menu_scene);
void settings_interaction(menu_scene *menu_scene);
void play_interaction(menu_scene *menu_scene);
void mouse_click_interaction(menu_scene *menu_scene);
void fill_map_texture(play_scene *play_scene);

//GET
sfVector2i get_mouse_pos(sfRenderWindow *window);

//SET
simple_entity set_simple_entity(char *pathname, sfFloatRect size);
void setscale_state(button *button);
void setscale_allbuttons(menu_scene *menu_scene);
void settexture_state(button *button);
void settexture_allbuttons(menu_scene *menu_scene);

//INITIALISATION
void i_game_core(game_core *game_core);
void i_game_core_pointers(game_core *game_core);
void i_play_scene(play_scene *, sfRenderWindow *);
void i_menu_scene(menu_scene *, sfRenderWindow *);
void i_menu_background(menu_background *menu_background);
void i_opt_background(menu_background *menu_background);
void i_fps_background(menu_background *menu_background);
void i_choice_menu(choice_menu *choice_menu);
void i_menu_ui(menu_ui *menu_ui);
void i_settings_ui(settings_ui *opt_ui);
void i_cursor(game_core *gc);
void i_settings_ui(settings_ui *opt_ui);
void i_choice_menu(choice_menu *choice_menu);
void i_map(play_scene *play_scene);


//UPDATE
void u_game_core(game_core *game_core);
void u_menu_scene(menu_scene *menu_scene);
void u_play_scene(play_scene *play_scene);

//DISPLAY
void d_game_core(game_core *, sfRenderWindow *);

#endif /* !MY_DEFENDER_H_ */
