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

#define PI 3.14159265

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

enum turret_type {
    SIMPLE_TURRET,
    BOMB_TURRET,
    FREEZE_TURRET,
    SNIPER_TURRET,
    NONE
} ;

typedef struct sound {
    sfSoundBuffer *sound_buffer;
    sfSound *sound;
} sound_t;

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
    simple_entity difficulty_check;
} choice_menu;

typedef struct menu_ui {
    button play_btn;
    button hiscore_btn;
    button settings_btn;
    button quit_btn;
} menu_ui;

typedef struct menu_background {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} menu_background;

typedef struct settings_ui {
    button close_button;
    menu_background background;
    menu_background sound_bg;
    simple_entity check_mark;
    sfRectangleShape *volume_rect;
} settings_ui;

typedef struct menu_scene {
    sfRenderWindow *window;
    struct game_core *game_core;
    menu_background menu_background;
    settings_ui settings_ui;
    menu_ui ui;
    choice_menu choice_menu;
    int settings_state;
    int choice_state;
    int *game_state;
    int *map_index;
    sfEvent *event;
    sfMusic *music;
    sound_t click_sound;
    int sound_state;
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
    coord *coord;
} map;

typedef struct turrets_price {
    int simple;
    int bomb;
    int freeze;
    int sniper;
} turrets_price ;

typedef struct turret_hud {
    sfTexture *sheet;
    sfSprite *simple;
    sfSprite *bomb;
    sfSprite *freeze;
    sfSprite *sniper;
    bool is_buyable_simple;
    bool is_buyable_bomb;
    bool is_buyable_freeze;
    bool is_buyable_sniper;
}  turret_hud;

typedef struct player_infos {
    int health;
    int money;
    sfText *health_text;
    sfText *money_text;
    char health_str[4];
    char money_str[11];
} player_infos;

typedef struct turret_t {
    sfSprite *sprite;
    sfVector2f pos;
    int type;
    int range;
    struct turret_t *previous;
    struct turret_t *next;
} turret_t ;

typedef struct turrets_placed {
    sfTexture *texture;
    turret_t *turrets;
} turrets_placed ;

typedef struct dragndrop {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfCircleShape *circle;
    sfText *price_text;
    int turret_selected;
    bool display;
    char money_str[11];
    char money_str2[11];
    char money_str3[11];
    char money_str4[11];
} dragndrop ;

typedef struct enemy_t {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect hitbox;
    sfRectangleShape *hbar_max;
    sfRectangleShape *hbar;
    bool moving;
    int type;
    int health;
    int max_health;
    int index_reached;
    struct enemy_t *previous;
    struct enemy_t *next;
} enemy_t ;

typedef struct wave_t {
    int index;
    int spawn_rate;
    sfTexture *texture;
    struct enemy_t *enemy;
    struct wave_t *previous;
    struct wave_t *next;
} wave_t ;

typedef struct pause_menu {
    simple_entity background;
    button resume;
    button restart;
    button main_menu;
    button quit;
} pause_menu ;

typedef struct play_scene {
    sfRenderWindow *window;
    struct game_core *game_core;
    map map;
    turrets_placed turrets_placed;
    turrets_price turret_price;
    turret_hud turret_hud;
    dragndrop dragndrop;
    player_infos player_infos;
    menu_background background;
    wave_t *waves;
    sfTexture *enemy_texture;
    pause_menu pause_menu;
    button pause_btn;
    button wave_btn;
    sfClock *movement_clock;
    bool playing;
    int wave_max;
    int pause_state;
    int sound_state;
    int difficulty;
    int *game_state;
    sfClock *general_clock;
    sfEvent *event;
    sfFont *font;
    sfMusic *music;
    sound_t click_sound;
    sound_t set_turret_sound;
    sfText *wave_text;
    sfText *wave_number;
    sfText *wave_button;
    sfText *setting_txt;
    char wave_button_str[99];
    char settings_str[9];
    char wave_max_str[999];
    char wave_str[11];
} play_scene;

typedef struct game_core {
    sfRenderWindow *window;
    sfMusic *music;
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
char *my_revstr(char *str);
char *my_itoa(int number, char* str);
button create_button(char *file_path, sfFloatRect rect);
void check_hover_click_ui(menu_scene *menu_scene);
void check_hover_click_settings(menu_scene *menu_scene);
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
void fps_selection(menu_scene *menu_scene);
int fps_selection_two(sfVector2i pos, simple_entity check);
void fill_coord_three(map *map);
void fill_coord_two(map *map);
void fill_coord_one(map *map);
void add_coord(map *map, sfVector2f list[], int len);
void add_coord_node(coord *node, sfVector2f pos, int index);
void change_texture_dnd(play_scene *scene);
void change_origin_dnd(play_scene *scene);
int is_the_turret_in_zones(play_scene *scene);
bool is_mouse_in_map(play_scene *scene);

//GET
sfVector2i get_mouse_pos(sfRenderWindow *window);

//SET
simple_entity set_simple_entity(char *pathname, sfFloatRect size);
void setscale_state(button *button);
void setscale_allbuttons(menu_scene *menu_scene);
void settexture_state(button *button);
void settexture_allbuttons(menu_scene *menu_scene);
void set_difficulty(play_scene *play_scene);
void set_money(play_scene *play_scene);
void set_play_values(play_scene *play_scene);
void set_map_coord(map *map);
void set_texts(play_scene *play_scene);
void set_dnd_texts(play_scene *play_scene);
void set_hbars_enemy(enemy_t *enemy);

//INITIALISATION
void i_game_core(game_core *game_core);
void i_game_core_pointers(game_core *game_core);
void i_play_scene(play_scene *, sfRenderWindow *);
void i_menu_scene(menu_scene *, sfRenderWindow *);
void i_menu_background(menu_background *menu_background);
void i_settings_background(menu_background *menu_background);
void i_choice_menu(choice_menu *choice_menu);
void i_menu_ui(menu_ui *menu_ui);
void i_music(game_core *game_core);
void i_sound_buttons(game_core *game_core);
void i_settings_ui(settings_ui *settings_ui);
void i_cursor(game_core *gc);
void i_settings_ui(settings_ui *settings_ui);
void i_choice_menu(choice_menu *choice_menu);
void i_map(play_scene *play_scene);
void i_font(play_scene *play_scene);
void i_turrets_price(play_scene *scene);
void i_turret_hud(play_scene *scene);
void i_turret_hud_two(play_scene *scene);
void i_dragndrop(play_scene *scene);
void i_font(play_scene *play_scene);
void i_player_infos(play_scene *play_scene);
void i_text_out_thick(play_scene *play_scene);

//UPDATE
void u_game_core(game_core *game_core);
void u_menu_scene(menu_scene *menu_scene);
void u_play_scene(play_scene *play_scene);
void u_turret_hud(play_scene *scene);
void check_is_n_buyable(play_scene *scene);
void check_is_buyable(play_scene *scene);
void u_turret_hud_money(play_scene *scene);
void u_turret_click_hud_two(play_scene *scene);
void u_turret_click_hud(play_scene *scene);
void u_turret_click_hud_pos(play_scene *scene, sfVector2i pos);
void u_turret_click_hud_pos_two(play_scene *scene, sfVector2i pos);
void u_escape_interaction(play_scene *play_scene);
void u_turret_tracking(play_scene *scene);
void u_turret_direction(enemy_t *enemy, turret_t *turret);


//DISPLAY
void d_game_core(game_core *, sfRenderWindow *);

#endif /* !MY_DEFENDER_H_ */
