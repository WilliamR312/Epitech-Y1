/*
** EPITECH PROJECT, 2020
** TO_NUMBER
** File description:
** if is alpha-num
*/

int is_alpha_num(char src)
{
    if ((src >= 48 && src <= 57) || (src >= 65 && src <= 90) \
    || (src >= 97 && src <= 122))
        return (1);
    return (0);
}