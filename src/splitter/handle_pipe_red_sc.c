/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** handle_pipe_red_sc
*/
#include "mysh.h"

void corpse_collector_all_return_value(app_t *app)
{
    pid_t corpse;
    int status;

    while ((corpse = waitpid(0, &status, 0)) != -1) {
        app->return_value = WEXITSTATUS(status);
        print_exeption(status, app);
    }
}

void corpse_collector(app_t *app)
{
    pid_t corpse;
    int status;

    while ((corpse = waitpid(0, &status, 0)) != -1) {
        if ((app->return_value == 0 && WEXITSTATUS(status) != 0)
        || WEXITSTATUS(status) != 0) {
            app->return_value = WEXITSTATUS(status);
        }
        print_exeption(status, app);
    }
}

static void middleware(app_t *app)
{
    char ***arr;

    app->current_in_arr = 0;
    arr = malloc(sizeof(char **) * (app->count_arg));
    if (arr == NULL)
        exit(1);
    for (int i = 0; i < app->count_arg; i++) {
        arr[i] = NULL;
    }
    split_exec(app, arr);
    for (int i = 0; i < app->count_arg && arr[i]; i++) {
        free_double_array(arr[i]);
    }
    free(arr);
}

void check_if_pipe(app_t *app)
{
    if (app->arg == NULL)
        return;
    if (app->arg[0] == NULL)
        return;
    if (check_if_single(app))
        return;
    app->is_singlecmd = 0;
    app->last_split = NONE;
    app->current_arg = 0;
    app->count_arg = my_ptrarrlen(app->arg);
    app->delimiter = 0;
    middleware(app);
    corpse_collector(app);
}