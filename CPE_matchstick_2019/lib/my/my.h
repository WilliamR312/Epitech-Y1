/*
** EPITECH PROJECT, 2020
** MY_LIB
** File description:
** My lib / last update : 25/01/20
*/

#ifndef MY_H_
#define MY_H_

// IS //

int my_isnumber(char c);

int my_is_prime(int nb);

int my_isneg(int n);

int is_prime_number(int nb);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int is_alpha_num(char src);


// INT //

int my_put_nbr(int nb);

int my_intlen(int nb);

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_prime_prime_sup(int nb);

int my_recpower(int nb, int p);

int iterative_factorial(int nb);

void my_sort_int_array(int *src, int size);

void my_intswap(int *a, int *b);


// STR //

void my_putchar(char c);

int my_putstr(char const *str);

int my_getnbr(char const *str);

int my_getnbr2(char const *str);

char *my_atoi(int nb);

int my_strlen(char const *src);

void my_swap_chars(char *src1, char *src2);

char *my_revstr(char *str);

char *my_strdup(char const *src);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int n);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strcapitalize(char *str);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strstr2(char *str, char const *to_find);

char *concat_parameters(int nb, char **args);

char **my_split_str(char const *str);

int my_show_str_array(char *const *array);


#endif /* !MY_H_ */