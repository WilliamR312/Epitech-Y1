/*
** EPITECH PROJECT, 2020
** CATCH_IMPUT
** File description:
** Used to catch user imput
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

static int check_error_getline(int size, char *line, shell_t *shell_d)
{
    int cmd = 0;

    if (size == 1 || size == -1) {
        if (size == 1 || size == 0) {
            free(line);
            return (1);
        } else {
            free(line);
            eof_exit_command(shell_d);
        }
    }
    for (int i = 0; line[i]; i++) {
        if (line[i] != ' ' && line[i] != '\0' && line[i] != '\t')
            cmd++;
    }
    if (cmd == 0) {
        free(line);
        return (1);
    }
    return (0);
}

static void handler_ctrlc(int signal)
{
    my_putstr("\n$> ");
}

static void reset(shell_t *shell_d)
{
    static int beggin = 1;

    if (beggin == 0) {
        if (shell_d->command.tab != NULL && shell_d->command.nbr != 0) {
            my_free_strtab(shell_d->command.tab);
            shell_d->command.tab = NULL;
            shell_d->command.nbr = 0;
        }
    }
    beggin = 0;
}

static void prompt(void)
{
    my_putstr("$> ");
}

int catch_input(shell_t *shell_d)
{
    char *line = NULL;
    size_t len = 0;
    int size = 0;

    reset(shell_d);
    shell_d->command.nbr = 0;
    shell_d->command.gtab_size = 0;
    prompt();
    signal(SIGINT, handler_ctrlc);
    size = getline(&line, &len, stdin);
    if (size != -1)
        line[size - 1] = '\0';
    if (check_error_getline(size, line, shell_d) == 1)
        return (0);
    shell_d->command.general_tab = split_major_args(line);
    free(line);
    for (int i = 0; shell_d->command.general_tab[i]; i++)
        (shell_d->command.gtab_size)++;
    return (1);
}