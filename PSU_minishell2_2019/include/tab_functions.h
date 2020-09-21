/*
** EPITECH PROJECT, 2020
** TAB_FUNCTION
** File description:
** my tab with structs
*/

#include "stddef.h"
#include "mysh.h"
#include "struct.h"

#ifndef TAB_FUNCTION_H_
#define TAB_FUNCTION_H_

typedef struct struct_commands
{
    char *cmd;
    void (*f)(shell_t *);
}command_t;

command_t tab_commands[] = {
    {"env", &env_command},
    {"cd", &cd_command},
    {"setenv", &setenv_command},
    {"unsetenv", &unsetenv_command},
    {"exit", &exit_command},
    {NULL, NULL}
};

#endif /* !MY_H_ */