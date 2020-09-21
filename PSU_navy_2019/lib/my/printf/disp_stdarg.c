/*
** EPITECH PROJECT, 2019
** bootstrap_my_printf
** File description:
** must print all argument
*/
#include "../../../include/my.h"

static void except(char flag_c, va_list ap)
{
    if (flag_c == '%') {
        my_putchar('%');
        return;
    } else if (flag_c == 'c') {
        my_putchar(va_arg(ap, int));
        return;
    }
}

void disp_stdarg(char flag_c, va_list ap)
{
    int y = -1;
    char flag[9] = "idsSXouxb";
    static void (*print[9])() = {my_put_nbr, my_put_nbr, my_putstr, \
    my_putstr_all, base_eighteen_up, base_octal, my_put_u_nbr, \
    base_eighteen, base_binaire};

    if (flag_c == '%' || flag_c == 'c') {
        except(flag_c, ap);
        return;
    }
    for (int x = 0; x != 10 && y == -1; x++)
        if (flag[x] == flag_c)
            y = x;
    if (y < 3)
        print[y](va_arg(ap, int));
    else if (y < 5)
        print[y](va_arg(ap, char *));
    else
        print[y](va_arg(ap, unsigned int));
}
