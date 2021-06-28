/*
** EPITECH PROJECT, 2021
** alias_handling.c
** File description:
** alias_handling
*/

#include "mysh.h"
#include "sh_getline.h"

void display_alias(char **alias)
{
    for (int i = 0; alias[i] != NULL; i++)
        printf("%s\n", alias[i]);
}

int alias_check(char *av)
{
    int sep = 0;
    int egal = 0;

    for (int i = 0; av[i] != '\0'; i++) {
        if (av[i] == '\'')
            sep++;
        if (av[i] == ' ' && sep != 1)
            return (84);
        if (av[i] == '=')
            egal++;
    }
    if ((sep != 2 && sep != 0) || egal != 1)
        return (84);
    return (0);
}

char **alias_handling(char **splited_argv, char **env, app_t *app)
{
    int ac = count_array(splited_argv);

    if (ac == 1)
        display_alias(app->alias);
    if (ac == 2 && alias_check(splited_argv[1]) == 0)
        add_alias(app, splited_argv[1]);
    return (env);
}
