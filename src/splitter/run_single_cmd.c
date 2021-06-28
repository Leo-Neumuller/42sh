/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** run_single_cmd
*/
#include "mysh.h"

static int check(app_t *app, int i)
{
    if (my_strstr(app->arg[i], "|") != NULL ||
    my_strstr(app->arg[i], ";") != NULL ||
    my_strstr(app->arg[i], ">"))
        return 1;
    if (my_strstr(app->arg[i], ">>") != NULL ||
    my_strstr(app->arg[i], "<") != NULL ||
    my_strstr(app->arg[i], "<<") || my_strstr(app->arg[i], "&&") ||
    my_strstr(app->arg[i], "||"))
        return 1;
    return 0;
}

static int loop_for_globbing(app_t *app)
{
    for (app->current_arg = 0; app->arg[app->current_arg];
    app->current_arg++) {
        init_globbing(app->arg[app->current_arg], app);
        if (app->arg[app->current_arg] == NULL)
            return 1;
    }
    return 0;
}

int check_if_single(app_t *app)
{
    int count = 0;

    for (int i = 0; app->arg[i]; i++) {
        parse_home_char(&app->arg[i], app);
        handle_dollar(&app->arg[i], app);
        if (check(app, i))
            count++;
    }
    if (count == 0) {
        if (loop_for_globbing(app) == 1)
            return 1;
        app->splited_arg = app->arg;
        app->is_singlecmd = 1;
        execute_right_cmd(app);
        corpse_collector_all_return_value(app);
        return 1;
    }
    return 0;
}