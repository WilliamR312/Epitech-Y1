/*
** EPITECH PROJECT, 2019
** GET_MAP_1D_H
** File description:
** used to get 1d map from the file
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/my_sokoban.h"
#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static char *get_map_1d(char *pathname, map_data_t *map_d, char *map_1d)
{
    int fd = 0;

    map_1d = malloc(sizeof(char) * map_d->size + 1);
    map_1d[map_d->size] = '\0';
    fd = open(pathname, O_RDONLY);
    if (fd == -1)
        exit(84);
    read(fd, map_1d, map_d->size);
    close(fd);
    return (map_1d);
}

static void get_file_size(char *pathname, map_data_t *map_d)
{
    int size = 0;
    struct stat st;

    stat(pathname, &st);
    size = st.st_size;
    if (size < 12)
        exit(84);
    map_d->size = size;
}

char **map_to_mem_management(char *pathname, map_data_t *map_d)
{
    int fd = 0;
    int file_size = 0;
    int nbr_line = 0;
    char *map_1d;
    char **map_2d;

    get_file_size(pathname, map_d);
    map_1d = get_map_1d(pathname, map_d, map_1d);
    map_2d = get_map_2d(map_d, map_1d, map_2d);
    free(map_1d);
    return (map_2d);
}