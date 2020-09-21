/*
** EPITECH PROJECT, 2020
** MY_STRUCT
** File description:
** My struct with some useful variables
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct commands
{
    char ***general_tab;
    int gtab_size;
    int nbr;
    char **tab;
}cmd_t;

typedef struct environement
{
    int nbr;
    char **tab;
}env_t;

typedef struct path_cmd
{
    int nbr;
    char **tab;
}pcmd_t;

typedef struct args_execution
{
    int nbr;
    char **args;
    char *path;
}pexec_t;

typedef struct builtins
{
    char *old_pwd;
}builtins_t;

typedef struct data_shell
{
    builtins_t builtins;
    cmd_t command;
    env_t env;
    pcmd_t path_cmd;
    pexec_t args_exec;

}shell_t;

#endif /* !MY_H_ */