/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_strcat
*/

#include "../../include/my_defender.h"

char *my_strcat(char *dest, char *src)
{
    int dest_sz = my_strlen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[dest_sz + i] = src[i];
    }
    dest[dest_sz + i] = '\0';

    return (dest);
}