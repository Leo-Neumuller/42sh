/*
** EPITECH PROJECT, 2021
** add_alias.c
** File description:
** add_alias
*/

#include "mysh.h"
#include "my.h"
#include "sh_getline.h"

int make_alias_line(app_t *app, int pos, char **new)
{
    new[pos] = malloc(sizeof(char) * (strlen(app->alias[pos]) + 1));
    if (new[pos] == NULL)
        return (error_message("Error: Allocation failed\n"));
    strcpy(new[pos], app->alias[pos]);
    return (0);
}

int add_alias(app_t *app, char *alias)
{
    int size = count_array(app->alias);
    char **new = malloc(sizeof(char *) * (size + 2));
    int i = 0;

    if (new == NULL)
        return (error_message("Error: Allocation failed\n"));
    for (; app->alias[i] != NULL; i++)
        if (make_alias_line(app, i, new) != 0)
            return (84);
    new[i] = malloc(sizeof(char) * (strlen(alias) + 1));
    if (new[i] == NULL)
        return (error_message("Error: Allocation failed\n"));
    strcpy(new[i], alias);
    i++;
    new[i] = NULL;
    free_array(app->alias);
    app->alias = new;
    return (0);
}
