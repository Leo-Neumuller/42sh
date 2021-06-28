/*
** EPITECH PROJECT, 2021
** load_alias.c
** File description:
** load_alias
*/

#include "my.h"
#include "mysh.h"
#include "sh_getline.h"

int next_len_alias(char *buff)
{
    int len = 0;

    for (int i = 0; buff[i] != '\0' && buff[i] != '\n'; i++)
        len++;
    return (len);
}

int list_size_alias(char *buff)
{
    int len = 0;
    int size = 0;

    for (int i = 0; buff[i] != '\0'; i += len + 1) {
        len = next_len_alias(&buff[i]);
        if (len > 0)
            size++;
        if (buff[i + len] == '\0')
            i--;
    }
    return (size);
}

int build_alias_line(char *buff, app_t *app, int pos, int len)
{
    int i = 0;

    app->alias[pos] = malloc(sizeof(char) * (len + 1));
    if (app->alias[pos] == NULL)
        return (error_message("Error: Allocation failed\n"));
    for (; buff[i] != '\0' && buff[i] != '\n'; i++)
        app->alias[pos][i] = buff[i];
    app->alias[pos][i] = '\0';
    return (0);
}

int create_alias(char *buff, app_t *app)
{
    int size = list_size_alias(buff);
    int len = 0;
    int y = 0;

    app->alias = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; buff[i] != '\0'; i += len + 1) {
        len = next_len_alias(&buff[i]);
        if (len > 0 && build_alias_line(&buff[i], app, y, len) != 0)
            return (84);
        if (buff[i + len] == '\0')
            i--;
        if (len > 0)
            y++;
    }
    app->alias[y] = NULL;
    return (0);
}

int load_alias(app_t *app)
{
    int fd = open(".sh_rc", O_RDONLY);
    struct stat file;
    char *buff;

    app->alias = NULL;
    if (fd == -1  || (stat(".sh_rc", &file)) == -1)
        return (make_empty_alias(app));
    buff = malloc(sizeof(char) * (file.st_size + 1));
    if (buff == NULL)
        return (84);
    read(fd, buff, file.st_size);
    buff[file.st_size] = '\0';
    if (create_alias(buff, app) != 0)
        return (84);
    free(buff);
    app->alias_size = count_array(app->alias);
    return (0);
}
