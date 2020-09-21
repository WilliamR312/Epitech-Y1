/*
** EPITECH PROJECT, 2020
** TO_NUMBER
** File description:
** to number "+-+-42" is -42
*/

#include "my.h"

static int compare_string(char const *str, char *compare, int pos_nbr)
{
    for (int i = 0; i < 10; i++) {
        if (str[pos_nbr] - 48 > compare[i] - 48)
            return (1);
        pos_nbr++;
    }
    return (0);
}

static int check_limit(char const *str, int pos_nbr, int nbr_size)
{
    char less[] = "2147483648";
    char plus[] = "2147483647";

    if (nbr_size > 10)
        return (1);
    if (str[pos_nbr - 1] == 45)
        return (compare_string(str, less, pos_nbr));
    else
        return (compare_string(str, plus, pos_nbr));
    return (0);
}

static int search_pos_nbr(char const *str, int pos_nbr)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 48 && str[i] <= 57 && pos_nbr == -1) {
            pos_nbr = i;
            return (pos_nbr);
        }
    }
    return (pos_nbr);
}

int my_getnbr(char const *str)
{
    int pos_nbr = -1;
    int nbr_size = 0;
    int result = 0;
    int more = 1;

    pos_nbr = search_pos_nbr(str, pos_nbr);
    for (int i = pos_nbr; str[i] >= 48 && str[i] <= 57 && str[i] != '\0'; i++)
        nbr_size++;
    for (int i = 0; i < nbr_size; i++) {
        result = result + (str[pos_nbr + nbr_size - 1 - i] - 48 ) * more;
        more = more * 10;
    }
    if (pos_nbr != 0)
        if (str[pos_nbr - 1] == 45)
            result = result * (-1);
    if ((nbr_size == 10 && check_limit(str, pos_nbr, nbr_size) == 1) || \
    pos_nbr == -1)
        return (0);
    return (result);
}