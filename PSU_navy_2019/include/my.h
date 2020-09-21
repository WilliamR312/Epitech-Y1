/*
** EPITECH PROJECT, 2019
** my lib
** File description:
** make a lib
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void my_putchar(char c);
void my_put_nbr(int nb);
void my_put_u_nbr(unsigned int nb);
void my_putstr(char const *str);
void my_putstr_all(char *str);
void base_binaire(unsigned int value);
void base_octal(unsigned int value);
void base_eighteen(unsigned int value);
void base_eighteen_up(unsigned int value);
char *my_revstr(char *str);
int my_strlen(char const *str);
void disp_stdarg(char s, va_list ap);
void my_printf(const char *format, ...);
int base_system(unsigned int nb, char *base);
int select_number(char const *str, int sign, int i, int result);
int my_getnbr(char const *str);
int fs_get_number_from_first_line(char const *filepath);
int fs_get_lng_seconde_line(char const *filepath);
char **array_dup_2d_array(char **arr, int nb_rows, int nb_cols);
char **found_the_square(char **buf, int rows, int cols);
int detector_first_line(char *buffer, int i);
int my_atoi(char *str);
int my_strcmp(char *str, char *other_str);
int verif_if_nbr(char *arg);
char *my_get_env(char **envp, char *str_finding);
char **my_str_to_word_array(char *str, char separate);
char *my_strcat_separate(char *dest, char const *src, char separate);
char *my_strcat(char *dest, char const *src);
char **my_realloc_double(char **before, int difference);
char **my_strcpy_double(char **str);
char *clean_str(char *str);
void my_putstr_error(char const *str);
void my_put_array(char **array);

#endif /* !MY_H_ */