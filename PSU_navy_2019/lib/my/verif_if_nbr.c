/*
** EPITECH PROJECT, 2020
** lib
** File description:
** verif_if_nbr
*/

int verif_if_nbr(char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++)
        if (arg[i] < 48 || arg[i] > 57)
            return (1);
    return (0);
}