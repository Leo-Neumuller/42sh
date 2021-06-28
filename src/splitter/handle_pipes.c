/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** handle_pipes
*/
#include "mysh.h"

int add_to_current_arg_pipes(app_t *app, char ***arr)
{
    app->splited_arg = NULL;

    arr[app->current_in_arr] = NULL;
    if (app->current_arg - app->delimiter == 0) {
        pferror("Invalid null command.\n");
        app->return_value = 1;
        return 1;
    }
    for (int i = app->delimiter; i < app->current_arg; i++) {
        arr[app->current_in_arr] = add_to_double_array(app->arg[i],
        arr[app->current_in_arr]);
    }
    app->current_in_arr = app->current_in_arr + 1;
    return 0;
}

int split_pipes(app_t *app, char ***arr)
{
    if (my_strcmp(app->arg[app->current_arg], "|") == 0) {
        app->last_split = PIPE;
        if (add_to_current_arg_pipes(app, arr))
            return 1;
        app->delimiter = app->current_arg + 1;
        return 0;
    }
    return 0;
}