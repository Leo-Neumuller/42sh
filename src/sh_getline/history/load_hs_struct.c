/*
** EPITECH PROJECT, 2021
** load_hs_struct.c
** File description:
** load_hs_struct
*/

#include "my.h"
#include "mysh.h"
#include "sh_getline.h"

int next_len(char *buff)
{
    int len = 0;

    for (int i = 0; buff[i] != '\0' && buff[i] != '\n'; i++)
        len++;
    return (len);
}

int list_size(char *buff)
{
    int len = 0;
    int size = 0;

    for (int i = 0; buff[i] != '\0'; i += len + 1) {
        len = next_len(&buff[i]);
        if (len > 0)
            size++;
        if (buff[i + len] == '\0')
            i--;
    }
    return (size);
}

int build_history_line(char *buff, history_t *hs, int pos, int len)
{
    int i = 0;

    hs->list[pos] = malloc(sizeof(char) * (len + 1));
    if (hs->list[pos] == NULL)
        return (error_message("Error: Allocation failed\n"));
    for (; buff[i] != '\0' && buff[i] != '\n'; i++)
        hs->list[pos][i] = buff[i];
    hs->list[pos][i] = '\0';
    return (0);
}

int create_history(char *buff, history_t *hs)
{
    int size = list_size(buff);
    int len = 0;
    int y = 0;

    hs->list = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; buff[i] != '\0'; i += len + 1) {
        len = next_len(&buff[i]);
        if (len > 0 && build_history_line(&buff[i], hs, y, len) != 0)
            return (84);
        if (buff[i + len] == '\0')
            i--;
        if (len > 0)
            y++;
    }
    hs->list[y] = NULL;
    return (0);
}

int load_hs_struct(history_t *hs)
{
    int fd = open(".sh_history", O_RDONLY);
    struct stat file;
    char *buff;

    hs->current = NULL;
    hs->list = NULL;
    if (fd == -1  || (stat(".sh_history", &file)) == -1)
        return (make_empty_history(hs));
    buff = malloc(sizeof(char) * (file.st_size + 1));
    read(fd, buff, file.st_size);
    buff[file.st_size] = '\0';
    if (create_history(buff, hs) != 0)
        return (84);
    free(buff);
    hs->size = count_array(hs->list);
    hs->pos = hs->size;
    return (0);
}
