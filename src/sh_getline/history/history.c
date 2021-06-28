/*
** EPITECH PROJECT, 2021
** history.c
** File description:
** history
*/

#include "my.h"
#include "mysh.h"
#include "sh_getline.h"

int error_message(char *msg)
{
    write(2, msg, strlen(msg));
    return (84);
}

void destroy_current(history_t *hs)
{
    if (hs->current != NULL) {
        free(hs->current);
        hs->current = NULL;
    }
}

int build_current(history_t *hs, key_list_t **command)
{
    if (hs->current != NULL) {
        free(hs->current);
        hs->current = NULL;
    }
    hs->current = command_to_str(*command);
    if (hs->current[0] == -1 && hs->size != 0)
        hs->current[0] = '\0';
    if (hs->current == NULL)
        return (error_message("Error: Allocation failed\n"));
    return (0);
}

int count_array(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}
