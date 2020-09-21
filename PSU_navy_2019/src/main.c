/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/
#include "my.h"
#include "my_navy.h"

static int check_error(int ac, char **av)
{
    int test = 0;

    if (ac == 2) {
        test = open(av[1], O_RDONLY);
        if (test == -1) {
            close(test);
            return (84);
        }
    } else if (ac == 3) {
        test = open(av[2], O_RDONLY);
        if (test == -1) {
            close(test);
            return (84);
        }
        if (verif_if_nbr(av[1]) == 1)
            return (84);
    } else {
        return (84);
    }
    close(test);
    return (0);
}

static int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    first_player_pid: only for the \
    2nd player. pid of the first player.\n");
    my_putstr("    navy_positions: file representing the \
    positions of the ships.\n");
    return (0);
}

int main(int ac, char **av)
{
    int check = 0;

    if (ac == 1)
        return (84);
    else if (av[1][0] == '-' && av[1][1] == 'h')
        return (help());
    check = check_error(ac, av);
    if (ac == 2 && check != 84)
        return (first_player(av));
    else if (ac == 3 && check != 84)
        return (second_player(av));
    else
        return (84);
}