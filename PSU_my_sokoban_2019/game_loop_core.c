/*
** EPITECH PROJECT, 2019
** GAME_LOOP_CORE_H
** File description:
** manage game loop
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

static void check_screen_size(map_data_t *map_d)
{
    int row = 0;
    int col = 0;

    getmaxyx(stdscr, row, col);
    while (row < map_d->rows || col < map_d->max_col) {
        mvprintw(row / 2, ( col - 20) / 2, "%s","enlarge the terminal");
        refresh();
        clear();
        getmaxyx(stdscr, row, col);
    }
}

static void display_map(map_data_t *map_d, char **map_2d)
{
    check_screen_size(map_d);
    for (int i = 0; i < map_d->rows; i++) {
        printw("%s", map_2d[i]);
    }
}

static void check_victory(map_data_t *map_d, char **map_2d)
{
    int hole = 0;
    int a = 0;
    int b = 0;

    if (map_d->over == 1)
        return;
    for (int i = 0; i < map_d->size; i++) {
        if (map_2d[a][b] == 'O')
            return;
        if (map_2d[a][b] == '\n') {
            a++;
            b = 0;
        }
        else
            b++;
    }
    if (hole == 0)
        map_d->game_state = 1;
}

static void check_fail(map_data_t *map_d, char **map_2d)
{
    int a = 0;
    int b = 0;
    int count = 0;

    for (int i = 0; i < map_d->size; i++) {
        if (map_2d[a][b] == 'X' && (((map_2d[a][b + 1] == '#' || \
        map_2d[a][b - 1] == '#') && (map_2d[a + 1][b] == '#' || \
        map_2d[a - 1][b] == '#')))) {
            map_d->game_state = 2;
        }
        if (map_2d[a][b] == '\n') {
            a++;
            b = 0;
        }
        else
            b++;
    }
}

void game_loop_core(map_data_t *map_d, char **map_2d)
{
    int x = 0;
    int y = 0;
    int key = 0;

    initscr();
    cbreak ();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    while (key != ' ' && map_d->game_state == 0) {
        clear();
        display_map(map_d, map_2d);
        key = getch();
        move_player(key, map_d, map_2d);
        refresh();
        check_fail(map_d, map_2d);
        check_victory(map_d, map_2d);
    }
}