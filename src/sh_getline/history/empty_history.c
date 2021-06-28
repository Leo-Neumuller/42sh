/*
** EPITECH PROJECT, 2021
** empty_history.c
** File description:
** make empty_history
*/

#include "mysh.h"
#include "sh_getline.h"

int make_empty_history(history_t *hs)
{
    hs->list = malloc(sizeof(char *) * (1));
    if (hs->list == NULL)
        return (error_message("Error: Allocation failed\n"));
    hs->list[0] = NULL;
    hs->size = 0;
    hs->pos = 0;
    return (0);
}
