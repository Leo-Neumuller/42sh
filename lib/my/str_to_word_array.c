/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** str_to_word_array
*/

#include "my.h"
#include <stdarg.h>

static char **check_if_null(char *str, char **new_array)
{
    if (str == NULL)
        return new_array;
    if (str[0] == '\0')
        return new_array;
    new_array = add_to_double_array(str, new_array);
    return new_array;
}

static char **split(char *str, char *split_list)
{
    char **new_array = NULL;
    int last_pos = 0;
    char tmp;
    char tmpsearch[2];
    tmpsearch[1] = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
        tmpsearch[0] = str[i];
        if (my_strstr(split_list, tmpsearch) != NULL) {
            tmp = str[i];
            str[i] = '\0';
            new_array = check_if_null(&str[last_pos], new_array);
            str[i] = tmp;
            last_pos = i + 1;
        }
    }
    tmpsearch[0] = str[my_strlen(str) - 1];
    if (my_strstr(split_list, tmpsearch) == NULL)
        new_array = check_if_null(&str[last_pos], new_array);
    return new_array;
}

char **str_to_word_array(char *str, int n, ...)
{
    va_list aq;
    char *split_list = NULL;

    va_start(aq, n);
    for (int i = 0; i < n; i++) {
        add_char_to_array((char)va_arg(aq, int), &split_list);
    }
    va_end(aq);
    return split(str, split_list);
}