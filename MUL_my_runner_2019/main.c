/*
** EPITECH PROJECT, 2020
** MAIN
** File description:
** Main for my_runner
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "my_runner.h"
#include "my.h"

static void help_display(void)
{
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n ./my_runner map.txt\n\n\n");
    my_putstr("OPTIONS\n -i        launch the game in infinity mode.\n");
    my_putstr(" -h        print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n SPACE_KEY        jump.\n\n");
    my_putstr("[FOR MAPPING]\n -create your map named map.txt,\
    use TILE MAPPING and respect RULES (lower down).\n\n");
    my_putstr(">TILE MAPPING<\n - 1 : for block (plateform over).\n ");
    my_putstr("- 2 : for spike (collision with player kill him).\n\n");
    my_putstr(">RULES<\n - max useful map size : 7 lines.\
    \n - carriage return at the end.\n");
    my_putstr(" - the player appears on the third line from the end,\
    keep his spawn area clear !\n");
}

static void bad_arg(int nb_arg)
{
    if (nb_arg == 1)
        my_putstr("./my_runner: bad arguments: 0 given but 1 is requiered\n");
    else {
        my_putstr("./my_runner: bad arguments: too many given but 1 is\
        requiered\n");
    }
    my_putstr("retry with -h\n");
}

int main(int nb_arg, char **argv)
{
    core_t core_d;

    if (nb_arg > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0')
            help_display();
    }
    if (nb_arg == 2 && map_load(&core_d.map_d, argv[1]) == 1)
        game_core(&core_d);
    else {
        bad_arg(nb_arg);
        return (84);
    }
    return (0);
}