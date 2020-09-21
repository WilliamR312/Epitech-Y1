/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** index
*/
#include "../../../include/my.h"

void base_binaire(unsigned int value)
{
    base_system(value, "01");
}

void base_octal(unsigned int value)
{
    base_system(value, "01234567");
}

void base_eighteen(unsigned int value)
{
    base_system(value, "0123456789abcdef");
}

void base_eighteen_up(unsigned int value)
{
    base_system(value, "0123456789ABCDEF");
}