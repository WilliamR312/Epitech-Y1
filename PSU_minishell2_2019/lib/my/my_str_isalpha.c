/*
** EPITECH PROJECT, 2020
** MY_STR_ISALPHA
** File description:
** Check if str is only alpha.
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(('a' >= str[i] && str[i] <= 'z')\
        || ('A' >= str[i] && str[i] <= 'Z')))
            return (0);
    }
    return (0);
}