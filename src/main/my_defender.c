/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_defender
*/

#include "../../include/my_defender.h"

int main(int ac, char **av)
{
    if (ac != 1) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            char usage[] = "Bloons TD 5\nUSAGE\n./my_defender\n\nHOW TO PLAY\n";
            char usagetwo[] = "The game in itself is pretty much self explan";
            char usagethree[] = "atory, just drag n drop towers\nnext to the ";
            char usagefour[] = "roads, defend your territory from the evil ";
            char usagefive[] = "bloons !\n";
            write(0, usage, my_strlen(usage));
            write(0, usagetwo, my_strlen(usagetwo));
            write(0, usagethree, my_strlen(usagethree));
            write(0, usagefour, my_strlen(usagefour));
            write(0, usagefive, my_strlen(usagefive));
        }
        return (0);
    }
    else {
        run();
        return (0);
    }
}