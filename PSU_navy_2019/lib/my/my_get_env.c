/*
** EPITECH PROJECT, 2020
** lib
** File description:
** get someting in env
*/
#include "../../include/my.h"

char *my_get_env(char **envp, char *str_finding)
{
    char *object = NULL;
    int temp = 0;
    int len_str = 0;
    int len_env = 0;

    for (;str_finding[len_str] != '\0'; len_str++);
    for (int i = 0, x = 0; envp[i] != NULL; i++) {
        for (;envp[i][x] == str_finding[x]; x++);
        if (x == len_str)
            temp = i;
        x = 0;
    }
    len_str++;
    len_env = len_str;
    for (;envp[temp][len_env] != '\0'; len_env++);
    object = malloc(sizeof(char) * len_env);
    if (temp != 0)
        for (int j = 0;envp[temp][len_str] != '\0';len_str++, j++)
            object[j] = envp[temp][len_str];
    return (object);
}