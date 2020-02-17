/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}