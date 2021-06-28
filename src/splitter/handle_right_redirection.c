/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** handle_right_redirection
*/
#include "mysh.h"

static void open_file_and_redir(app_t *app, char ***arr, int file)
{
    int savestdin = dup(1);

    dup2(file, 1);
    if (last_is_singlecmd(app, arr)) {
        close(file);
        dup2(savestdin, 1);
        close(savestdin);
        app->current_arg = app->current_arg + 1;
        return;
    }
    exec_pipes(app, arr);
    close(file);
    dup2(savestdin, 1);
    close(savestdin);
    corpse_collector(app);
    app->current_arg = app->current_arg + 1;
}

static void handle_simple_or_double(app_t *app, char ***arr, int is_double)
{
    int file;

    if (is_double) {
        file = open(app->arg[app->current_arg + 1], O_WRONLY | O_APPEND |
        O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    } else {
        file = open(app->arg[app->current_arg + 1], O_WRONLY | O_TRUNC |
        O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    }
    open_file_and_redir(app, arr, file);
}

int handle_simple_r_r(app_t *app, char ***arr, int is_double)
{
    int ret;

    if (add_to_current_arg_redirect(app, arr)) {
        app->last_split = REDIRECTION;
        return 1;
    }
    ret = check_for_redir(app);
    if (ret == 2)
        return 0;
    else if (ret == 1)
        return 1;
    handle_simple_or_double(app, arr, is_double);
    app->is_singlecmd = 0;
    app->last_split = REDIRECTION;
    app->current_in_arr = 0;
    app->delimiter = app->current_arg + 1;
    return 0;
}