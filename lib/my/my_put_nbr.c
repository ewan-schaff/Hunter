/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** return a number sent to the fonction string
*/
#include "my.h"

void condi_0(int nb)
{
    if (nb == 0){
        my_putchar('0');
    }
}

void recursion(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 0){
        recursion(nb / 10);
        my_putchar('0' + nb % 10);
    }
}

int my_put_nbr(int nb)
{
    condi_0(nb);
    if (nb == -2147483648){
        my_putstr("-2");
        nb -= 2000000000;
        recursion(nb);
    }else{
        recursion(nb);
    }
    return 0;
}
