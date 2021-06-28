/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** my strstr
*/

#include "my.h"

static void check_if_str_in_str(char *str, char *to_find, int i, int *c)
{
    if (str[i] == to_find[*c]) {
        *c = *c + 1;
    } else if (str[i] == to_find[0]) {
        *c = 1;
    } else {
        *c = 0;
    }
}

char *my_strstr(char *str, char *to_find)
{
    int size = my_strlen(str);
    int c = 0;

    for (int i = 0; i < size; i++) {
        check_if_str_in_str(str, to_find, i, &c);
        if (c == my_strlen(to_find)) {
            return &str[i - c + 1];
        }
    }
    return 0;
}