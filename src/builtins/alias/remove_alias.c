/*
** EPITECH PROJECT, 2021
** remove_alias.c
** File description:
** remove_alias
*/

#include "mysh.h"
#include "sh_getline.h"

int remove_alias(app_t *app, int pos)
{
    int size = count_array(app->alias);
    char **new = malloc(sizeof(char *) * (size));
    int i = 0;
    int y = 0;

    if (new == NULL)
        return (error_message("Error: Allocation failed\n"));
    for (; app->alias[i] != NULL; i++) {
        if (i != pos) {
            new[y] = malloc(sizeof(char) * (strlen(app->alias[i]) + 1));
            if (new[y] == NULL)
                return (error_message("Error: Allocation failed\n"));
            strcpy(new[y], app->alias[i]);
            y++;
        }
    }
    new[y] = NULL;
    free_array(app->alias);
    app->alias = new;
    return (0);
}
