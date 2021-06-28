/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse a string
*/
#include "my.h"

static char *reverse_string(char *str, int size)
{
    char str_copy[size];
    int a = 0;

    for (int i = 0; i < size; i++) {
        str_copy[i] = str[i];
    }
    for (int i = size - 1; i >= 0; i--) {
        str[a] = str_copy[i];
        a++;
    }
    str[a] = '\0';
    return str;
}

char *my_revstr(char *str)
{
    int i = 0;
    char replaceChar;

    while (str[i] != '\0') {
        i++;
    }
    return reverse_string(str, i);
}
