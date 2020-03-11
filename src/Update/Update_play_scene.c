/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_play_scene
*/

#include "../../include/my_defender.h"

void change_texture_dnd(play_scene *scene)
{
    dragndrop *dnd = &scene->dragndrop;
    if (dnd->turret_selected == SIMPLE_TURRET)
        sfSprite_setTextureRect(dnd->sprite, (sfIntRect){0, 0, 67, 69});
    if (dnd->turret_selected == BOMB_TURRET)
        sfSprite_setTextureRect(dnd->sprite, (sfIntRect){0, 167, 73, 83});
    if (dnd->turret_selected == FREEZE_TURRET)
        sfSprite_setTextureRect(dnd->sprite, (sfIntRect){0, 250, 99, 99});
    if (dnd->turret_selected == SNIPER_TURRET)
        sfSprite_setTextureRect(dnd->sprite, (sfIntRect){0, 69, 67, 98});
}

void change_origin_dnd(play_scene *scene)
{
    dragndrop *dnd = &scene->dragndrop;
    if (dnd->turret_selected == SIMPLE_TURRET)
        sfSprite_setOrigin(dnd->sprite, (sfVector2f){67 / 2, 69 / 2});
    if (dnd->turret_selected == BOMB_TURRET)
        sfSprite_setOrigin(dnd->sprite, (sfVector2f){73 / 2, 83 / 2});
    if (dnd->turret_selected == FREEZE_TURRET)
        sfSprite_setOrigin(dnd->sprite, (sfVector2f){99 / 2, 99 / 2});
    if (dnd->turret_selected == SNIPER_TURRET)
        sfSprite_setOrigin(dnd->sprite, (sfVector2f){67 / 2, 98 / 2});
}

void u_turret_click_hud_two(play_scene *scene)
{
    if (scene->dragndrop.display == true) {
        change_origin_dnd(scene);
        change_texture_dnd(scene);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
            sfSprite_setPosition(scene->dragndrop.sprite, (sfVector2f){pos.x, pos.y});
        }
    }
}

void u_turret_click_hud_pos_two(play_scene *scene, sfVector2i pos)
{
    if (pos.x >= 1513 && pos.x <= 1588 && pos.y >= 277 && pos.y <= 352 && scene->turret_hud.is_buyable_freeze) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = FREEZE_TURRET;
    }
    if (pos.x >= 1600 && pos.x <= 1675 && pos.y >= 277 && pos.y <= 352 && scene->turret_hud.is_buyable_sniper) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = SNIPER_TURRET;
    }
}

void u_turret_click_hud_pos(play_scene *scene, sfVector2i pos)
{
    if (pos.x >= 1513 && pos.x <= 1588 && pos.y >= 193 && pos.y <= 256 && scene->turret_hud.is_buyable_simple) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = SIMPLE_TURRET;
    }
    if (pos.x >= 1600 && pos.x <= 1675 && pos.y >= 193 && pos.y <= 256 && scene->turret_hud.is_buyable_bomb) {
        scene->dragndrop.display = true;
        scene->dragndrop.turret_selected = BOMB_TURRET;
    }
    u_turret_click_hud_pos_two(scene, pos);
}

int set_turret_range(int turret_type)
{
    switch (turret_type) {
        case SIMPLE_TURRET : return (100);
        case BOMB_TURRET : return (75);
        case FREEZE_TURRET : return (50);
        case SNIPER_TURRET : return (999999);
        default : return (0);
    }
}

void set_turret_texture(sfSprite *sprite, int turret_type, sfTexture *tx)
{
    sfSprite_setTexture(sprite, tx, sfFalse);
    switch (turret_type) {
        case SIMPLE_TURRET : sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 67, 69});
            break;
        case BOMB_TURRET : sfSprite_setTextureRect(sprite, (sfIntRect){0, 167, 73, 83});
            break;
        case FREEZE_TURRET : sfSprite_setTextureRect(sprite, (sfIntRect){0, 250, 99, 99});
            break;
        case SNIPER_TURRET : sfSprite_setTextureRect(sprite, (sfIntRect){0, 69, 67, 98});
            break;
    }
}

void set_turret_origin(sfSprite *sprite, int type)
{
    switch (type) {
        case SIMPLE_TURRET : sfSprite_setOrigin(sprite, (sfVector2f){67 / 2, 69 / 2});
            break;
        case BOMB_TURRET : sfSprite_setOrigin(sprite, (sfVector2f){73 / 2, 83 / 2});
            break;
        case FREEZE_TURRET : sfSprite_setOrigin(sprite, (sfVector2f){99 / 2, 99 / 2});
            break;
        case SNIPER_TURRET : sfSprite_setOrigin(sprite, (sfVector2f){67 / 2, 98 / 2});
            break;
    }
}

void add_turret_node_existing(play_scene *scene, int type, sfVector2i pos,
sfTexture *tx)
{
    scene->turrets_placed.turrets->sprite = sfSprite_create();
    scene->turrets_placed.turrets->pos = (sfVector2f){pos.x, pos.y};
    set_turret_texture(scene->turrets_placed.turrets->sprite, type, tx);
    set_turret_origin(scene->turrets_placed.turrets->sprite, type);
    sfSprite_setPosition(scene->turrets_placed.turrets->sprite, scene->turrets_placed.turrets->pos);
    scene->turrets_placed.turrets->type = type;
    scene->turrets_placed.turrets->range = set_turret_range(type);
    scene->turrets_placed.turrets->previous = NULL;
    scene->turrets_placed.turrets->next = NULL;
}

