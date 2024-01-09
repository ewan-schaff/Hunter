/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** ceck if file is a directory
*/
#include "my.h"

int check_directory(char *file, int ac)
{
    struct stat s;

    stat(file, &s);
    if (S_ISREG(s.st_mode)) {
        my_printf(file);
        my_printf("  ");
        return 0;
    }else {
        if (ac >= 3) {
            my_printf(file);
            my_printf(":\n");
        }
        my_ls_base(file);
        return 1;
    }
}
