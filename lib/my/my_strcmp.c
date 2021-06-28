/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare two strings
*/
#include "my.h"

static int find_ascii_dif(char const *s1, char const *s2, int o)
{
    if (s1[o] < s2[o]) {
        return -1;
    } else if (s1[o] > s2[o]) {
        return 1;
    }
}

static int check_string_length(int i, int a)
{
    if (i > a) {
        return 1;
    } else if (a > i) {
        return -1;
    } else {
        return 0;
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = my_strlen(s1);
    int a = my_strlen(s2);
    int o = 0;

    while (s1[o] != '\0' && s2[o] != '\0') {
        if (s1[o] != s2[o]) {
            return find_ascii_dif(s1, s2, o);
        }
        o++;
    }
    return check_string_length(i, a);
}
