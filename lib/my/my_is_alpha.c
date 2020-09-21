/*
** EPITECH PROJECT, 2020
** TO_NUMBER
** File description:
** if is alpha-num
*/

int is_alpha(char c)
{
    if ((c >= 65 && c <= 90) \
    || (c >= 97 && c <= 122))
        return (1);
    return (0);
}