/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** handle_enoexec
*/
#include "mysh.h"
#include <errno.h>

void handle_enoexec(app_t *app)
{
    if (errno == ENOEXEC) {
        pferror(app->splited_arg[0]);
        pferror(": Exec format error. Wrong Architecture.\n");
        exit(1);
    }
}