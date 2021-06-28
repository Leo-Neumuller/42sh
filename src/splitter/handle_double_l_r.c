/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** handle_double_l_r
*/
#include "mysh.h"

static void dup_into_stdin(int file, app_t *app, char ***arr)
{
    int savestdout = dup(0);

    dup2(file, 0);
    if (last_is_singlecmd(app, arr)) {
        close(file);
        dup2(savestdout, 0);
        close(savestdout);
        app->current_arg = app->current_arg + 1;
        return;
    }
    exec_pipes(app, arr);
    close(file);
    dup2(savestdout, 0);
    close(savestdout);
    corpse_collector(app);
    app->current_arg = app->current_arg + 1;
}

void handle_double_l_r(app_t *app, char ***arr, char *str)
{
    char *buffer = NULL;
    int file = open("/tmp", __O_TMPFILE | O_RDWR, 0);

    add_char_to_array('\n', &str);
    while (getline(&buffer, &(size_t) {0}, stdin) != -1) {
        if (strcmp(buffer, str) == 0)
            break;
        write(file, buffer, my_strlen(buffer));
    }
    lseek(file, 0, SEEK_SET);
    dup_into_stdin(file, app, arr);
}