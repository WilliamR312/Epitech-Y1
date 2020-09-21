/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** made a print convert
*/
#include "../../../include/my.h"

static int prefix2(char const *format, int i)
{
    while (format[i] == '#') {
        i++;
        if (format[i] == 'x')
            my_putstr("0x");
        if (format[i] == 'X')
            my_putstr("0X");
        if (format[i] == 'o')
            my_putchar('0');
    }
    return (i);
}

static int prefix(char const *format, int i)
{
    int x = 0;

    for (;format[i] == ' '; i++);
    while (format[i] == '+') {
        i++;
        if (x == 0 && format[i] == 'd' || x == 0 && format[i] == 'i') {
            my_putchar('+');
            x++;
        }
    }
    for (;format[i] == '-'; i++);
    i = prefix2(format, i);
    return (i);
}

void my_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            i = prefix(format, i);
            disp_stdarg(format[i], ap);
        }
        else
            my_putchar(format[i]);
    }
    va_end(ap);
}