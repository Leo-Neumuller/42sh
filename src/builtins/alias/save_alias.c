/*
** EPITECH PROJECT, 2021
** save_alias.c
** File description:
** save_alias
*/

#include "my.h"
#include "mysh.h"
#include "sh_getline.h"

int save_alias(app_t *app)
{
    int file = open(".sh_rc", O_CREAT | O_RDWR | O_TRUNC, 0664);

    for (int i = 0; app->alias[i] != NULL; i++) {
        write(file, app->alias[i], strlen(app->alias[i]));
        write(file, "\n", 1);
    }
    close(file);
    free_array(app->alias);
    return (0);
}
