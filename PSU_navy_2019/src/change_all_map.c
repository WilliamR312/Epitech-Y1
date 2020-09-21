/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** change_all_map
*/
#include "my.h"
#include "my_navy.h"

char **change_map(char **map, int pid)
{
    int pos[2] = {0, 0};
    char pos_letter = 0;

    pos[0] = count_signal();
    pos[1] = count_signal();
    if (map[pos[1] - 1][pos[0] - 1] != '.' && \
    map[pos[1] - 1][pos[0] - 1] != 'o') {
        my_printf("%c%i: hit\n\n", pos[0] + 64, pos[1]);
        map[pos[1] - 1][pos[0] - 1] = 'x';
        kill(pid, SIGUSR1);
    } else {
        my_printf("%c%i: missed\n\n", pos[0] + 64, pos[1]);
        map[pos[1] - 1][pos[0] - 1] = 'o';
        kill(pid, SIGUSR2);
    }
    return (map);
}

char **change_enemy_map(char **map, char *answer, int pid)
{
    int pos[2] = {0, 0};
    int result = 0;

    pos[0] = answer[0] - 64;
    pos[1] = answer[1] - 48;
    for (int i = 0; i < pos[0]; i++) {
        kill(pid, SIGUSR1);
        usleep(100000);
    }
    kill(pid, SIGUSR2);
    usleep(100000);
    for (int i = 0; i < pos[1]; i++) {
        kill(pid, SIGUSR1);
        usleep(100000);
    }
    kill(pid, SIGUSR2);
    result = wait_result_sig();
    map = attack_result(result, pos, answer, map);
    return (map);
}
