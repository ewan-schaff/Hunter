/*
** EPITECH PROJECT, 2023
** m_printf.c
** File description:
** make our own printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

int flag_upper(va_list list, const char *format, int i)
{
    switch (format[i]) {
        case 'X':
            my_put_hexa_up(va_arg(list, int));
            break;
        case 'F':
            my_put_float(va_arg(list, double));
            break;
        case 'E':
            my_put_sci_up(va_arg(list, double));
            break;
        case 'e':
            my_put_sci(va_arg(list, double));
            break;
    }
}

int flag_with_letter(va_list list, const char *format, int i)
{
    switch (format[i]) {
        case 'c':
            my_putchar(va_arg(list, int));
            break;
        case 's':
            my_putstr(va_arg(list, char *));
            break;
        case 'x':
            my_put_hexa_low(va_arg(list, long));
            break;
        case '%':
            my_putchar('%');
            break;
        case 'p':
            my_put_hexa_base(va_arg(list, long));
            break;
        default:
            flag_upper(list, format, i);
    }
}

int decimal_flag(va_list list, const char *format, int i)
{
    switch (format[i]) {
        case 'i':
            my_put_nbr(va_arg(list, int));
            break;
        case 'd':
            my_put_nbr(va_arg(list, int));
            break;
        case 'u':
            my_put_nbr_long(va_arg(list, long));
            break;
        case 'o':
            my_put_octal(va_arg(list, int));
            break;
        case 'f':
            my_put_float(va_arg(list, double));
            break;
        default:
            flag_with_letter(list, format, i);
    }
}

int my_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            format[i++];
            i += space_flag(format, i);
            decimal_flag(list, format, i);
        }else
            my_putchar(format[i]);
    }
    va_end(list);
}
