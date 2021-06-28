/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** set_pwd_if_null
*/

#include "mysh.h"

static void add_to_null_env(app_t *app)
{
    char *newenv = NULL;
    char buffer[BUFSIZ];

    add_str_to_array("PWD=", &newenv);
    add_str_to_array(getcwd(buffer, BUFSIZ), &newenv);
    app->env = add_to_double_array(newenv, app->env);
    free(newenv);
    newenv = NULL;
    add_str_to_array("OLDPWD=", &newenv);
    add_str_to_array(getcwd(buffer, BUFSIZ), &newenv);
    app->env = add_to_double_array(newenv, app->env);
}

static void setenv_for_pwd(app_t *app, char *env)
{
    char **arg = NULL;
    char buffer[BUFSIZ];

    arg = add_to_double_array("setenv", arg);
    arg = add_to_double_array(env, arg);
    arg = add_to_double_array(getcwd(buffer, BUFSIZ), arg);
    app->env = setenv_builtins(arg, app->env, app);
    free_double_array(arg);
}

static void set_oldpwd_if_null(app_t *app)
{
    for (int i = 0; app->env[i] != NULL; i++) {
        if (my_strstr(app->env[i], "OLDPWD=") != NULL)
            return;
    }
    setenv_for_pwd(app, "OLDPWD");
}

void set_pwd_if_null(app_t *app)
{
    if (app->env == NULL) {
        add_to_null_env(app);
        return;
    }
    set_oldpwd_if_null(app);
    for (int i = 0; app->env[i] != NULL; i++) {
        if (my_strstr(app->env[i], "PWD=") != NULL &&
        my_strstr(app->env[i], "OLDPWD=") == NULL)
            return;
    }
    setenv_for_pwd(app, "PWD");
}