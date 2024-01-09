/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** recreat the ls function
*/
#include "my.h"

int my_ls_base(char *file)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(file);
    while (true) {
        entry = readdir(dir);
        if (entry == 0)
            break;
        if (entry->d_name[0] != '.')
            my_printf("%s  ", entry->d_name);
    }
    closedir(dir);
}
