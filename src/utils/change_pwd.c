/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** change_pwd
*/
#include "mysh.h"

static void cut_path(char *fullpath)
{
    int a = 0;

    for (int i = my_strlen(fullpath); i >= 0; i--) {
        if (fullpath[i] == '/' && a == 1) {
            fullpath[i] = '\0';
            break;
        } else if (fullpath[i] == '/')
            a++;
    }
}

static void change_oldpwd(char **env, int i, char *pwd)
{
    char *newoldpwd = malloc(1);

    if (newoldpwd == NULL)
        return;
    newoldpwd[0] = '\0';
    add_str_to_array("OLDPWD=", &newoldpwd);
    add_str_to_array(pwd, &newoldpwd);
    free(env[i]);
    env[i] = newoldpwd;
}

void change_pwd(char *fullpath, char **argv, char **env,
char *pwd)
{
    int i = 0;
    char *equalptr;

    if (my_strstr(argv[1], "..") != 0) {
        cut_path(fullpath);
    }
    for (i = 0; env[i] != 0; i++) {
        equalptr = my_strstr(env[i], "=");
        equalptr[0] = '\0';
        if (my_strcmp("OLDPWD", env[i]) == 0) {
            equalptr[0] = '=';
            break;
        }
        equalptr[0] = '=';
    }
    change_oldpwd(env, i, pwd);
}