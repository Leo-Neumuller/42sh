/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** error_not_found
*/
#include "mysh.h"

void error_not_found(app_t *app)
{
    write(2, app->splited_arg[0], my_strlen(app->splited_arg[0]));
    write(2, ": Command not found.\n", 21);
    app->return_value = 1;
    exit(app->return_value);
}