/*
** EPITECH PROJECT, 2020
** MY_STRSTR
** File description:
** Identifies a sub_string in a string passed as parameter, need i return NULL?
*/

char *my_strstr(char *str, char const *to_find)
{
    int first_match = -1;

    for (unsigned long i = 0; str[i] && first_match == -1; i++) {
        if (str[i] == to_find[0])
            first_match = i;
    }
    if (first_match == -1)
        return (0);
    for (unsigned long i = first_match, j = 0; to_find[j]; i++, j++) {
        if (str[i] != to_find[j])
            return (0);
    }
    return (str);
}