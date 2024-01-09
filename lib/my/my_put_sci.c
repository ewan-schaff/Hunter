/*
** EPITECH PROJECT, 2023
** my_put_scti
** File description:
** displai float in scientifist expresion
*/
#include <stdio.h>
#include "my.h"

char put_zero_low(long nb_size)
{
    if (nb_size <= 9) {
        my_putchar('0');
        my_put_nbr_long(nb_size);
    }
    if (nb_size > 9) {
        my_put_nbr_long(nb_size);
    }
}

int entire_zero(double nb_double, long entire)
{
    int nb_size = 0;

    while (entire == 0) {
        nb_double *= 10;
        entire = nb_double;
        nb_size++;
    }
    my_put_float(nb_double);
    my_putchar('e');
    my_putchar('-');
    put_zero_low(nb_size);
    return 0;
}

int entire_sup_zero_low(double nb_double, long nb_size)
{
    while (nb_double >= 10) {
        nb_double /= 10;
        nb_size++;
    }
    my_put_float(nb_double);
    my_putchar('e');
    my_putchar('+');
    put_zero_low(nb_size);
    return 0;
}

float my_put_sci(double nb)
{
    double nb_double = nb;
    long entire = nb;
    long i = 0;
    long nb_size = 0;

    if (nb < 0) {
        nb_double = nb * - 1;
        my_putchar('-');
    }
    if (entire == 0) {
        entire_zero(nb_double, entire);
        return 0;
    }
    entire_sup_zero_low(nb_double, nb_size);
}
