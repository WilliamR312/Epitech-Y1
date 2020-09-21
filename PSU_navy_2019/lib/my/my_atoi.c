/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** make a conversion of a char to a int
*/

int my_atoi(char *str)
{
    int nbr_valeur = 0;
    int i = 0;
    int result = 0;

    while (str[nbr_valeur] != '\0')
        nbr_valeur++;
    while (i < nbr_valeur) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result + str[i] - '0';
            result = result * 10;
        }
    }
    result = result / 10;
    return (result);
}
