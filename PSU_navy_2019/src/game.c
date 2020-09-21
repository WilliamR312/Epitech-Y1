/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game
*/
#include "my.h"
#include "my_navy.h"

static int verif_answer(char *answer)
{
    int i = 0;

    for (; answer[i] != '\0'; i++);
    if (i != 3 || answer[0] < 65 || answer[0] > 72 || \
    answer[1] < 49 || answer[1] > 56)
        return (84);
    return (0);
}

static int launch_the_game(char *answer, char ***maps, int pid, int player)
{
    int return_value = 0;

    maps[1] = change_enemy_map(maps[1], answer, pid);
    return_value = check_all_result(maps[0], maps[1]);
    if (return_value != 2)
        return (return_value);
    if (return_value == 2 && player == 2)
        display_all_maps(maps[0], maps[1]);
    write(1, "waiting for enemy's attack...\n", 31);
    maps[0] = change_map(maps[0], pid);
    return_value = check_all_result(maps[0], maps[1]);
    if (return_value == 2 && player == 1)
        display_all_maps(maps[0], maps[1]);
    return (return_value);
}

static int make_action(char *answer, char ***maps, int pid, int player)
{
    int result = 0;

    result = launch_the_game(answer, maps, pid, player);
    return (result);
}

static char ***get_maps_tab(char **map, char **map_enemy)
{
    char ***maps = NULL;

    maps = malloc(sizeof(char **) * 2);
    maps[0] = map;
    maps[1] = map_enemy;
    return (maps);
}

int game_loop(char **map, char **map_enemy, int pid, int player)
{
    char *answer = NULL;
    int result = 2;
    size_t size = 0;
    int read = 0;
    char ***maps = NULL;

    maps = get_maps_tab(map, map_enemy);
    while (result == 2) {
        write(1, "attack: ", 9);
        read = getline(&answer, &size, stdin);
        if (read == EOF)
            result = 84;
        answer[read] = '\0';
        if (verif_answer(answer) == 0) {
            result = make_action(answer, maps, pid, player);
        } else
            write(1, "wrong position\n", 16);
        answer = NULL;
    }
    free_ressources(maps);
    return (result);
}