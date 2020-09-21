/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    for (;dest[i] != '\0';i++);
    for (int a = 0;src[a] != '\0'; i++, a++)
        dest[i] = src[a];
    return (dest);
}