/*
** EPITECH PROJECT, 2020
** sheel_loop
** File description:
** shell loop
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "mysh.h"
#include "struct.h"

static void check_error_status(int status)
{
    if (WIFSIGNALED(status)) {
        if (WIFSIGNALED(status))
            my_putestr(strsignal(status - 128));
        else if (WTERMSIG(status) == 8)
            my_putestr("Floating exception");
        if (WCOREDUMP(status))
            my_putestr(" (core dumped)");
        my_putestr("\n");
    }
}

static int simple_command(shell_t *shell_d)
{
    int status = 0;
    pid_t pid = 0;

    if (custom_commands(shell_d) != 1) {
        pid = fork();
        waitpid(pid, &status, 0);
        if (pid == 0) {
            get_path_cmd(shell_d);
            execve_core(shell_d);
            exit (0);
        } else {
            check_error_status(status);
        }
    }
    return (0);
}

static void count_commands(cmd_t *shell_cmd)
{
    for (int j = 0; shell_cmd->tab[j]; shell_cmd->nbr++, j++);
}

static void commands_manager(shell_t *shell_d)
{
    for (int i = 0; i < shell_d->command.gtab_size; i++) {
        if (shell_d->command.general_tab[i][0] != NULL) {
            shell_d->command.nbr = 0;
            shell_d->command.tab = shell_d->command.general_tab[i];
            count_commands(&shell_d->command);
            simple_command(shell_d);
        }
    }
}

int shell_loop(int nb_args, char **args, char **env)
{
    shell_t shell_d;

    initialization(&shell_d);
    get_initial_env(&shell_d, env);
    while (1) {
        while (catch_input(&shell_d) == 0);
        commands_manager(&shell_d);
    }
    return (0);
}