void add_turret_node_non_existing(play_scene *scene, int type, sfVector2i pos,
sfTexture *tx)
{
    turret_t *temp = malloc(sizeof(turret_t));
    while (scene->turrets_placed.turrets->next != NULL)
        scene->turrets_placed.turrets = scene->turrets_placed.turrets->next;
    temp->sprite = sfSprite_create();
    temp->pos = (sfVector2f){pos.x, pos.y};
    set_turret_texture(temp->sprite, type, tx);
    set_turret_origin(temp->sprite, type);
    sfSprite_setPosition(temp->sprite, temp->pos);
    temp->type = type;
    temp->range = set_turret_range(type);
    scene->turrets_placed.turrets->next = temp;
    temp->previous = scene->turrets_placed.turrets;
    temp->next = NULL;
}

void add_turret_node(play_scene *scene, int type, sfVector2i pos, sfTexture *tx)
{
    if (scene->turrets_placed.turrets->range == -1) {
        add_turret_node_existing(scene, type, pos, tx);
    } else {
        add_turret_node_non_existing(scene, type, pos, tx);
    }
}

void place_turret(play_scene *scene, int type, sfVector2i pos, sfTexture *tx)
{
    switch (type) {
        case SIMPLE_TURRET : add_turret_node(scene, SIMPLE_TURRET, pos, tx);
            break;
        case BOMB_TURRET : add_turret_node(scene, BOMB_TURRET, pos, tx);
            break;
        case FREEZE_TURRET : add_turret_node(scene, FREEZE_TURRET, pos, tx);
            break;
        case SNIPER_TURRET : add_turret_node(scene, SNIPER_TURRET, pos, tx);
            break;
    }
}

void u_turret_click_hud(play_scene *scene)
{
    if (scene->event->mouseButton.type == sfEvtMouseButtonPressed) {
        sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
        u_turret_click_hud_pos(scene, pos);
    }
    if (scene->event->mouseButton.type == sfEvtMouseButtonReleased) {
        if (scene->dragndrop.turret_selected != NONE)
            place_turret(scene, scene->dragndrop.turret_selected, sfMouse_getPositionRenderWindow(scene->window), scene->turrets_placed.texture);
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
    if (scene->wave_btn.state == HOVER && scene->event->mouseButton.type == sfEvtMouseButtonReleased)
            scene->wave_btn.state = CLICKED;
    setscale_state(&scene->wave_btn);
}

void u_pause_button(play_scene *scene)
{
    if (is_hovering(scene->pause_btn, scene->window))
        scene->pause_btn.state = HOVER;
    else
        scene->pause_btn.state = IDLE;
    if (scene->pause_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft)) {
        scene->pause_btn.state = CLICKING;
        if (scene->sound_state == 0) {
            sfSound_play(scene->sound);
            scene->sound_state = 1;
        }
    }
    if (scene->pause_btn.state == HOVER && scene->event->mouseButton.type == sfEvtMouseButtonReleased) {
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

void u_pause_menu_hover_click(play_scene *scene)
{
    button *buttons[4];
    buttons[0] = &scene->pause_menu.resume;
    buttons[1] = &scene->pause_menu.restart;
    buttons[2] = &scene->pause_menu.main_menu;
    buttons[3] = &scene->pause_menu.quit;
    for (int i = 0; i < 4; i++)
        if (buttons[i]->state == HOVER && sfMouse_isButtonPressed(sfMouseLeft)) {
            buttons[i]->state = CLICKING;
            if (scene->sound_state == 0) {
                sfSound_play(scene->sound);
                scene->sound_state = 1;
            }
        }
    for (int i = 0; i < 4; i++)
        if (buttons[i]->state == HOVER && scene->event->mouseButton.type == sfEvtMouseButtonReleased) {
            buttons[i]->state = CLICKED;
            scene->sound_state = 0;
        }
}

void u_pause_menu_hover(play_scene *scene)
{
    button *buttons[4];
    buttons[0] = &scene->pause_menu.resume;
    buttons[1] = &scene->pause_menu.restart;
    buttons[2] = &scene->pause_menu.main_menu;
    buttons[3] = &scene->pause_menu.quit;
    for (int i = 0; i < 4; i++) {
        if (is_hovering(*buttons[i], scene->window))
            buttons[i]->state = HOVER;
        else
            buttons[i]->state = IDLE;
    }
}

void u_pause_menu(play_scene *scene)
{
    u_pause_menu_hover(scene);
    u_pause_menu_hover_click(scene);
    setscale_state(&scene->pause_menu.resume);
    setscale_state(&scene->pause_menu.restart);
    setscale_state(&scene->pause_menu.main_menu);
    setscale_state(&scene->pause_menu.quit);
}

void u_pause_menu_interactions(play_scene *scene)
{
    if (scene->pause_menu.quit.state == CLICKED)
        sfRenderWindow_close(scene->window);
    if (scene->pause_menu.restart.state == CLICKED)
        set_play_values(scene);
    if (scene->pause_menu.resume.state == CLICKED)
        scene->pause_state = 0;
    if (scene->pause_menu.main_menu.state == CLICKED) {
        *scene->game_state = MENU;
        sfMusic_play(scene->game_core->menu_scene.music);
        scene->map.map_index = 0;
        scene->pause_state = 0;
    }
}

void u_hud(play_scene *scene)
{
    u_turret_hud(scene);
    u_turret_click_hud(scene);
    if (scene->pause_state == 0)
        u_pause_button(scene);
    if (scene->pause_state == 1) {
        u_pause_menu(scene);
        u_pause_menu_interactions(scene);
    }
    u_escape_interaction(scene);
    u_wave_button(scene);
}

void u_waves(play_scene *scene)
{
    // while (scene->waves->enemy->)
}

void u_play_scene(play_scene *scene)
{
    u_hud(scene);
    u_waves(scene);
}