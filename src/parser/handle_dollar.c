/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** handle_dollar
*/

#include "mysh.h"

int get_egale_pos(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '=') {
            i++;
            return (i);
        }
        i++;
    }
    return (-1);
}

char *my_mstrcpy(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    char *final_str = malloc(sizeof(char) * len + 1);
    if (final_str == NULL)
        exit(1);
    for (i = 0; i < len; i++) {
        final_str[i] = str[i];
    }
    final_str[i] = '\0';
    return (final_str);
}

char *get_echo_env_err(char *tmp)
{
    char *err = malloc(sizeof(tmp) + 22);
    if (err == NULL)
        exit(1);
    err[0] = '\0';
    strcat(err, &tmp[1]);
    strcat(err, ": Undefined variable.");
    err[my_strlen(err)] = '\0';
    return (err);
}

void handle_dollar(char **str, app_t *app) {
    char *tmp = *str;
    char *var = NULL;

    if (*str[0] == '$') {
        var = my_getenv(&tmp[1], app->env);
        if (var == NULL)
            var = get_echo_env_err(tmp);
        free(*str);
        *str = var;
    }
}