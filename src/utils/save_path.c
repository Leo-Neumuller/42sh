/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** save_path
*/
#include "mysh.h"

void save_path(app_t *app)
{
    app->saved_path = NULL;
    add_str_to_array(return_path(app->env), &app->saved_path);
}