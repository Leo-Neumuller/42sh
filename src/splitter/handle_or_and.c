/*
** EPITECH PROJECT, 2021
** handle_or_and
** File description:
** handle or and
*/

#include "mysh.h"

int find_and_pipe(app_t *app)
{
    int now = app->current_arg - 2;

    for (; now > 0; now--) {
        if (check_mult_env(app, now) == 1 &&
        my_strcmp(app->arg[now], "|") != 0)
            return (now);
    }
    return (now);
}

int check_if_or_and_pipe(app_t *app)
{
    int tot = 0;

    for (int i = 0; app->arg[i] != NULL; i++) {
        if (check_mult_env(app, i))
            tot++;
    }
    if (tot == 0)
        return (0);
    if ((app->current_arg - 2 >= 0 && app->current_arg - 2 < app->count_arg) &&
    my_strcmp(app->arg[find_and_pipe(app)], "&&") == 0 &&
    app->return_value != 0)
        return (1);
    if ((app->current_arg - 2 >= 0 && app->current_arg - 2 < app->count_arg) &&
    my_strcmp(app->arg[find_and_pipe(app)], "||") == 0 &&
    app->return_value == 0)
        return (1);
    return (0);
}

void check_if_or(app_t *app)
{
    int tot = 0;

    for (int i = 0; app->arg[i] != NULL; i++) {
        if (check_mult_env(app, i))
            tot++;
    }
    if (tot == 0)
        return;
    if (app->current_arg - 2 >= 0 && app->return_value == 0 &&
    my_strcmp(app->arg[find_or(app)], "||") == 0)
        exit(0);
    if ((app->current_arg - 2 >= 0 && app->current_arg - 2 < app->count_arg) &&
    my_strcmp(app->arg[find_and(app)], "&&") == 0 && app->return_value != 0)
        exit(1);
    if ((app->current_arg - 2 >= 0 && app->current_arg - 2 < app->count_arg) &&
    my_strcmp(app->arg[find_and(app)], "||") == 0 && app->return_value == 0) {
        exit(0);
    }
}

int handle_or(app_t *app, char ***arr)
{
    if (my_strcmp(app->arg[app->current_arg], "||") == 0) {
        app->last_split = OR;
        if (check_null(app))
            return 1;
        if (add_to_current_arg_semicolon(app, arr))
            return 0;
        if (app->last_split == NONE || app->last_split == OR) {
            app->is_singlecmd = 1;
            app->splited_arg = arr[app->current_in_arr - 1];
            execute_right_cmd(app);
            corpse_collector_all_return_value(app);
        }
        handle_last_was_pipe(app, arr);
        app->is_singlecmd = 0;
        app->current_in_arr = 0;
        app->last_split = OR;
        app->delimiter = app->current_arg + 1;
        return 0;
    }
    return 0;
}

int handle_and(app_t *app, char ***arr)
{
    if (my_strcmp(app->arg[app->current_arg], "&&") == 0) {
        app->last_split = AND;
        if (check_null(app))
            return 1;
        if (add_to_current_arg_semicolon(app, arr))
            return 0;
        if (app->last_split == NONE || app->last_split == AND) {
            app->is_singlecmd = 1;
            app->splited_arg = arr[app->current_in_arr - 1];
            execute_right_cmd(app);
            corpse_collector_all_return_value(app);
        }
        handle_last_was_pipe(app, arr);
        app->is_singlecmd = 0;
        app->current_in_arr = 0;
        app->last_split = AND;
        app->delimiter = app->current_arg + 1;
        return 0;
    }
    return 0;
}