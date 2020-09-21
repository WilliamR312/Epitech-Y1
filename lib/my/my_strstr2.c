/*
** EPITECH PROJECT, 2020
** MY_STRSTR
** File description:
** Identifies a sub_string in a string passed as parameter, return position
*/

int my_strstr2(char *str, char const *to_find)
{
    int first_match = -1;
    int position = 0;

    for (unsigned long i = 0; str[i] && first_match == -1; i++) {
        if (str[i] == to_find[0])
            first_match = i;
    }
    if (first_match == -1)
        return (-1);
    for (int i = first_match, j = 0; to_find[j]; i++, j++) {
        if (str[i] != to_find[j])
            return (-1);
    }
    position = first_match;
    return (position);
}