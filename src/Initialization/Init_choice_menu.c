/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Init_choice_menu
*/

#include "../../include/my_defender.h"

void i_choice_menu(choice_menu *choice_menu)
{
    choice_menu->background = set_simple_entity("img/menu_scene/choice_menu/choice_menu_bg.png", (sfFloatRect){200, 50, 1521, 900});
    choice_menu->map1_name_holder = set_simple_entity("img/menu_scne/choice_menu/map_name_holder.png", (sfFloatRect){385, 200, 334, 50});
    choice_menu->map2_name_holder = set_simple_entity("img/menu_scne/choice_menu/map_name_holder.png", (sfFloatRect){785, 200, 334, 50});
    choice_menu->map3_name_holder = set_simple_entity("img/menu_scne/choice_menu/map_name_holder.png", (sfFloatRect){1185, 200, 334, 50});
    choice_menu->close_btn = create_button("img/in_game_buttons/close_", (sfFloatRect){1580, 100, 75, 75});
    choice_menu->map_one_btn = create_button("img/menu_scene/choice_menu/map1_",(sfFloatRect){400, 200, 300, 200});
    choice_menu->map_two_btn = create_button("img/menu_scene/choice_menu/map2_",(sfFloatRect){800, 200, 300, 200});
    choice_menu->map_three_btn = create_button("img/menu_scene/choice_menu/map3_",(sfFloatRect){1200, 200, 300, 200});
}