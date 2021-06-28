/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** run_bin
*/
#include "mysh.h"

char *return_path(char **env)
{
    int i = 0;
    char *equalptr = NULL;

    for (i = 0; env[i] != 0; i++) {
        equalptr = my_strstr(env[i], "=");
        equalptr[0] = '\0';
        if (my_strcmp("PATH", env[i]) == 0) {
            equalptr[0] = '=';
            break;
        }
        equalptr[0] = '=';
        equalptr = NULL;
    }
    if (equalptr != NULL)
        return &equalptr[1];
    return NULL;
}

static void check_if_is_executable(char *fullpath)
{
    if (access(fullpath, X_OK) || opendir(fullpath)) {
        write(2, fullpath, my_strlen(fullpath));
        write(2, ": Permission denied.\n", 21);
        free(fullpath);
        exit(1);
    }
}

static int check_and_run(char *tmpfullpath, app_t *app)
{
    struct stat buff;
    char *tmppath;
    char *fullpath = NULL;
    add_str_to_array(tmpfullpath, &fullpath);
    if (fullpath[0] == '~') {
        tmppath = NULL;
        add_str_to_array(return_home(app->env), &tmppath);
        add_str_to_array(&fullpath[1], &tmppath);
        free(fullpath);
        fullpath = tmppath;
    }
    if (stat(fullpath, &buff) != -1) {
        check_if_is_executable(fullpath);
        check_if_or(app);
        execve(fullpath, &app->splited_arg[0], app->env);
        handle_enoexec(app);
        return 1;
    }
    free(fullpath);
    return 0;
}

static char *use_saved_path_if_null(app_t *app)
{
    char *path = return_path(app->env);

    if (path == NULL)
        path = app->saved_path;
    return path;
}

void check_if_bin_exist(app_t *app)
{
    char *path = use_saved_path_if_null(app);
    int lastpos = 0;
    char *fullpath;

    if (my_strstr(app->splited_arg[0], "/") != 0 &&
    check_and_run(app->splited_arg[0], app) == 1)
        return;
    else if (my_strstr(app->splited_arg[0], "/") != 0 || path == NULL) {
        error_not_found(app);
        return;
    }
    for (int i = 0; path[i] != '\0'; i++) {
        if ((fullpath = split_path(path, i, &lastpos, app->splited_arg)) != 0 &&
        check_and_run(fullpath, app) == 1) {
            return;
        }
    }
    error_not_found(app);
}