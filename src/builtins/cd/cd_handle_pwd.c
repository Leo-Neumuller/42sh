/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** cd_handle_pwd
*/
#include "mysh.h"

char *return_home(char **env)
{
    int i = 0;
    char *equalptr = NULL;

    for (i = 0; env[i] != 0; i++) {
        equalptr = my_strstr(env[i], "=");
        equalptr[0] = '\0';
        if (my_strcmp("HOME", env[i]) == 0) {
            equalptr[0] = '=';
            break;
        }
        equalptr[0] = '=';
        equalptr = NULL;
    }
    if (equalptr != NULL)
        return &equalptr[1];
    return NULL;
}

char *return_pwd(char **env)
{
    int i = 0;
    char *equalptr;

    for (i = 0; env[i] != 0; i++) {
        equalptr = my_strstr(env[i], "=");
        equalptr[0] = '\0';
        if (my_strcmp("PWD", env[i]) == 0) {
            equalptr[0] = '=';
            break;
        }
        equalptr[0] = '=';
    }
    if (equalptr != 0)
        return &equalptr[1];
    return 0;
}

char *return_oldpwd(char **env)
{
    int i = 0;
    char *equalptr;

    for (i = 0; env[i] != 0; i++) {
        equalptr = my_strstr(env[i], "=");
        equalptr[0] = '\0';
        if (my_strcmp("OLDPWD", env[i]) == 0) {
            equalptr[0] = '=';
            break;
        }
        equalptr[0] = '=';
    }
    if (equalptr != 0)
        return &equalptr[1];
    return 0;
}

char *make_new_pwd(char *fullpath)
{
    char *pwd = NULL;

    add_char_to_array('P', &pwd);
    add_char_to_array('W', &pwd);
    add_char_to_array('D', &pwd);
    add_char_to_array('=', &pwd);
    for (int i = 0; fullpath[i] != '\0'; i++) {
        add_char_to_array(fullpath[i], &pwd);
    }
    return pwd;
}