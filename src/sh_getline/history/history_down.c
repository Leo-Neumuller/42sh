/*
** EPITECH PROJECT, 2021
** history_down.c
** File description:
** history_down
*/

#include "my.h"
#include "mysh.h"
#include "sh_getline.h"

void history_down(void **history, void **command, int *pos)
{
    history_t *hs = (history_t *)*history;
    key_list_t **cmd = (key_list_t **)command;

    if (hs->pos == hs->size)
        return;
    if (hs->pos < hs->size)
        hs->pos++;
    for (; hs->list[hs->pos] != NULL &&
        strlen(hs->current) != 0 && my_strncmp(hs->current,
        hs->list[hs->pos], strlen(hs->current) - 1) != 0; hs->pos++);
    if (hs->pos != hs->size)
        str_to_command(cmd, pos, hs->list[hs->pos]);
    else
        str_to_command(cmd, pos, hs->current);
}
