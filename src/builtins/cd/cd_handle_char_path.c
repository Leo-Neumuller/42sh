/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** cd_handle_char_path
*/
#include "mysh.h"

void cd_handle_oldpwd(app_t *app)
{
    char *new_arg = NULL;

    if (my_strcmp(app->splited_arg[1], "-") == 0) {
        add_str_to_array(return_oldpwd(app->env), &new_arg);
        free(app->splited_arg[1]);
        app->splited_arg[1] = malloc(sizeof(char) * my_strlen(new_arg) + 1);
        if (app->splited_arg[1] == NULL)
            return;
        my_strcpy(app->splited_arg[1], new_arg);
        app->splited_arg[1][my_strlen(new_arg)] = '\0';
        free(new_arg);
    }
}

void handle_home_arg(app_t *app)
{
    char *new_arg = NULL;
    if (app->splited_arg[1] == NULL) {
        app->splited_arg = add_to_double_array(return_home(app->env),
        app->splited_arg);
        app->arg = app->splited_arg;
    } else if (app->splited_arg[1][0] == '~') {
        add_str_to_array(return_home(app->env), &new_arg);
        if (app->splited_arg[1][1] != '\0') {
            add_str_to_array(&app->splited_arg[1][1], &new_arg);
        }
        free(app->splited_arg[1]);
        app->splited_arg[1] = malloc(sizeof(char) * my_strlen(new_arg) + 1);
        if (app->splited_arg[1] == NULL)
            return;
        my_strcpy(app->splited_arg[1], new_arg);
        app->splited_arg[1][my_strlen(new_arg)] = '\0';
        free(new_arg);
    }
    cd_handle_oldpwd(app);
}