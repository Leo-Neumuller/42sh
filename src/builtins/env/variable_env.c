/*
** EPITECH PROJECT, 2021
** variable_env.c
** File description:
** variable_env
*/

#include <string.h>
#include "mysh.h"

void handle_return_value(app_t *app, int i)
{
    char *nbr_str = my_itoa(app->return_value);

    if (nbr_str == NULL)
        return;
    memset(app->arg[i], 0, strlen(app->arg[i]));
    app->arg[i] = realloc(app->arg[i], (sizeof(char) * my_strlen(nbr_str) + 1));
    app->arg[i] = my_strcpy(app->arg[i], nbr_str);
    free(nbr_str);
}

void recup_variable(app_t *app, int i)
{
    if (app->arg[i][0] == '$' && app->arg[i][1] == '?')
        handle_return_value(app, i);
}

void variable_env(app_t *app)
{
    if (app->arg == NULL)
        return;
    for (int i = 0; app->arg[i] != NULL; i++)
        recup_variable(app, i);
}