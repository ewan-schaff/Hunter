/*
** EPITECH PROJECT, 2023
** space flag
** File description:
** make the flag even if it has a ' ' between the % and the letter
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

int space_flag(const char *format, int i)
{
    int j = 0;
    int condi = 0;

    if (format[i] == ' ' && condi != 1){
        my_putchar(' ');
        condi++;
    }
    while (format[i] != '\0') {
        if (format[i] == ' ') {
            j++;
            i++;
        }else
            break;
    }
    return j;
}
