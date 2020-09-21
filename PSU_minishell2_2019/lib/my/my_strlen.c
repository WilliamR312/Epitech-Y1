/*
** EPITECH PROJECT, 2020
** MY_STRLEN
** File description:
** returns the length of an array, does not count the '\0'
*/

int my_strlen(char const *src)
{
    int length = 0;

    for (; src[length] != '\0'; length++);
    return (length);
}