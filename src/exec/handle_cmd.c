/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** handle_cmd
*/
#include "mysh.h"
#include <errno.h>

void print_exeption(int status, app_t *app)
{
    if (WIFSIGNALED(status)) {
        if (status == 13) {
            app->return_value = 141;
            return;
        }
        if (WTERMSIG(status) == 8)
            pferror("Floating exception");
        else
            pferror(strsignal(WTERMSIG(status)));
        if (__WCOREDUMP(status) != 0) {
            pferror(" (core dumped)");
        }
        pferror("\n");
        app->return_value = status;
    }
}

void execute_right_cmd(app_t *app)
{
    char **tmpenv;
    pid_t pid = -1;

    if ((tmpenv = check_if_builtins(app)) != NULL) {
        app->env = tmpenv;
        return;
    } else if (my_strcmp(app->splited_arg[0], "exit") != 0) {
        if (app->is_singlecmd)
            pid = fork();
        if (pid == 0 || app->is_singlecmd == 0) {
            check_if_bin_exist(app);
            exit(app->return_value);
        }
    }
}