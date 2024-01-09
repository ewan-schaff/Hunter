/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** return a number sent to the fonction string
*/
#include "my.h"

int my_put_nbr_long(long nb)
{
    long i = 1000000000;
    long var = 0;
    long j;

    if (nb < 0) {
        return 0;
    }
    while (nb < i ){
        i = i / 10 ;
    }
    while (i != 0) {
        if ( nb / i >= 0) {
            var = nb / i;
            my_putchar(var + 48);
            nb -= i * var;
        }
        i = i / 10;
    }
}
