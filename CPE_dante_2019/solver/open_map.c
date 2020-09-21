/*
** EPITECH PROJECT, 2020
** open_map
** File description:
** open a map
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_solv.h"
#include "struct.h"

static void final_assignement(solver_t *solver, char **map, \
ssize_t prev_read, ssize_t nb_lines)
{
    nb_lines -= 1;
    map[nb_lines] = NULL;
    solver->info_maze.size_x = prev_read;
    solver->info_maze.size_y = nb_lines;
}

char **copy_map(char **map, FILE *fd, solver_t *solver)
{
    size_t len = 0;
    ssize_t prev_read = 0;
    ssize_t read = 0;
    int nb_lines = 0;

    map = malloc(sizeof(char *) * 1);
    for (int i = 0; read != -1; i++, nb_lines++) {
        map[i] = NULL;
        read = getline(&map[i], &len, fd);
        if (read != -1) {
            prev_read = read;
            if (map[i][read - 1] == '\n')
                map[i][read - 1] = '\0';
            map = realloc(map, sizeof(char *) * (i + 2));
        } else
            free(map[i]);
    }
    final_assignement(solver, map, prev_read, nb_lines);
    return (map);
}

static int check_map_error(char **map, int size_x, int size_y)
{
    int size = 0;

    if (size_x == 0 || size_y == 0)
        return (1);
    for (int y = 0; y < size_y; y++) {
        for (int x = 0; map[y][x] != '\0'; x++, size++) {
            if (map[y][x] != 'X' && map[y][x] != '*')
                return (1);
        }
        if (size != size_x)
            return (1);
        size = 0;
    }
    if (size_x == 1 && size_y == 1)
        return (1);
    return (0);
}

static void free_map(char **map)
{
    for (int y = 0; map[y] != NULL; y++)
        free(map[y]);
    free(map);
}

char **get_map(char **map, char *path, solver_t *solver)
{
    FILE *fd = NULL;

    fd = fopen(path, "r");
    if (fd == NULL)
        return (NULL);
    map = copy_map(map, fd, solver);
    fclose(fd);
    if (check_map_error(map, solver->info_maze.size_x, \
    solver->info_maze.size_y)) {
        free_map(map);
        return (NULL);
    }
    return (map);
}