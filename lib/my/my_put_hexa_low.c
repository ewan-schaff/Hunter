/*
** EPITECH PROJECT, 2023
** my_put_hexa_min
** File description:
** display an hexa
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int size_low(int nb)
{
    int size = 0;
    int nb2 = nb;

    while (nb2 != 0) {
        nb2 = nb2 / 16;
        size++;
    }
}

long my_put_hexa_low(long nb)
{
    long hexa = 0;
    char *str;
    long i = 0;
    char letter;

    str = malloc(sizeof(char) * size_low(nb));
    if (nb == 0)
        my_putchar('0');
    while (nb != 0) {
        hexa = nb % 16;
        nb = nb / 16;
        if (hexa >= 10 && hexa <= 15)
            letter = hexa + 87;
            str[i] = letter;
        if (hexa >= 0 && hexa <= 9) {
            str[i] = hexa + 48;
        }
        i++;
    }
    my_put_revstr(str);
}
