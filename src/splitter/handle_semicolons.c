/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** handle_semicolons
*/
#include "mysh.h"

int add_to_current_arg_semicolon(app_t *app, char ***arr)
{
    app->splited_arg = NULL;

    arr[app->current_in_arr] = NULL;
    if (app->current_arg - app->delimiter == 0) {
        app->delimiter = app->delimiter + 1;
        if (app->current_arg + 1 != app->count_arg) {
            app->current_arg = app->current_arg + 1;
        }
        return 1;
    }
    for (int i = app->delimiter; i < app->current_arg; i++) {
        arr[app->current_in_arr] = add_to_double_array(app->arg[i],
        arr[app->current_in_arr]);
    }
    app->current_in_arr = app->current_in_arr + 1;
    return 0;
}

int handle_last_was_pipe(app_t *app, char ***arr)
{
    if (app->last_split == PIPE) {
        add_to_current_arg_pipes(app, arr);
        app->last_split = SEMICOLON;
        exec_pipes(app, arr);
        corpse_collector(app);
        return 1;
    }
    return 0;
}

static int check_last_split_exec(app_t *app)
{
    if (app->last_split == NONE || app->last_split == SEMICOLON ||
    app->last_split == AND)
        return 1;
    if (app->last_split == OR)
        return 1;
    return 0;
}

int handle_semicolons(app_t *app, char ***arr)
{
    if (my_strcmp(app->arg[app->current_arg], ";") == 0) {
        if (add_to_current_arg_semicolon(app, arr)) {
            app->last_split = SEMICOLON;
            return 0;
        }
        if (check_last_split_exec(app)) {
            app->is_singlecmd = 1;
            app->splited_arg = arr[app->current_in_arr - 1];
            execute_right_cmd(app);
            corpse_collector_all_return_value(app);
        }
        handle_last_was_pipe(app, arr);
        app->is_singlecmd = 0;
        app->last_split = SEMICOLON;
        app->current_in_arr = 0;
        app->delimiter = app->current_arg + 1;
        return 0;
    }
    return 0;
}