/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** handle_quote
*/

#include "mysh.h"

static char **handle_void_arg(char *str, int i, char **arr, int *lastpos)
{
    char *voidstr;

    if (i - *lastpos <= 1) {
        voidstr = malloc(1);
        if (voidstr == NULL)
            return NULL;
        voidstr[0] = '\0';
        *lastpos = i + 1;
        return add_to_double_array(voidstr, arr);
    } else {
        return handle_cut_arg(str, i, arr, lastpos);
    }
}

char **handle_quote(char *str, int i, char **arr, int *lastpos)
{
    static int last_was_quote = 0;
    static int last_was_double_quote = 0;

    if (str[i] == '"' && last_was_double_quote == 1) {
        last_was_double_quote = 0;
        return handle_void_arg(str, i, arr, lastpos);
    } else if (str[i] == '"') {
        last_was_double_quote = 1;
        *lastpos = i + 1;
    }
    if (str[i] == '\'' && last_was_quote == 1) {
        last_was_quote = 0;
        return handle_void_arg(str, i, arr, lastpos);
    } else if (str[i] == '\'') {
        last_was_quote = 1;
        *lastpos = i + 1;
    }
    return arr;
}