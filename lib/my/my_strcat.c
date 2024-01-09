/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** concatenate two str
*/
#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    my_printf("s");
    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
