/*
** EPITECH PROJECT, 2020
** my
** File description:
** header of all libs
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

#ifndef MY_H
#define MY_H
typedef struct linked_list
{
    int data;
    struct linked_list *next;
} linked_list_t;
typedef struct listinfo
{
    linked_list_t *list;
    int size;
} list_info;
typedef struct linked_liststr
{
    char *data;
    struct linked_liststr *next;
} linked_list_str;
typedef struct listinfostr
{
    linked_list_str *list;
    int size;
} list_info_str;

int my_compute_factorial_it(int);
int my_compute_factorial_rec(int);
int my_compute_power_it(int, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
char *my_evil_str(char *);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int my_isneg(int);
int my_is_prime(int);
int my_print_alpha(void);
int my_print_comb2(void);
int my_print_comb(void);
int my_print_digits(void);
int my_print_revalpha(void);
int my_putchar(char);
void my_put_nbr(int);
int my_putstr(char const *);
char *my_revstr(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
void my_sort_int_array(int *, int);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *str, char *to_find);
char *my_strupcase(char *);
void my_swap(int *, int *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
void my_put_long(long n);
char *remove_char_in_array(char *str, int i);
char *add_to_array(char *expr, char *nb, int i);
char *add_char_to_array(char expr, char **nb);
char *long_to_hex(long nb);
char *int_to_binary(unsigned int nb);
void print_non_printable(unsigned char *c);
char *uint_to_hex(unsigned int nb);
int my_printf(const char *format, ...);
char *int_to_str(int n);
void sort_d_arr_alpha(char **str, int count);
void rotate_forward(int *list, int size);
int push(linked_list_t **list_from, linked_list_t **list_to, int *size_from,
                                                                int *size_to);
void swap(linked_list_t **list, int size);
void rotate_backward(int *list, int size);
int check_if_sorted(linked_list_t *list, int size);
void sort(list_info *l_a, list_info *l_b);
int rev_check_if_sorted(linked_list_t *list, int size);
int check_if_both_sorted(linked_list_t **l_a, linked_list_t **l_b,
                                    int *size_l_a, int *size_l_b);
void put_str_in_list(linked_list_str **list, char *data);
linked_list_str *rev(linked_list_str *tmp, int size);
void put_str_in_list(linked_list_str **list, char *data);
char *read_file(char *path);
void add_str_to_array(char *str, char **to);
char **add_to_double_array(char *str, char **arr);
int my_ptrarrlen(char **arr);
int my_atoi(char *nb);
char *my_itoa(int nbr);
char **str_to_word_array(char *str, int n, ...);
int check_str_alpha(char *str);
int	match(char *s_one, char *s_two);
char **insert_in_double_arr(int pos, char *str, char **arr);
#endif
