/*
** EPITECH PROJECT, 2020
** MY_STRUPCASE
** File description:
** Switches a string to uppercase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    }
    return (str);
}