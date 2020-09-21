/*
** EPITECH PROJECT, 2019
** MY_STR_ISPRINTABLE
** File description:
** tests if you can print the string
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 0 && str[i] > 127)
            return (0);
    }
    return (1);
}