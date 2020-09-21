/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** init_map_first_player
*/
#include "my.h"
#include "my_navy.h"

char **gen_empty_map(void)
{
    char **map = NULL;

    map = malloc(sizeof(char *) * 9);
    map[8] = NULL;
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
        map[i][8] = '\0';
    }
    return (map);
}

static char **free_for_end(int fd, char *buffer)
{
    close(fd);
    free(buffer);
    return (NULL);
}

static int check_separator(char *src)
{
    int count = 0;

    for (int i = 0; src[i]; i++) {
        if (src[i] == ':')
            count++;
    }
    if (count == 8)
        return (1);
    return (0);
}

char **read_pos_boat(char *file)
{
    char *buffer = NULL;
    char **boat_position = NULL;
    int fd = 0;
    ssize_t check_read = 0;

    buffer = malloc(sizeof(char) * 32);
    buffer[31] = '\0';
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (free_for_end(fd, buffer));
    check_read = read(fd, buffer, 32);
    if (check_read != 32 || check_separator(buffer) == 0)
        return (free_for_end(fd, buffer));
    boat_position = my_str_to_word_array(buffer, '\n');
    free_for_end(fd, buffer);
    return (boat_position);
}