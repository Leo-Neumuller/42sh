/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** check_if_builtins
*/
#include "mysh.h"

int check_mult_env(app_t *app, int i)
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

int find_and(app_t *app)
{
    int now = app->current_arg - 2;

    for (; now > 0; now--) {
        if (check_mult_env(app, now) == 1)
            return (now);
    }
    return (now);
}

int check_if_or_and(app_t *app)
{
    int tot = 0;

    for (int i = 0; app->arg[i] != NULL; i++) {
        if (check_mult_env(app, i))
            tot++;
    }
    if (tot == 0)
        return (0);
    if ((app->current_arg - 2 >= 0 && app->current_arg - 2 < app->count_arg) &&
    my_strcmp(app->arg[find_and(app)], "&&") == 0 && app->return_value != 0)
        return (1);
    if ((app->current_arg - 2 >= 0 && app->current_arg - 2 < app->count_arg) &&
    my_strcmp(app->arg[find_and(app)], "||") == 0 && app->return_value == 0)
        return (1);
    return (0);
}

char **check_if_builtins(app_t *app)
{
    char *builtins[] = { "cd", "env", "setenv", "unsetenv", 0 };
    char **(*p[5]) (char **splited_argv, char **env, app_t *app);

    if (check_if_or_and(app) == 1)
        return app->env;
    p[0] = builtins_cd;
    p[1] = builtins_env;
    p[2] = setenv_builtins;
    p[3] = builtins_unsetenv;
    for (int i = 0; builtins[i] != 0; i++) {
        if (my_strcmp(builtins[i], app->splited_arg[0]) == 0) {
            app->env = (*p[i]) (app->splited_arg, app->env, app);
            return app->env;
        }
    }
    return NULL;
}