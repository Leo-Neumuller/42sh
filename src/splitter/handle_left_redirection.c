/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** handle_left_redirection
*/
#include "mysh.h"

static void open_file_and_redir(app_t *app, char ***arr, int file)
{
    int savestdout = dup(0);

    dup2(file, 0);
    if (last_is_singlecmd(app, arr)) {
        close(file);
        dup2(savestdout, 0);
        close(savestdout);
        app->current_arg = app->current_arg + 1;
        return;
    }
    exec_pipes(app, arr);
    close(file);
    dup2(savestdout, 0);
    close(savestdout);
    corpse_collector(app);
    app->current_arg = app->current_arg + 1;
}

static void handle_simple_or_double(app_t *app, char ***arr, int is_double)
{
    int file;

    if (is_double) {
        handle_double_l_r(app, arr, app->arg[app->current_arg + 1]);
    } else {
        file = open(app->arg[app->current_arg + 1], O_RDONLY);
        open_file_and_redir(app, arr, file);
    }
}

static int handle_error(app_t *app, int is_double)
{
    int ret;

    if (is_double == 0 && stat(app->arg[app->current_arg + 1],
    &(struct stat) {0}) == -1) {
        pferror(app->arg[app->current_arg + 1]);
        pferror(": No such file or directory.\n");
        app->return_value = 1;
        return 1;
    }
    ret = check_for_redir(app);
    if (ret == 2)
        return 0;
    else if (ret == 1)
        return 1;
    return 0;
}

int handle_simple_l_r(app_t *app, char ***arr, int is_double)
{
    int ret;

    if (add_to_current_arg_redirect(app, arr)) {
        app->last_split = REDIRECTION;
        return 1;
    }
    ret = handle_error(app, is_double);
    if (ret != 0)
        return ret;
    handle_simple_or_double(app, arr, is_double);
    app->is_singlecmd = 0;
    app->last_split = REDIRECTION;
    app->current_in_arr = 0;
    app->delimiter = app->current_arg + 1;
    return 0;
}