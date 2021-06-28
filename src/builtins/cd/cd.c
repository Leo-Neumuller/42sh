/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cd
*/
#include "mysh.h"

static char *return_new_path(char *pwd, char **argv)
{
    char *fullpath = NULL;

    if (argv[1][0] != '/') {
        for (int i = 0; pwd[i] != '\0'; i++)
            add_char_to_array(pwd[i], &fullpath);
        add_char_to_array('/', &fullpath);
        for (int i = 0; argv[1][i] != '\0'; i++)
            add_char_to_array(argv[1][i], &fullpath);
    } else {
        for (int i = 0; argv[1][i] != '\0'; i++)
            add_char_to_array(argv[1][i], &fullpath);
    }
    return fullpath;
}

static int check_if_its_directory(app_t *app, char **argv,
char *fullpath)
{
    struct stat buff;

    if (stat(fullpath, &buff) != -1) {
        if (S_ISREG(buff.st_mode)) {
            write(2, argv[1], my_strlen(argv[1]));
            write(2, ": Not a directory.\n", 19);
            app->return_value = 1;
            free(fullpath);
            return 0;
        }
    } else {
        if (argv[1][0] != '0' && argv[1][0] != '\0')
            write(2, argv[1], my_strlen(argv[1]));
        write(2, ": No such file or directory.\n", 29);
        app->return_value = 1;
        free(fullpath);
        return 0;
    }
    return 1;
}

static int check_if_path_exist(char *fullpath, char **argv, app_t *app)
{
    DIR *tmp;

    if (check_if_its_directory(app, argv, fullpath) == 0)
        return 0;
    tmp = opendir(fullpath);
    if (tmp != NULL) {
        free(tmp);
        return 1;
    }
    else {
        write(2, argv[1], my_strlen(argv[1]));
        write(2, ": Permission denied.\n", 21);
        app->return_value = 1;
        free(fullpath);
        return 0;
    }
    return 0;
}

static void change_path(char *fullpath, app_t *app, char *pwd, char **argv)
{
    int i;
    char *equalptr;

    chdir(fullpath);
    change_pwd(fullpath, argv, app->env, pwd);
    fullpath = make_new_pwd(fullpath);
    for (i = 0; app->env[i] != NULL; i++) {
        equalptr = my_strstr(app->env[i], "=");
        equalptr[0] = '\0';
        if (my_strcmp("PWD", app->env[i]) == 0) {
            equalptr[0] = '=';
            break;
        }
        equalptr[0] = '=';
    }
    free(app->env[i]);
    app->env[i] = fullpath;
}

char **builtins_cd(char **argv, char **env, app_t *app)
{
    char *pwd = return_pwd(env);
    char *fullpath = NULL;

    (void) argv;
    handle_home_arg(app);
    fullpath = return_new_path(pwd, app->splited_arg);
    if (check_if_path_exist(fullpath, app->splited_arg, app) == 0)
        return app->env;
    change_path(fullpath, app, pwd, app->splited_arg);
    app->return_value = 0;
    return app->env;
}