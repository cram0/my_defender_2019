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

void change_origin_circle(play_scene *scene)
{
    dragndrop *dnd = &scene->dragndrop;
    if (dnd->turret_selected == SIMPLE_TURRET) {
        sfCircleShape_setOrigin(dnd->circle, (sfVector2f){150, 150});
        sfCircleShape_setRadius(dnd->circle, 150);
    }
    if (dnd->turret_selected == BOMB_TURRET) {
        sfCircleShape_setOrigin(dnd->circle, (sfVector2f){90, 90});
        sfCircleShape_setRadius(dnd->circle, 90);
    }
    if (dnd->turret_selected == FREEZE_TURRET) {
        sfCircleShape_setOrigin(dnd->circle, (sfVector2f){100, 100});
        sfCircleShape_setRadius(dnd->circle, 100);
    }
    if (dnd->turret_selected == SNIPER_TURRET) {
        sfCircleShape_setOrigin(dnd->circle, (sfVector2f){1999, 1999});
        sfCircleShape_setRadius(dnd->circle, 1999);
    }
}

void change_price_dnd( play_scene *scene)
{
    dragndrop *dnd = &scene->dragndrop;
    if (dnd->turret_selected == SIMPLE_TURRET) {
        sfText_setString(scene->dragndrop.price_text, my_itoa(scene->turret_price.simple, scene->dragndrop.money_str));
    }
    if (dnd->turret_selected == BOMB_TURRET) {
        sfText_setString(scene->dragndrop.price_text, my_itoa(scene->turret_price.bomb, scene->dragndrop.money_str2));
    }
    if (dnd->turret_selected == FREEZE_TURRET) {
        sfText_setString(scene->dragndrop.price_text, my_itoa(scene->turret_price.freeze, scene->dragndrop.money_str3));
    }
    if (dnd->turret_selected == SNIPER_TURRET) {
        sfText_setString(scene->dragndrop.price_text, my_itoa(scene->turret_price.sniper, scene->dragndrop.money_str4));
    }
}

