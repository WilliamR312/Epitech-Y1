/*
** EPITECH PROJECT, 2020
** MY_SHELL
** File description:
** Prototypes useful for my shell
*/

#include "struct.h"

#ifndef MY_SH_H_
#define MY_SH_H_

int shell_loop(int nb_args, char **args, char **env);

char ***split_major_args(char const *str);
char **split_args(char const *str);
void get_path_cmd(shell_t *shell_d);
int is_space(char src);
int is_space_tab(char src);
char **split_args_limits(char const *str, int min, int max);

void get_initial_env(shell_t *shell_d, char **env);
char *get_pathline(char **env, char *path);
int find_path(char **env, char *path);
void initialization(shell_t *shell_d);

int catch_input(shell_t *shell_d);

void exit_command(shell_t *shell_d);
void eof_exit_command(shell_t *shell_d);
int custom_commands(shell_t *shell_d);
void execve_core(shell_t *shell_d);
void execve_command(shell_t *shell_d);
void execve_binary(shell_t *shell_d);
void setenv_command(shell_t *shell_d);
int setenv_cmd_error(shell_t *shell_d);
void unsetenv_command(shell_t *shell_d);
int unsetenv_cmd_error(shell_t *shell_d);
void cd_command(shell_t *shell_d);
void cd_check_error(shell_t *shell_d);
void env_command(shell_t *shell_d);

#endif /* !MY_H_ */