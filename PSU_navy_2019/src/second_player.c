/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** seconde_player
*/
#include "my.h"
#include "my_navy.h"

static void free_map(char **map)
{
    for (int i = 0; i < 8; i++)
        free(map[i]);
    free(map);
}

static int wait_for_connection(int usr1_pid, char **map)
{
    int usr2_pid = 0;

    kill(usr1_pid, SIGUSR2);
    my_printf("my_pid: %i\n", getpid());
    usr2_pid = wait_signal();
    if (usr2_pid == 0) {
        free_map(map);
        return (84);
    }
    my_putstr("successfully connected\n\n");
    return (0);
}

int second_player(char **av)
{
    int usr1_pid = 0;
    char **map = NULL;
    char **map_enemy = NULL;
    int return_value = 0;

    map = load_map(av[2]);
    if (map == NULL)
        return (84);
    usr1_pid = my_getnbr(av[1]);
    if (wait_for_connection(usr1_pid, map) == 84)
        return (84);
    my_putstr("my positions:\n");
    map_enemy = get_map_p2_print_init_map(map);
    my_putstr("waiting for enemy's attack...\n");
    map = change_map(map, usr1_pid);
    return_value = game_loop(map, map_enemy, usr1_pid, 2);
    return (return_value);
}