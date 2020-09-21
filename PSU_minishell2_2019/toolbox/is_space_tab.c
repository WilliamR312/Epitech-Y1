/*
** EPITECH PROJECT, 2020
** IS_SPACE_TAB
** File description:
** if is space or tab on char
*/

#include "mysh.h"

int is_space_tab(char src)
{
    if (src == 32 || src == 9)
        return (1);
    return (0);
}