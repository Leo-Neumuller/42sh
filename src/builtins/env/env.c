/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** env
*/
#include "mysh.h"

char **builtins_env(char **argv, char **env, app_t *app)
{
    (void)argv;
    (void)app;
    for (int i = 0; env[i] != 0; i++) {
        my_printf("%s\n", env[i]);
    }
    return env;
}

char *my_getenv(char *str, char **env)
{
    int i = 0;
    char *path = NULL;
    int egale_pos = 0;

    while (env[i] != NULL) {
        if (my_strstr(env[i], str) != NULL) {
            egale_pos = get_egale_pos(env[i]);
            if (egale_pos - 1 == my_strlen(str)) {
                path = my_mstrcpy(&env[i][egale_pos]);
                return (path);
            }
        }
        i++;
    }
    return (NULL);
}