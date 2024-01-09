/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** check if xe have a dash in av
*/
#include "my.h"

int nbr_to_dash(char **av, int ac)
{
    int i = 1;
    int j = 0;
    int condi = 0;

    while (ac != 1) {
        while (av[i][j] != '\0')
            j++;
        i++;
        ac--;
    }
    return i;
}

char check_letter(char **av, int ac)
{
    int i = 1;
    int j = 0;
    char condi;

    while (ac != 1) {
        j = 0;
        if (av[i][j] == '-') {
            j++;
            condi = av[i][j];
        }
        j++;
        i++;
        ac--;
    }
    return condi;
}

int check_dash(char **av, int ac)
{
    int i = 1;
    int j = 0;
    int condi = 0;

    while (ac != 1) {
        j = 0;
        if (av[i][j] == '-')
            condi++;
        j++;
        i++;
        ac--;
    }
    return condi;
}
