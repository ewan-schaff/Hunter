/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** function that regroup all the error managment function
*/
#include "my.h"

int is_same(char **av, int ac, int i)
{
    if (av[i][0] == '-')
        i++;
    if (ac > 2 && ac <= 3) {
        if (my_strcmp(av[i], "-a") == 0)
            return 84;
        if (my_strcmp(av[i], "-d") == 0)
            return 84;
        if (my_strcmp(av[i], "-l") == 0)
            return 84;
        if (my_strcmp(av[i], "-la") == 0)
            return 84;
        if (my_strcmp(av[i], "-al") == 0)
            return 84;
    }else
        return 0;
}

int error_letter(char **av, struct myls *ls, int ac)
{
    if (av[ls->i][ls->j] != 'a' || av[ls->i][ls->j] != 'd')
        return 84;
    if (av[ls->i][ls->j] != 'l')
        return 84;
}

int error_manage(char **av, struct error *err)
{
    struct stat s;
    int i = 1;

    while (av[i] != NULL) {
        if (stat(av[i], &s) == -1 && av[i][0] != '-')
            return 84;
        i++;
    }
    i = 0;
    while (av[i] != NULL) {
        if (my_strcmp(av[i], "/root") == 0 || my_strcmp(av[i], "/root/") == 0)
            return 84;
        i++;
    }
}
