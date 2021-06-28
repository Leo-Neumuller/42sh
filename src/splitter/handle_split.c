/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** handle_split
*/
#include "mysh.h"

int add_to_current_arg(app_t *app, char ***arr)
{
    app->splited_arg = NULL;

    arr[app->current_in_arr] = NULL;
    if (app->current_arg - app->delimiter == 0)
        return 1;
    for (int i = app->delimiter; i < app->current_arg; i++) {
        arr[app->current_in_arr] = add_to_double_array(app->arg[i],
        arr[app->current_in_arr]);
    }
    app->current_in_arr = app->current_in_arr + 1;
    return 0;
}

int last_is_singlecmd(app_t *app, char ***arr)
{
    if (my_ptrarrlen(arr[app->current_in_arr - 1]) == 1 &&
    (app->last_split == NONE || app->last_split == SEMICOLON)) {
        app->is_singlecmd = 1;
        app->splited_arg = arr[app->current_in_arr - 1];
        execute_right_cmd(app);
        corpse_collector_all_return_value(app);
        app->is_singlecmd = 0;
        return 1;
    }
    return 0;
}

void last_split(app_t *app, char ***arr)
{
    if (app->last_split == PIPE)
        if (add_to_current_arg_pipes(app, arr))
            return;
    if (add_to_current_arg(app, arr))
        return;
    if (last_is_singlecmd(app, arr))
        return;
    exec_pipes(app, arr);
    corpse_collector(app);
}

static int handle_priority(app_t *app, char ***arr)
{
    if (handle_semicolons(app, arr))
        return 1;
    if (handle_redirection(app, arr))
        return 1;
    if (split_pipes(app, arr))
        return 1;
    if (handle_and(app, arr))
        return 1;
    if (handle_or(app, arr))
        return 1;
    return 0;
}

void split_exec(app_t *app, char ***arr)
{
    for (app->current_arg = 0; app->current_arg < app->count_arg;
    app->current_arg += 1) {
        init_globbing(app->arg[app->current_arg], app);
        if (app->arg[app->current_arg] == NULL)
            return;
        if (handle_priority(app, arr))
            return;
    }
    last_split(app, arr);
}
