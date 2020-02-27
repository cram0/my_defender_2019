/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_revstr
*/

#include "../../include/my_defender.h"

char *my_revstr(char *str)
{
    int str_sz = my_strlen(str) - 1;
    char buffer;

    for (int i = 0; i < str_sz;  i++) {
        buffer = str[i];
        str[i] = str[str_sz];
        str[str_sz] = buffer;
        str_sz--;
    }

    return (str);
}