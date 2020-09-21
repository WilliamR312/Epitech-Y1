/*
** EPITECH PROJECT, 2019
** MAIN_MY_HUNTER
** File description:
** Main my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my_hunter.h"
#include "./include/my.h"

int main(int nb_arg, char **argv)
{
    if (nb_arg > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            help_display();
        }
    } else {
        game_loop();
    }
    return (0);
}