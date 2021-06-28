/*
** EPITECH PROJECT, 2021
** error
** File description:
** error
*/

#include "mysh.h"

int find_or(app_t *app)
{
    int now = app->current_arg - 2;

    for (; now > 0; now--) {
        if (my_strcmp(app->arg[now], ";") == 0)
            return (app->current_arg - 2);
        if (check_mult_env(app, now) == 1 &&
        my_strcmp(app->arg[now], "||") == 0)
            return (now);
    }
    return (now);
}

int check_null(app_t *app)
{
    int i = 0;

    for (; app->arg[i] != NULL; i++) {
        if (my_strcmp(app->arg[i], "&&") == 0 && app->arg[i + 1] == NULL) {
            pferror("Invalid null command.\n");
            return (1);
        } if (my_strcmp(app->arg[i], "||") == 0 && app->arg[i + 1] == NULL) {
            pferror("Invalid null command.\n");
            return (1);
        } if (my_strcmp(app->arg[i], "&&") == 0 && check_mult_env(app, i + 1)) {
            pferror("Invalid null command.\n");
            return (1);
        } if (my_strcmp(app->arg[i], "||") == 0 && check_mult_env(app, i + 1)) {
            pferror("Invalid null command.\n");
            return (1);
        }
    }
    return (0);
}