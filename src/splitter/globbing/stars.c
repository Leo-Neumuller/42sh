/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** stars
*/
#include "mysh.h"

static void handle_no_match(app_t *app, char *str)
{
    if (app->arg[app->delimiter] == NULL)
        pferror(str);
    else
        pferror(app->arg[app->delimiter]);
    pferror(": No match.\n");
    app->return_value = 1;
    for (;check_for_delimiter(app->arg[app->current_arg]) == 0;
    app->current_arg += 1);
    app->current_in_arr = 0;
    app->delimiter = app->current_arg + 1;
}

void init_globbing(char *str, app_t *app)
{
    glob_t globbing;

    if (my_strstr(str, "*") != NULL || my_strstr(str, "?") != NULL
    || my_strstr(str, "[") != NULL) {
        glob(str, GLOB_PERIOD, NULL, &globbing);
        if (globbing.gl_pathv == NULL) {
            handle_no_match(app, str);
            return;
        }
        app->arg[app->current_arg] = globbing.gl_pathv[0];
        for (int i = 1; globbing.gl_pathv[i] != NULL; i++) {
            app->arg = insert_in_double_arr(app->current_arg,
            globbing.gl_pathv[i], app->arg);
            app->count_arg += 1;
        }
    }
}