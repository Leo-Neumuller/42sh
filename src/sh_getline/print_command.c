/*
** EPITECH PROJECT, 2021
** print_command.c
** File description:
** source file for command print handle
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include "sh_getline.h"

void print_prompt(void)
{
    for (int i = 0; i < 3; i++)
        move_cursor((void *)"D");
    write(0, "$> ", 3);
}

void clean_stdin(int pos, int clean, struct winsize size)
{
    int pos_y = GET_DIV(pos, size.ws_col);
    int pos_x = GET_MOD(pos, size.ws_col);
    int clean_y = GET_DIV(clean, size.ws_col);
    int clean_x = GET_MOD(clean, size.ws_col);
    int index = 0;
    int full_index = 0;

    reset_cursor(0, pos_x, pos_y);
    for (int i = 0; i < clean; i++, index++) {
        if (GET_DIV(index, size.ws_col) != 0) {
            full_index += index;
            reset_cursor(full_index, GET_MOD(full_index - 1, size.ws_col),
                        GET_DIV(full_index - 1, size.ws_col));
            index = 0;
        }
        write(0, " ", 1);
    }
    reset_cursor(0, clean_x, clean_y);
    print_prompt();
}

void final_display(key_list_t *command, int pos, struct winsize size)
{
    key_list_t *current = command;
    int command_size = get_command_size(command);
    int pos_y = GET_DIV(command_size, size.ws_col);
    int pos_x = GET_MOD(command_size, size.ws_col);
    int index = 0;
    int full_index = 0;

    for (; current != NULL; current = current->next, index++) {
        if (GET_DIV(index, size.ws_col) != 0) {
            full_index += index;
            reset_cursor(full_index, GET_MOD(full_index - 1, size.ws_col),
                        GET_DIV(full_index - 1, size.ws_col));
            index = 0;
        }
        write(0, &current->key, 1);
    }
    reset_cursor(pos, pos_x, pos_y);
}

void print_command(key_list_t *command, int pos)
{
    struct winsize size;

    memset(&size, 0, sizeof(struct winsize));
    ioctl(0, TIOCGWINSZ, &size);
    clean_stdin(pos, get_command_size(command) + 1, size);
    final_display(command, pos, size);
}