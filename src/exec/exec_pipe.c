/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** exec_pipe
*/
#include "mysh.h"

static void handle_last_pipe(int last_input)
{
    if (last_input != -1) {
        dup2(last_input, 0);
        close(last_input);
    }
}

static void open_pipes(int pipes[2])
{
    close(pipes[0]);
    dup2(pipes[1], 1);
    close(pipes[1]);
}

static void exec_last_pipe(int last_input, int i,
char ***arr, app_t *app)
{
    handle_last_pipe(last_input);
    app->splited_arg = arr[i];
    execute_right_cmd(app);
    if (app->pipes[1] != -1)
        close(app->pipes[1]);
    if (last_input != -1)
        close(last_input);
    corpse_collector(app);
}

static void loop_pipe_exec(app_t *app, int *last_input, int i,
char ***arr)
{
    pid_t pid;

    if (pipe(app->pipes) < 0) {
        app->return_value = 1;
        return;
    }
    pid = fork();
    if (pid == 0) {
        handle_last_pipe(*last_input);
        open_pipes(app->pipes);
        app->splited_arg = arr[i];
        execute_right_cmd(app);
        exit(0);
    } else {
        close(app->pipes[1]);
        if (*last_input != -1)
            close(*last_input);
        *last_input = app->pipes[0];
    }
}

void exec_pipes(app_t *app, char ***arr)
{
    int last_input = -1;
    int i = 0;
    int stdin_backup = dup(0);

    if (check_if_or_and_pipe(app) == 1)
        return;
    app->pipes[0] = -1;
    app->pipes[1] = -1;
    for (i = 0; i < app->current_in_arr - 1; i++) {
        loop_pipe_exec(app, &last_input, i, arr);
    }
    app->is_singlecmd = 1;
    exec_last_pipe(last_input, i, arr, app);
    app->is_singlecmd = 0;
    dup2(stdin_backup, 0);
    close(stdin_backup);
    corpse_collector(app);
}