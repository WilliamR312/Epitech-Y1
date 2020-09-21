/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** compare string character
*/

int my_strcmp(char *str, char *other_str)
{
    int i = 0;

    for (; other_str[i] != '\0'; i++) {
        if (str[i] != other_str[i]) {
            return (1);
        }
    }
    if (str[i] != '\0')
        return (1);
    return (0);
}