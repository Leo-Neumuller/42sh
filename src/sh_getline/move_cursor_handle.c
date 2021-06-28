/*
** EPITECH PROJECT, 2021
** move_cursor_handle.c
** File description:
** source file for cursor moving
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include "sh_getline.h"

void move_handle(void **arr[2], int *key, int size, int *pos)
{
    char *keys = "DCAB";
    void (*key_fun_arr[4])(void **, void **, int *) =
        {move_cursor_left, move_cursor_right, history_up, history_down};

    for (int index = 0; index < 4; index++) {
        if (index < 2 && keys[index] == *key)
            key_fun_arr[index]((void **)&key, (void **)&pos, &size);
        if (index < 4 && index >= 2 && keys[index] == *key) {
            key_fun_arr[index](arr[0], arr[1], pos);
            print_command((key_list_t *)*arr[1], *pos);
        }
    }
}

void move_cursor_y(int pos_y, int *actual_pos_y)
{
    while (pos_y != *actual_pos_y) {
        if (*actual_pos_y < pos_y) {
            (*actual_pos_y)++;
            move_cursor((void *)"B");
        } else if (*actual_pos_y > pos_y) {
            (*actual_pos_y)--;
            move_cursor((void *)"A");
        }
    }
}

void move_cursor_x(int pos_x, int *actual_pos_x)
{
    while (pos_x != *actual_pos_x) {
        if (*actual_pos_x < pos_x) {
            (*actual_pos_x)++;
            move_cursor((void *)"C");
        } else if (*actual_pos_x > pos_x) {
            (*actual_pos_x)--;
            move_cursor((void *)"D");
        }
    }
}

void reset_cursor(int pos, int actual_pos_x, int actual_pos_y)
{
    struct winsize size;
    int pos_y;
    int pos_x;

    memset(&size, 0, sizeof(struct winsize));
    ioctl(0, TIOCGWINSZ, &size);
    pos_y = GET_DIV(pos, size.ws_col);
    pos_x = GET_MOD(pos, size.ws_col);
    move_cursor_y(pos_y, &actual_pos_y);
    move_cursor_x(pos_x, &actual_pos_x);
}
