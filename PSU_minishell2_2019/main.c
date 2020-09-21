/*
** EPITECH PROJECT, 2020
** MAIN
** File description:
** main for minishell1
*/

#include "my.h"
#include "mysh.h"
#include "struct.h"

int main(int nb_args, char **args, char **env)
{
    shell_loop(nb_args, args, env);
    return (0);
}