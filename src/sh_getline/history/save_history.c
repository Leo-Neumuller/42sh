/*
** EPITECH PROJECT, 2021
** save_history.c
** File description:
** save_history
*/

#include "my.h"
#include "mysh.h"
#include "sh_getline.h"

int save_history(history_t *hs)
{
    int file = open(".sh_history", O_CREAT | O_RDWR | O_TRUNC, 0664);

    for (int i = 0; hs->list[i] != NULL; i++) {
        write(file, hs->list[i], strlen(hs->list[i]));
        write(file, "\n", 1);
    }
    close(file);
    free_array(hs->list);
    free(hs->current);
    return (0);
}
