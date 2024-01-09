/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** recreat the ls function
*/
#include "my.h"

int my_ls_a(char *file)
{
    DIR *dir;
    struct stat s;
    struct dirent *entry;

    dir = opendir(file);
    while (true) {
        entry = readdir(dir);
        if (entry == 0)
            break;
        my_printf("%s  ", entry->d_name);
    }
    my_printf("\n");
    closedir(dir);
}
