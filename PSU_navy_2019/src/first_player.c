/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** first_player
*/
#include "my.h"
#include "my_navy.h"

static void free_map(char **map)
{
    for (int i = 0; i < 8; i++)
        free(map[i]);
    free(map);
}

static void sig_starting(int pid)
{
    write(1, "\nenemy connected\n\n", 18);
    usleep(100000);
    kill(pid, SIGUSR1);
}

int first_player(char **av)
{
    char **map = NULL;
    char **map_enemy = NULL;
    int pid = 0;
    int return_value = 0;

    map = load_map(av[1]);
    if (map == NULL)
        return (84);
    my_printf("my_pid: %i\n", getpid());
    my_putstr("waiting for enemy connection...\n");
    pid = wait_signal();
    if (pid == 0) {
        free_map(map);
        return (84);
    }
    sig_starting(pid);
    my_putstr("my positions:\n");
    map_enemy = get_map_p2_print_init_map(map);
    return_value = game_loop(map, map_enemy, pid, 1);
    return (return_value);
}