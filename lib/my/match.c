/*
** EPITECH PROJECT, 2021
** match
** File description:
** main
*/
#include "my.h"

static void inc_both(int *i, int *a)
{
    *i += 1;
    *a += 1;
}

static int star_conditional(char *s_one, char *s_two, int *i, int *a)
{
    if (s_two[*a] == '\0' && s_one[*i + 1] != '\0') {
        *a -= 1;
        *i += 1;
        return 1;
    }
    if (s_two[*a] == '\0' && s_one[*i] == '*') {
        *i += 1;
        return 1;
    }
    if (s_one[*i] == '*' && s_two[*a] != '\0') {
        *a += 1;
        return 1;
    }
    return 0;
}

static int conditional_matches(char *s_one, char *s_two, int *i, int *a)
{
    if (star_conditional(s_one, s_two, i, a) != 0) {
        return 0;
    }
    if (s_one[*i] == s_two[*a] && s_one[*i] != '\0' && s_two[*a] != '\0') {
        inc_both(i, a);
        return 0;
    }
    if (s_one[*i] != s_two[*a] && s_one[*i] != '\0' && s_two[*a] != '\0'
    && s_one[*i - 1] == '*') {
        *a -= 1;
        return 0;
    }
    if (s_one[*i] != s_two[*a] && s_one[*i] == '\0') {
        return 1;
    }
}

int	match(char *s_one, char *s_two)
{
    int i = 0;
    int a = 0;
    while (s_one[i] != '\0' || s_two[a] != '\0') {
        if (a == -1)
            return 0;
        if (conditional_matches(s_one, s_two, &i, &a))
            return 0;
    }
    return 1;
}