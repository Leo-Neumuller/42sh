/*
** EPITECH PROJECT, 2021
** sh_loop.c
** File description:
** sh_loop
*/

#include "my.h"
#include "mysh.h"
#include "sh_getline.h"

void sh_loop(app_t *app, history_t *hs)
{
    while (1) {
        app->arg = NULL;
        set_pwd_if_null(app);
        app->arg = handle_arg(app->arg, app->env, app, hs);
        variable_env(app);
        app->return_value = 0;
        check_if_pipe(app);
        if (app->arg != NULL && add_to_history(hs, app->arg) != 0)
            exit(84);
        handle_exit(app, hs);
        free_double_array(app->arg);
    }
    free_double_array(app->env);
}