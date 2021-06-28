/*
** EPITECH PROJECT, 2021
** char_to_linked.c
** File description:
** source file for char to linked list convert
*/

#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>
#include "sh_getline.h"

void str_to_command(key_list_t **command, int *pos, char *command_str)
{
    struct winsize size;

    memset(&size, 0, sizeof(struct winsize));
    ioctl(0, TIOCGWINSZ, &size);
    clean_stdin(*pos, get_command_size(*command) + 1, size);
    reset_cursor(0, GET_MOD(*pos, size.ws_col), GET_DIV(*pos, size.ws_col));
    *pos = 0;
    free_key(*command);
    *command = NULL;
    for (int index = 0; command_str[index] != 0; index++) {
        key_add(command, command_str[index], *pos);
        (*pos)++;
    }
}
