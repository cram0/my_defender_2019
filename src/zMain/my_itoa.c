/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_itoa
*/

#include "../../include/my_defender.h"


char *my_itoa(int number, char *str)  {
    int i = 0;
    while (number != 0) {
        int rest = number % 10;
        str[i++] = (rest > 9)? (rest - 10) + 97 : rest + 48;
        number = number / 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}