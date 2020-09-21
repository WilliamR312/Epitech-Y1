/*
** EPITECH PROJECT, 2020
** generator
** File description:
** main for generator
*/
#include "include/my_gen.h"
#include "include/struct.h"

static int check_error(int nb_args, char **args)
{
    if (nb_args < 3 || nb_args > 4)
        return (84);
    if (str_is_num(args[1]) == 0 || str_is_num(args[2]) == 0)
        return (84);
    if (nb_args == 4 && \
    (str_is_num(args[3]) == 0 || strcmp(args[3], "perfect") != 0))
        return (84);
    return (0);
}

static int setup_args(int nb_args, char **args, generator_t *generator)
{
    generator->info_maze.x = atoi(args[1]);
    generator->info_maze.y = atoi(args[2]);
    if (generator->info_maze.y == 0 || generator->info_maze.x == 0)
        return (84);
    if (nb_args == 4)
        generator->perfect = 1;
    else
        generator->perfect = 0;
    return (0);
}

static void free_res(generator_t *generator)
{
    for (int i = 0; i < generator->info_maze.y; i++)
        free(generator->maze[i]);
    free(generator->maze);
}

int main(int nb_args, char **args)
{
    generator_t generator;

    if (check_error(nb_args, args) == 84)
        return (84);
    srand(time(0));
    if (setup_args(nb_args, args, &generator) == 84)
        return (84);
    generate_empty_maze(&generator);
    kruskal_algorithm(&generator);
    if (generator.perfect == 0)
        manage_imperfect(&generator);
    display_char_maze(&generator);
    free_res(&generator);
    return (1);
}