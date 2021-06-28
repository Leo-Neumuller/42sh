/*
** EPITECH PROJECT, 2021
** empty_alias.c
** File description:
** empty_alias
*/

#include "mysh.h"
#include "my.h"
#include "sh_getline.h"

int make_empty_alias(app_t *app)
{
    app->alias = malloc(sizeof(char *) * (1));
    if (app->alias == NULL)
        return (error_message("Error: Allocation failed\n"));
    app->alias[0] = NULL;
    app->alias_size = 0;
    return (0);
}
