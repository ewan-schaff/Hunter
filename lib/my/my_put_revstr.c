/*
** EPITECH PROJECT, 2023
** my_put_revstr
** File description:
** my_put_revstr
*/
#include <unistd.h>
#include "my.h"

void my_put_revstr(const char *str)
{
    int last = my_strlen(str)-1;

    while (last >= 0){
        my_putchar(str[last]);
        last--;
    }
}
