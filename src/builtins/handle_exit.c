/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** handle_exit
*/

#include "sh_getline.h"

static int check_is_numeric(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

static void check_for_exit_arg(app_t *app)
{
    if (check_is_numeric(app->splited_arg[1])) {
        if (isatty(0))
            my_printf("exit\n");
        exit(my_atoi(app->splited_arg[1]));
    } else if (app->splited_arg[1][0] != '|') {
        write(2, "exit: Expression Syntax.\n", 25);
    }
}

static int handle_for_pipes(app_t *app)
{
    if (app->splited_arg[1] == NULL)
        return (0);
    if (app->splited_arg[2] != NULL) {
        if (app->splited_arg[2][0] == '|' &&
        check_is_numeric(app->splited_arg[1]) && app->return_value == 0) {
            app->return_value = my_atoi(app->splited_arg[1]);
            return (1);
        }
        if (app->splited_arg[2][0] == '|' &&
        check_is_numeric(app->splited_arg[1]))
            return (1);
    }
    return (0);
}

static void exec_exit(app_t *app)
{
    if (handle_for_pipes(app))
        return;
    if (app->splited_arg[1] != NULL) {
        check_for_exit_arg(app);
    } else {
        if (isatty(0))
            my_printf("exit\n");
        exit(app->return_value);
    }
}

void handle_exit(app_t *app, history_t *hs)
{
    if (app->arg == NULL)
        return;
    if (app->arg[0] == NULL)
        return;
    for (int i = 0; app->arg[i]; i++) {
        if (my_strcmp(app->arg[i], "exit") == 0) {
            save_history(hs);
            app->splited_arg = &app->arg[i];
            exec_exit(app);
            return;
        }
    }
}
