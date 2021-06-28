/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** handle_redirection
*/
#include "mysh.h"

int check_if_is_dir(app_t *app)
{
    struct stat buff;
    char *fulpath = NULL;
    char buffer[BUFSIZ];

    add_str_to_array(getcwd(buffer, BUFSIZ), &fulpath);
    add_char_to_array('/', &fulpath);
    add_str_to_array(app->arg[app->current_arg + 1], &fulpath);
    if (stat(fulpath, &buff) != -1) {
        if (!S_ISREG(buff.st_mode)) {
            pferror(app->arg[app->current_arg + 1]);
            pferror(": Is a directory.\n");
            app->delimiter = app->current_arg + 2;
            app->current_arg = app->current_arg + 1;
            app->return_value = 1;
            app->current_in_arr = 0;
            free(fulpath);
            return 2;
        }
    }
    free(fulpath);
    return 0;
}

int check_for_redir(app_t *app)
{
    int ret;

    if (app->current_arg + 1 >= app->count_arg) {
        pferror("Missing name for redirect.\n");
        app->return_value = 1;
        return 1;
    }
    if (app->arg[app->current_arg + 1] == NULL)
        return 1;
    ret = check_if_is_dir(app);
    if (ret != 0)
        return ret;
    return 0;
}

static int check_if_next_is_redir(app_t *app, int which_next)
{
    if (app->current_arg + which_next >= app->count_arg)
        return 0;
    if (my_strcmp(app->arg[app->current_arg + which_next], ">") == 0)
        return 1;
    if (my_strcmp(app->arg[app->current_arg + which_next], ">>") == 0)
        return 1;
    if (my_strcmp(app->arg[app->current_arg + which_next], "<") == 0)
        return 1;
    if (my_strcmp(app->arg[app->current_arg + which_next], "<<") == 0)
        return 1;
    return 0;
}

int add_to_current_arg_redirect(app_t *app, char ***arr)
{
    app->splited_arg = NULL;
    arr[app->current_in_arr] = NULL;
    if (check_if_next_is_redir(app, 2)) {
        pferror("Ambiguous output redirect.\n");
        app->return_value = 1;
        return 1;
    }
    if (check_if_next_is_redir(app, 1)) {
        pferror("Missing name for redirect.\n");
        app->return_value = 1;
        return 1;
    }
    for (int i = app->delimiter; i < app->current_arg; i++) {
        arr[app->current_in_arr] = add_to_double_array(app->arg[i],
        arr[app->current_in_arr]);
    }
    app->current_in_arr = app->current_in_arr + 1;
    return 0;
}

int handle_redirection(app_t *app, char ***arr)
{
    if (my_strcmp(app->arg[app->current_arg], ">") == 0) {
        if (handle_simple_r_r(app, arr, 0))
            return 1;
    }
    if (my_strcmp(app->arg[app->current_arg], ">>") == 0) {
        if (handle_simple_r_r(app, arr, 1))
            return 1;
    }
    if (my_strcmp(app->arg[app->current_arg], "<") == 0) {
        if (handle_simple_l_r(app, arr, 0))
            return 1;
    }
    if (my_strcmp(app->arg[app->current_arg], "<<") == 0) {
        if (handle_simple_l_r(app, arr, 1))
            return 1;
    }
    return 0;
}