/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** ceck if file is a directory
*/
#include "my.h"

int check_directory_d(char *file, int ac)
{
    struct stat s;

    stat(file, &s);
    if (S_ISREG(s.st_mode)) {
        my_printf(file);
        my_printf("  ");
        return 0;
    }else {
        my_ls_d(file, ac);
        return 1;
    }
}
