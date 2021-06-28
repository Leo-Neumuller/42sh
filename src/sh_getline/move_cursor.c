/*
** EPITECH PROJECT, 2021
** move_cursor.c
** File description:
** source file for cursor move
*/

#include <unistd.h>
#include "sh_getline.h"

void move_cursor(void *key)
{
    int escape = 27;
    int move_key = 91;

    write(0, &escape, 1);
    write(0, &move_key, 1);
    write(0, key, 1);
}

void move_cursor_right(void **key, void **pos, int *size)
{
    int *pos_int = (int *)*pos;

    if (*pos_int < *size) {
        (*pos_int)++;
        move_cursor(*key);
    }
}

void move_cursor_left(void **key, void **pos, __attribute__((unused))int *size)
{
    int *pos_int = (int *)*pos;

    if (*pos_int > 0) {
        (*pos_int)--;
        move_cursor(*key);
    }
}