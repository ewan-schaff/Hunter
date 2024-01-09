/*
** EPITECH PROJECT, 2023
** my_put_octal.c
** File description:
** display octal
*/
#include "my.h"

int my_put_octal(int nb)
{
    int octal = 0;
    int mul = 1;
    int var = 0;

    if (nb == 0)
        my_putchar('0');
    if (nb < 0){
        nb *= - 1;
        my_putchar('-');
    }
    while (nb != 0) {
        octal = nb % 8;
        var += octal * mul;
        nb = nb / 8;
        mul = mul * 10;
    }
    my_put_nbr_long(var);
}
