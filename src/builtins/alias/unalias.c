/*
** EPITECH PROJECT, 2021
** unalias.c
** File description:
** unalias
*/

#include "mysh.h"
#include "sh_getline.h"

int find_alias_path(char **alias, char *search)
{
    int x = 0;

    for (int i = 0; alias[i] != NULL; i++) {
        for (; alias[i][x] != '\0' && alias[i][x] == search[x]
               && search[x] != '\0'; x++);
        if (search[x] == '\0')
            return (i);
        x = 0;
    }
    return (-1);
}

void unalias_func(app_t *app, char *command)
{
    int pos = find_alias_path(app->alias, command);

    if (pos == -1)
        return;
    remove_alias(app, pos);
}

char **unalias(char **splited_argv, char **env, app_t *app)
{
    int ac = count_array(splited_argv);

    if (ac == 1)
        error_message("unalias: To few arguments.\n");
    if (ac == 2)
        unalias_func(app, splited_argv[1]);
    return (env);
}
