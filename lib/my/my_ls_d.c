/*
** EPITECH PROJECT, 2023
** my_ls_d
** File description:
** option d
*/
#include "my.h"

int my_ls_d(char *av, int ac)
{
    int i = ac - 2;

    if (ac > 2) {
        my_printf("%s  ", av);
        my_printf("\b\b");
        my_printf("  ");
    }else {
        my_printf("%c\n", '.');
        }
}
