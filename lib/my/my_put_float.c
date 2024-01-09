/*
** EPITECH PROJECT, 2023
** my_put_float
** File description:
** display float number
*/
#include <stdio.h>
#include "my.h"

int size_nb(long entire)
{
    long size = 1;
    int i = 0;

    while (size <= entire) {
        size *= 10;
        i++;
    }
    return (i);
}

char put_zero(double nb_float)
{
    if (size_nb(nb_float) == 5)
        my_putstr("0");
    if (size_nb(nb_float) == 4)
        my_putstr("00");
    if (size_nb(nb_float) == 3)
        my_putstr("000");
    if (size_nb(nb_float) == 2)
        my_putstr("0000");
    if (size_nb(nb_float) == 1)
        my_putstr("00000");
    if (size_nb(nb_float) == 0)
        my_putstr("000000");
}

int nb_round(double nb, long entire)
{
    long i = nb * 10000000;
    long x = nb * 1000000;
    int res = i - (x * 10);

    if (res >= 5 && res <= 9)
        entire++;
    return entire;
}

int nb_supp(long entire, double nb_double)
{
    if (entire < 0) {
        my_putchar('-');
        entire *= - 1;
    }
    entire += 1;
    my_put_nbr_long(entire);
    my_putchar('.');
    my_putstr("000000");
    return 0;
}

static int nb_sup_zero(long entire, double nb_double, double nb)
{
    if (nb_double < 0)
        nb_double *= - 1;
    nb_double -= entire;
    nb -= entire;
    entire = nb_double * 1000000;
    entire = nb_round(nb, entire);
    put_zero(entire);
    my_put_nbr_long(entire);
}

double my_put_float(double nb)
{
    long entire = nb;
    double nb_double = nb;
    long i = (nb - entire) * 10000000;

    if (i == 9999999 || i == -9999999 || i == -9999998) {
        nb_supp(entire, nb_double);
        return 0;
    }
    if (nb < 0 ) {
        entire *= -1;
        my_putchar('-');
    }
    if (entire == 0)
        my_putchar('0');
    my_put_nbr_long(entire);
    my_putchar('.');
    nb_sup_zero(entire, nb_double, nb);
}
