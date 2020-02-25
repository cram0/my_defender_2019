/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Update_menu_scene
*/

#include "../../include/my_defender.h"

bool is_hovering(button button, sfRenderWindow *window)
{
    if ((get_mouse_pos(window).x > button.pos.x && get_mouse_pos(window).x < (button.pos.x + button.width)) &&
    (get_mouse_pos(window).y > button.pos.y && get_mouse_pos(window).y < (button.pos.y + button.height))) {
        return (true);
    }
    return (false);
}

sfVector2i get_mouse_pos(sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    return cursor;
}

void hovering_button(menu_scene *menu_scene)
{
    if (is_hovering(menu_scene->ui.play_btn, menu_scene->window)) {
        menu_scene->ui.play_btn.state = HOVER;
    } else {
        menu_scene->ui.play_btn.state = IDLE;
    }
    if (is_hovering(menu_scene->ui.hiscore_btn, menu_scene->window)) {
        menu_scene->ui.hiscore_btn.state = HOVER;
    } else {
        menu_scene->ui.hiscore_btn.state = IDLE;
    }
    if (is_hovering(menu_scene->ui.quit_btn, menu_scene->window)) {
        menu_scene->ui.quit_btn.state = HOVER;
    } else {
        menu_scene->ui.quit_btn.state = IDLE;
    }
    if (is_hovering(menu_scene->ui.settings_btn, menu_scene->window)) {
        menu_scene->ui.settings_btn.state = HOVER;
    } else {
        menu_scene->ui.settings_btn.state = IDLE;
    }
}

void hovering_choice_menu_buttons(menu_scene *menu_scene)
{
    if (is_hovering(menu_scene->choice_menu.close_btn, menu_scene->window)) {
        menu_scene->choice_menu.close_btn.state = HOVER;
    } else
        menu_scene->choice_menu.close_btn.state = IDLE;
    if (is_hovering(menu_scene->choice_menu.map_one_btn, menu_scene->window)) {
        menu_scene->choice_menu.map_one_btn.state = HOVER;
    } else
        menu_scene->choice_menu.map_one_btn.state = IDLE;
    if (is_hovering(menu_scene->choice_menu.map_two_btn, menu_scene->window)) {
        menu_scene->choice_menu.map_two_btn.state = HOVER;
    } else
        menu_scene->choice_menu.map_two_btn.state = IDLE;
}

void hovering_settings_buttons(menu_scene *menu_scene)
{
    if (is_hovering(menu_scene->opt_ui.close_button, menu_scene->window)) {
        menu_scene->opt_ui.close_button.state = HOVER;
    } else
        menu_scene->opt_ui.close_button.state = IDLE;
}

void check_hover_click_ui(menu_scene *menu_scene)
{
    if (menu_scene->ui.play_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->ui.play_btn.state = CLICK;
    if (menu_scene->ui.hiscore_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->ui.hiscore_btn.state = CLICK;
    if (menu_scene->ui.settings_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->ui.settings_btn.state = CLICK;
    if (menu_scene->ui.quit_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->ui.quit_btn.state = CLICK;
}

void check_hover_click_opt(menu_scene *menu_scene)
{
    if (menu_scene->opt_ui.close_button.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->opt_ui.close_button.state = CLICK;
    if (menu_scene->choice_menu.close_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->choice_menu.close_btn.state = CLICK;
    if (menu_scene->choice_menu.map_one_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->choice_menu.map_one_btn.state = CLICK;
    if (menu_scene->choice_menu.map_two_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->choice_menu.map_two_btn.state = CLICK;
    if (menu_scene->choice_menu.map_three_btn.state == HOVER && sfMouse_isButtonPressed(sfMouseLeft))
        menu_scene->choice_menu.map_three_btn.state = CLICK;
}

void check_hover_click(menu_scene *menu_scene)
{
    check_hover_click_ui(menu_scene);
    check_hover_click_opt(menu_scene);
}

void settexture_state(button *button)
{
    switch (button->state) {
        case IDLE : sfSprite_setTexture(button->sprite, button->texture_idle,
        sfTrue);
            break;
        case HOVER : sfSprite_setTexture(button->sprite, button->texture_hover,
        sfTrue);
            break;
        case CLICK : sfSprite_setTexture(button->sprite, button->texture_click,
        sfTrue);
            break;
    }
}

void settexture_allbuttons(menu_scene *menu_scene)
{
    settexture_state(&menu_scene->ui.play_btn);
    settexture_state(&menu_scene->ui.hiscore_btn);
    settexture_state(&menu_scene->ui.settings_btn);
    settexture_state(&menu_scene->ui.quit_btn);
    settexture_state(&menu_scene->opt_ui.close_button);
    settexture_state(&menu_scene->choice_menu.close_btn);
    settexture_state(&menu_scene->choice_menu.map_one_btn);
    settexture_state(&menu_scene->choice_menu.map_two_btn);
    settexture_state(&menu_scene->choice_menu.map_three_btn);
}

void setscale_state(button *button)
{
    switch (button->state) {
        case IDLE : sfSprite_setScale(button->sprite, (sfVector2f){1.0, 1.0});
            break;
        case HOVER : sfSprite_setOrigin(button->sprite, (sfVector2f){2, 2});
            sfSprite_setScale(button->sprite, (sfVector2f){1.15, 1.15});
            sfSprite_setPosition(button->sprite, button->pos);
            break;
        case CLICK : sfSprite_setScale(button->sprite, (sfVector2f){0.85, 0.85});
            break;
    }

}

void setscale_allbuttons(menu_scene *menu_scene)
{
    setscale_state(&menu_scene->opt_ui.close_button);
    setscale_state(&menu_scene->choice_menu.close_btn);
}

void quit_interaction(menu_scene *menu_scene)
{
    if (menu_scene->ui.quit_btn.state == CLICK) {
        sfRenderWindow_close(menu_scene->window);
    }
}

void settings_interaction(menu_scene *menu_scene)
{
    if (menu_scene->ui.settings_btn.state == CLICK) {
        menu_scene->opt_state = 1;
    }
    if (menu_scene->opt_ui.close_button.state == CLICK) {
        menu_scene->opt_state = 0;
    }
}

void play_interaction(menu_scene *menu_scene)
{
    if (menu_scene->ui.play_btn.state == CLICK) {
        menu_scene->choice_state = 1;
    }
    if (menu_scene->choice_menu.close_btn.state == CLICK) {
        menu_scene->choice_state = 0;
    }
}

void chose_map(menu_scene *menu_scene)
{


}

void mouse_click_interaction(menu_scene *menu_scene)
{
    quit_interaction(menu_scene);
    settings_interaction(menu_scene);
    play_interaction(menu_scene);
}

void u_menu_scene(menu_scene *menu_scene)
{
    hovering_button(menu_scene);
    hovering_settings_buttons(menu_scene);
    hovering_choice_menu_buttons(menu_scene);
    check_hover_click(menu_scene);
    settexture_allbuttons(menu_scene);
    setscale_allbuttons(menu_scene);
    mouse_click_interaction(menu_scene);
    chose_map(menu_scene);
}