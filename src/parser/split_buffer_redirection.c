/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** split_buffer_redirection
*/
#include "mysh.h"

static void check_if_double(char *str, int *i, char new_arr[3], int *lastpos)
{
    if (my_strlen(str) != *i) {
        if (str[*i + 1] == str[*i]) {
            new_arr[1] = str[*i];
            *lastpos = *lastpos + 1;
            *i = *i + 1;
        }
    }
}

char **split_buffer_redirection(char *str, int *i, char **arr, int *lastpos)
{
    char tmp;
    char new_arr[3];

    new_arr[1] = '\0';
    new_arr[2] = '\0';
    tmp = str[*i];
    str[*i] = '\0';
    if (my_strlen(&str[*lastpos]) > 0)
        arr = check_size_and_add(&str[*lastpos], arr);
    *lastpos = *i + 1;
    str[*i] = tmp;
    new_arr[0] = tmp;
    check_if_double(str, i, new_arr, lastpos);
    arr = check_size_and_add(new_arr, arr);
    return arr;
}