void u_turret_click_hud_two(play_scene *scene)
{
    if (scene->dragndrop.display == true) {
        change_origin_dnd(scene);
        change_texture_dnd(scene);
        change_origin_circle(scene);
        change_price_dnd(scene);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
            sfSprite_setPosition(scene->dragndrop.sprite, (sfVector2f){pos.x, pos.y});
            sfCircleShape_setPosition(scene->dragndrop.circle, (sfVector2f){pos.x, pos.y});
            sfText_setPosition(scene->dragndrop.price_text, (sfVector2f){pos.x - 50, pos.y - 100});
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
        case SIMPLE_TURRET : return (150);
        case BOMB_TURRET : return (90);
        case FREEZE_TURRET : return (100);
        case SNIPER_TURRET : return (1999);
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
    turret_t *temp = NULL;
    temp = malloc(sizeof(turret_t));
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

int is_out_path_1(int x, int y)
{
    if ((x >= 853 && x <= 924 && y >= 0 && y <= 138) || (x >= 440 && x <= 924 &&
        y >= 60 && y <= 138) || (x >= 440 && x <= 524 && y >= 60 && y <= 685) ||
        (x >= 440 && x <= 1133 && y >= 603 && y <= 685) ||
        (x >= 1040 && x <= 1133 && y >= 283 && y <= 685) ||
        (x >= 850 && x <= 1133 && y >= 283 && y <= 359) ||
        (x >= 850 && x <= 935 && y >= 283 && y <= 565) ||
        (x >= 635 && x <= 935 && y >= 486 && y <= 565) ||
        (x >= 635 && x <= 724 && y >= 175 && y <= 565) ||
        (x >= 635 && x <= 1333 && y >= 175 && y <= 249) ||
        (x >= 1243 && x <= 1333 && y >= 175 && y <= 805) ||
        (x >= 860 && x <= 1333 && y >= 726 && y <= 805) ||
        (x >= 860 && x <= 944 && y >= 726 && 870)) {
            return (0);
        }
    return 1;
}

int is_out_path_3(int x, int y)
{
    if ((x >= 390 && x <= 445 && y >= 0 && y <= 180) || (x >= 390 && x <= 748 &&
        y >= 124 && y <= 179) || (x >= 690 && x <= 748 && y >= 124 && y <= 467) ||
        (x >= 390 && x <= 748 && y >= 394 && y <= 467) ||
        (x >= 390 && x <= 452 && y >= 400 && y <= 816) ||
        (x >= 390 && x <= 745 && y >= 762 && y <= 816) ||
        (x >= 683 && x <= 745 && y >= 488 && y <= 816) ||
        (x >= 685 && x <= 838 && y >= 488 && y <= 544) ||
        (x >= 776 && x <= 838 && y >= 126 && y <= 544) ||
        (x >= 776 && x <= 1373 && y >= 126 && y <= 187) ||
        (x >= 1312 && x <= 1373 && y >= 126 && y <= 462) ||
        (x >= 1062 && x <= 1373 && y >= 404 && y <= 462) ||
        (x >= 1062 && x <= 1117 && y >= 404 && y <= 544) ||
        (x >= 1062 && x <= 1373 && y >= 488 && y <= 544) ||
        (x >= 1300 && x <= 1373 && y >= 488 && y <= 822) ||
        (x >= 1300 && x <= 1500 && y >= 756 && y <= 822)) {
            return (0);
        }
    return 1;
}

int is_the_turret_in_zones(play_scene *scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
    int x = pos.x;
    int y = pos.y;
    if (is_mouse_in_map(scene)) {
        if (scene->map.map_index == 1) {
            if (is_out_path_1(x, y) == 1)
                return (1);
        }
        if (scene->map.map_index == 2) {
            return (1);
        }
        if (scene->map.map_index == 3) {
            if (is_out_path_3(x, y) == 1)
                return (1);
        }
    }
    return (-1);
}

void u_turret_range_color(play_scene *scene)
{
    if (is_the_turret_in_zones(scene) > 0) {
        sfCircleShape_setFillColor(scene->dragndrop.circle, sfColor_fromRGBA(218,128,128,128));
    } else {
        sfCircleShape_setFillColor(scene->dragndrop.circle, sfColor_fromRGBA(255,255,255,128));
    }
}

void u_turret_click_hud(play_scene *scene)
{
    if (scene->event->mouseButton.type == sfEvtMouseButtonPressed) {
        sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
        u_turret_click_hud_pos(scene, pos);
    }
    if (scene->event->mouseButton.type == sfEvtMouseButtonReleased) {
        if (scene->dragndrop.turret_selected != NONE) {
            if (is_the_turret_in_zones(scene) == 1) {
                place_turret(scene, scene->dragndrop.turret_selected, sfMouse_getPositionRenderWindow(scene->window), scene->turrets_placed.texture);
                sfSound_play(scene->set_turret_sound.sound);
            }
        }
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
    if (scene->wave_btn.state == HOVER && scene->event->type == sfEvtMouseButtonReleased) {
        scene->wave_btn.state = CLICKED;
        scene->wave_max += 1;
        if (scene->wave_max >= 9)
            scene->wave_max = 9;
    }
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
            sfSound_play(scene->click_sound.sound);
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
                sfSound_play(scene->click_sound.sound);
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
        scene->map.map_index = 0;
        scene->pause_state = 0;
    }
}

void u_hud_text(play_scene *scene)
{
    sfText_setString(scene->wave_text, "Wave :");
    sfText_setString(scene->wave_number, my_itoa(scene->wave_max, scene->wave_max_str));
    sfText_setString(scene->player_infos.money_text, my_itoa
    (scene->player_infos.money, scene->player_infos.money_str));
    sfText_setString(scene->player_infos.health_text, my_itoa
    (scene->player_infos.health, scene->player_infos.health_str));
}

void u_hud(play_scene *scene)
{
    u_turret_hud(scene);
    u_turret_click_hud(scene);
    if (scene->pause_state == 0) {
        u_pause_button(scene);
        u_wave_button(scene);
    }
    if (scene->pause_state == 1) {
        u_pause_menu(scene);
        u_pause_menu_interactions(scene);
    }
    u_hud_text(scene);
}

void u_turret_direction(play_scene *scene, turret_t *turret)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
    int x1 = turret->pos.x;
    int y1 = turret->pos.y;
    int x2 = pos.x;
    int y2 = pos.y;
    int dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double angle = atan2(y2 - y1, x2 - x1) * 180 / PI;
    if (dist <= turret->range) {
        sfSprite_setRotation(turret->sprite, angle + 90);
    }
}

bool is_mouse_in_map(play_scene *scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
    int x = pos.x;
    int y = pos.y;
    if (x >= 236 && x <= 1496 && y >= 0 && y <= 871) {
        return true;
    }
    return false;
}

void u_turret_tracking(play_scene *scene)
{
    if (scene->turrets_placed.turrets->range != -1 && is_mouse_in_map(scene)) {
        while (scene->turrets_placed.turrets->previous != NULL) {
            scene->turrets_placed.turrets = scene->turrets_placed.turrets->previous;
        }
        u_turret_direction(scene, scene->turrets_placed.turrets);
        while (scene->turrets_placed.turrets->next != NULL) {
            u_turret_direction(scene, scene->turrets_placed.turrets);
            scene->turrets_placed.turrets = scene->turrets_placed.turrets->next;
            if (scene->turrets_placed.turrets->next == NULL) {
                u_turret_direction(scene, scene->turrets_placed.turrets);
            }
        }
    }
}

void u_waves(play_scene *scene)
{
    while (scene->waves->previous != NULL)
        scene->waves = scene->waves->previous;
    while (scene->waves->index != scene->wave_max) {
        while (scene->waves->enemy->previous != NULL)
            scene->waves->enemy = scene->waves->enemy->previous;
        while (scene->waves->enemy->next != NULL) {
            if (scene->waves->enemy->previous == NULL) {
                scene->waves->enemy->moving = true;
            }
            else {
                if (scene->waves->enemy->previous->moving == true && sfTime_asSeconds(sfClock_getElapsedTime(scene->movement_clock)) >= 1 && scene->waves->enemy->moving == false) {
                    scene->waves->enemy->moving = true;
                    sfClock_restart(scene->movement_clock);
                }
            }
            while (scene->map.coord->previous != NULL)
                scene->map.coord = scene->map.coord->previous;
            while (scene->map.coord->next != NULL) {
                if (scene->map.coord->index - 1 == scene->waves->enemy->index_reached) {
                    if (scene->waves->enemy->pos.x >= scene->map.coord->pos.x - 4 && scene->waves->enemy->pos.x <= scene->map.coord->pos.x + 4 && scene->waves->enemy->pos.y >= scene->map.coord->pos.y - 4 && scene->waves->enemy->pos.y <= scene->map.coord->pos.y + 4) {
                        scene->waves->enemy->index_reached += 1;
                    }
                    if (scene->waves->enemy->pos.x < scene->map.coord->pos.x && scene->waves->enemy->moving == true)
                        scene->waves->enemy->pos.x += 0.06 * sfTime_asMilliseconds(sfClock_getElapsedTime(scene->general_clock));
                    if (scene->waves->enemy->pos.x > scene->map.coord->pos.x && scene->waves->enemy->moving == true)
                        scene->waves->enemy->pos.x -= 0.06 * sfTime_asMilliseconds(sfClock_getElapsedTime(scene->general_clock));
                    if (scene->waves->enemy->pos.y < scene->map.coord->pos.y && scene->waves->enemy->moving == true)
                        scene->waves->enemy->pos.y += 0.06 * sfTime_asMilliseconds(sfClock_getElapsedTime(scene->general_clock));
                    if (scene->waves->enemy->pos.y > scene->map.coord->pos.y && scene->waves->enemy->moving == true)
                        scene->waves->enemy->pos.y -= 0.06 * sfTime_asMilliseconds(sfClock_getElapsedTime(scene->general_clock));
                    sfSprite_setPosition(scene->waves->enemy->sprite, scene->waves->enemy->pos);
                }
                scene->map.coord = scene->map.coord->next;
            }
            scene->waves->enemy = scene->waves->enemy->next;
        }
        if (scene->waves->enemy->previous == NULL) {
            scene->waves->enemy->moving = true;
        }
        else {
            if (scene->waves->enemy->previous->moving == true && sfTime_asSeconds(sfClock_getElapsedTime(scene->movement_clock)) >= 1 && scene->waves->enemy->moving == false) {
                scene->waves->enemy->moving = true;
                sfClock_restart(scene->movement_clock);
            }
        }
        scene->waves = scene->waves->next;
    }
}

void u_play_scene(play_scene *scene)
{
    u_hud(scene);
    u_waves(scene);
    u_turret_tracking(scene);
    sfClock_restart(scene->general_clock);
}