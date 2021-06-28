/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** setenv
*/
#include "mysh.h"

static int check_name_alpha(char **argv, app_t *app)
{
    if (argv[1][0] < 'a' || argv[1][0] > 'z') {
        if ((argv[1][0] < 'A' || argv[1][0] > 'Z') && argv[1][0] != '_') {
            pferror("setenv: Variable name must begin with a letter.\n");
            app->return_value = 1;
            return 1;
        }
    }
    if (check_str_alphanumeric(argv[1])) {
        pferror(
            "setenv: Variable name must contain alphanumeric characters.\n");
        app->return_value = 1;
        return 1;
    }
    return 0;
}

static int return_existing_env(char **env, char **argv)
{
    int i = 0;
    char *equalptr;

    for (i = 0; env[i] != 0; i++) {
        equalptr = my_strstr(env[i], "=");
        equalptr[0] = '\0';
        if (my_strcmp(argv[1], env[i]) == 0) {
            equalptr[0] = '=';
            equalptr = env[i];
            return i;
        }
        equalptr[0] = '=';
        equalptr = 0;
    }
    return -1;
}

static char **add_to_env(char **argv, int size, char **env)
{
    char *tmp = NULL;

    add_str_to_array(argv[1], &tmp);
    add_char_to_array('=', &tmp);
    if (size >= 3)
        add_str_to_array(argv[2], &tmp);
    env = add_to_double_array(tmp, env);
    free(tmp);
    return env;
}

static int print_env_if_arg_null(char **argv, char **env, app_t *app)
{
    if (argv[1] == NULL || argv[1][0] == '\0') {
        builtins_env(argv, env, app);
        return 1;
    }
    return 0;
}

char **setenv_builtins(char **argv, char **env, app_t *app)
{
    int i = -1;
    int size = 0;
    char *new_env = NULL;
    (void)app;
    if (print_env_if_arg_null(argv, env, app) || check_name_alpha(argv, app))
        return app->env;
    for (size = 0; argv[size] != NULL; size++);
    if ((i = return_existing_env(env, argv)) != -1) {
        if (!env[i])
            free(env[i]);
        add_str_to_array(argv[1], &new_env);
        add_char_to_array('=', &new_env);
        if (size >= 3) {
            add_str_to_array(argv[2], &new_env);
        }
        env[i] = new_env;
    } else
        app->env = add_to_env(argv, size, app->env);
    return app->env;
}