/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** unsetenv
*/
#include "mysh.h"

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

char **remove_in_double_arr(int i, char **arr)
{
    char **tmp = NULL;

    for (int a = 0; arr[a] != 0; a++) {
        if (a != i)
            tmp = add_to_double_array(arr[a], tmp);
    }
    free_double_array(arr);
    return tmp;
}

static int unsetenv_error(char **argv, app_t *app)
{
    if (argv[1] == NULL) {
        pferror("unsetenv: Too few arguments.\n");
        app->return_value = 1;
        return 1;
    }
    return 0;
}

char **builtins_unsetenv(char **argv, char **env, app_t *app)
{
    int i;

    (void)app;
    if (unsetenv_error(argv, app))
        return env;
    if ((i = return_existing_env(env, argv)) != -1) {
        if (my_strcmp(argv[1], "PATH") == 0)
            save_path(app);
        env = remove_in_double_arr(i, env);
    }
    return env;
}