/*
** EPITECH PROJECT, 2020
** my_sort_double_alpha
** File description:
** sort a double array alphabeticaly
*/

#include "my.h"
#include <stdlib.h>

static void check_sort(char **str, int i, int a)
{
    char *tmp;

    if (my_strcmp(my_strlowcase(str[i]), my_strlowcase(str[a])) == -1 ||
    my_strcmp(my_strlowcase(str[i]), my_strlowcase(str[a])) == 0) {
        tmp = str[i];
        str[i] = str[a];
        str[a] = tmp;
    }
}

void sort_d_arr_alpha(char **str, int count)
{
    for (int i = 0; i < count; i++) {
        for (int a = 0; a < count; a++) {
            check_sort(str, i, a);
        }
    }
}