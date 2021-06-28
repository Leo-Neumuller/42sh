/*
** EPITECH PROJECT, 2020
** my int to str
** File description:
** my int to str
*/

#include "my.h"
#include <stdlib.h>

static void put_n_in_str(int n, char **str)
{
    int mod = 0;
    if (n <= 9 && n >= 0) {
        add_char_to_array(n + 48, str);
    }
    if (n < 0) {
        add_char_to_array('-', str);
        n = n * (-1);
        if (n <= 9 && n >= 0)
            put_n_in_str(n, str);
    }
    if (n > 9) {
        mod = n % 10;
        put_n_in_str(n / 10, str);
        add_char_to_array(mod + 48, str);
    }
}

char *int_to_str(int n)
{
    char *str = malloc(1);

    if (str == NULL)
        return NULL;
    str[0] = '\0';
    put_n_in_str(n, &str);
    return str;
}