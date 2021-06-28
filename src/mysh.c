/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** mysh
*/

#include "mysh.h"
#include "sh_getline.h"

static void intercept_sig(int signal)
{
    (void)signal;
    my_printf("\n$> ");
}

char **handle_arg(char **arg, char **env, app_t *app, history_t *hs)
{
    char *buffer = sh_getline(env, hs);

    if (buffer == NULL || buffer[0] == -1) {
        free_double_array(env);
        if (!arg)
            free(arg);
        if (buffer == NULL)
            app->return_value = 84;
        exit(app->return_value);
    }
    else if (buffer != NULL) {
        app->buffer = my_mstrcpy(buffer);
        arg = split_buffer(app, arg);
    }
    free(buffer);
    return (arg);
}

static char **remake_env(char **env)
{
    char **tmp = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        tmp = add_to_double_array(env[i], tmp);
    }
    return tmp;
}

static void set_default_path_and_env(app_t *app, char **env)
{
    app->saved_path = NULL;
    add_str_to_array("/usr/local/bin:/usr/bin:/bin", &app->saved_path);
    if (env == NULL)
        app->env = NULL;
    else
        app->env = remake_env(env);
}

void read_prompt(char **env)
{
    app_t app;
    history_t hs;

    if (load_hs_struct(&hs) != 0)
        return;
    app.return_value = 0;
    set_default_path_and_env(&app, env);
    signal(SIGINT, intercept_sig);
    sh_loop(&app, &hs);
}
