/*
** EPITECH PROJECT, 2021
** key_handle.c
** File description:
** source file for key handling
*/

#include <unistd.h>
#include <stdio.h>
#include "sh_getline.h"

void remove_key_handle(key_list_t **command, int key, int *pos)
{
    if (key ==  127 && *pos > 0) {
        if (get_command_size(*command) > 1) {
            key_remove(command, *pos - 1);
        } else {
            free_key(*command);
            *command = NULL;
        }
        (*pos)--;
        move_cursor((void *)"D");
        print_command(*command, *pos);
    } else if (key == 51) {
        key = getchar();
        if (key == 126 && get_command_size(*command) > 1) {
            key_remove(command, *pos);
        } else if (key == 126 && get_command_size(*command) == 1) {
            free_key(*command);
            *command = NULL;
        }
        print_command(*command, *pos);
    }
}

int special_key(void **arr[2], int key, int *pos)
{
    while (key == 27) {
        key = getchar();
        if (key == 91) {
            key = getchar();
            remove_key_handle((key_list_t **)arr[1], key, pos);
            move_handle(arr, &key, get_command_size((key_list_t *)*arr[1]),
                pos);
            return (1);
        }
    }
    if (key == 127) {
        remove_key_handle((key_list_t **)arr[1], key, pos);
        return (1);
    }
    return (0);
}

int end_key(key_list_t **command, int key, int *pos)
{
    if (key == '\n') {
        *pos = get_command_size(*command);
        key_add(command, key, *pos);
        print_command(*command, *pos);
        return (1);
    }
    return (0);
}

void key_handle(void **arr[2], char **env, int key, int *pos)
{
    if (special_key(arr, key, pos) == 1 ||
        end_key((key_list_t **)arr[1], key, pos) == 1 ||
        tab_handle((key_list_t **)arr[1], env, pos, key) == 1)
        return;
    key_add((key_list_t **)arr[1], key, *pos);
    (*pos)++;
    print_command((key_list_t *)*arr[1], *pos);
}