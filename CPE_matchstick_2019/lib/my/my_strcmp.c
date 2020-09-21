/*
** EPITECH PROJECT, 2019
** MY_STRCMP
** File description:
** it cmps 2 strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (int j = 0; s1[j] != '\0' && s2[j] != '\0'; j++);
    if (s1[i] == '\0' && s2[i] != '\0') {
        for (int j = 0; s2[j] !=  '\0'; i--, j++);
        return (i);
    }
    if (s2[i] == '\0' && s1[i] != '\0') {
        for (int j = 0; s1[j] !=  '\0'; i++, j++);
        return (i);
    }
    return (0);
}