/*
** EPITECH PROJECT, 2021
** history_up.c
** File description:
** history_up
*/

#include "my.h"
#include "mysh.h"
#include "sh_getline.h"

void history_up(void **history, void **command, int *pos)
{
    history_t *hs = (history_t *)*history;
    key_list_t **cmd = (key_list_t **)command;

    if (hs->pos <= 0)
        return;
    if (hs->pos == hs->size)
        build_current(hs, cmd);
    if (hs->pos > 0)
        hs->pos--;
    for (; hs->pos > 0 && strlen(hs->current) != 0 && my_strncmp(hs->current,
        hs->list[hs->pos], strlen(hs->current) - 1) != 0; hs->pos--);
    str_to_command(cmd, pos, hs->list[hs->pos]);
}
