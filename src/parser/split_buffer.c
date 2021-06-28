/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** split_buffer
*/
#include "mysh.h"

char **check_size_and_add(char *str, char **arr)
{
    if (my_strlen(str) > 0)
        arr = add_to_double_array(str, arr);
    return arr;
}

static char **handle_newline(char *str, int i, char **arr, int *lastpos)
{
    str[i] = '\0';
    arr = check_size_and_add(&str[*lastpos], arr);
    return arr;
}

char **handle_cut_arg(char *str, int i, char **arr, int *lastpos)
{
    str[i] = '\0';
    if (my_strlen(&str[*lastpos]) > 0)
        arr = check_size_and_add(&str[*lastpos], arr);
    *lastpos = i + 1;
    str[i] = ' ';
    return arr;
}

char **handle_split(char *str, int i, char **arr, int *lastpos)
{
    char tmp;
    char new_arr[2];

    new_arr[1] = '\0';
    tmp = str[i];
    str[i] = '\0';
    if (my_strlen(&str[*lastpos]) > 0)
        arr = check_size_and_add(&str[*lastpos], arr);
    *lastpos = i + 1;
    str[i] = tmp;
    new_arr[0] = tmp;
    arr = check_size_and_add(new_arr, arr);
    return arr;
}

char **split_buffer(app_t *app, char **arr)
{
    int lastpos = 0;

    for (int i = 0; app->buffer[i] != '\0'; i++) {
        if (app->buffer[i] == '\n')
            return handle_newline(app->buffer, i, arr, &lastpos);
        if (app->buffer[i] == ' ' || app->buffer[i] == '\t')
            arr = handle_cut_arg(app->buffer, i, arr, &lastpos);
        if (app->buffer[i] == '"' || app->buffer[i] == '\'')
            arr = handle_quote(app->buffer, i, arr, &lastpos);
        if (app->buffer[i] == '>' || app->buffer[i] == '<')
            arr = split_buffer_redirection(app->buffer, &i, arr, &lastpos);
        if (app->buffer[i] == '|' || app->buffer[i] == ';')
            arr = handle_split(app->buffer, i, arr, &lastpos);
    }
    if (app->buffer[my_strlen(app->buffer) - 1] != '\n')
        arr = check_size_and_add(&app->buffer[lastpos], arr);
    return arr;
}