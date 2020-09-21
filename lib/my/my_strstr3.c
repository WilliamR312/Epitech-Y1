/*
** EPITECH PROJECT, 2020
** MY_STRSTR3
** File description:
** Identifies a STRICT end sub string in a string passed as parameter.
*/

int my_strstr3(char *str, char const *to_find)
{
    int first_match = -1;
    int end = 0;

    for (unsigned long i = 0; str[i] && first_match == -1; i++) {
        if (str[i] == to_find[0])
            first_match = i;
    }
    if (first_match == -1)
        return (0);
    for (unsigned long i = first_match, j = 0; to_find[j]; i++, j++, end++) {
        if (str[i] != to_find[j])
            return (0);
    }
    if (str[first_match + end] != to_find[end])
        return (0);
    return (1);
}