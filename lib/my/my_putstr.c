/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** display one by one the characters of a string
*/
#include "my.h"

int my_putstr(char const *str)
{
    int i = 1;

    &str[0];
    my_putchar(str[0]);
    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
}
