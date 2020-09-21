/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

char *my_strcat_separate(char *dest, char const *src, char separate)
{
    int i = 0;

    for (;dest[i] != '\0';i++);
    dest[i] = separate;
    i++;
    for (int a = 0;src[a] != '\0'; i++, a++)
        dest[i] = src[a];
    dest[i] = '\0';
    return (dest);
}
