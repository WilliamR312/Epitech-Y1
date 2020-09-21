/*
** EPITECH PROJECT, 2019
** MY_HEADER
** File description:
** ITS MYYY HEADEEEEEER
*/

#ifndef MY_H_
#define MY_H_

int my_isnumber(char c);

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_prime_prime_sup(int nb);

int is_a_nb_character(char c);

int is_a_nb_character(char c);

int is_negative(char const *str, int mk1);

int power(int a, int pow);

int return_nbr(char const *str, int mk1, int mk2);

int my_getnbr(char const *str);

int my_is_prime(int nb);

int my_isneg(int n);

int my_put_nbr(int nb);

void my_putchar(char c);

int my_putstr(char const *str);

void my_swap_chars(char *src1, char *src2);

char *my_revstr(char *str);

int my_showmem(char const *str, int size);

int my_showstr(char const *str);

void my_sort_int_array(int *src, int size);

char *my_strdup(char const *src);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *src);

char *my_strlowcase(char *str);

char * my_strncat(char *dest, char const *src, int n);

int my_strncmp(char const *s1, char const *s2);

char *my_strncpy(char *dest, char const *src, int n);

int check_rest(char *str, char *to_find, int i);

char *my_strstr(char *str, char *to_find);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

#endif /* !MY_H_ */