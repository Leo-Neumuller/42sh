/*
** EPITECH PROJECT, 2021
** insert_in_double_arr
** File description:
** insert_in_double_arr
*/
#include "my.h"

char **insert_in_double_arr(int pos, char *str, char **arr)
{
    char **new_arr = NULL;

    for (int i = 0; i < pos && arr[i]; i++) {
        new_arr = add_to_double_array(arr[i], new_arr);
    }
    new_arr = add_to_double_array(str, new_arr);
    for (int i = pos; arr[i]; i++) {
        new_arr = add_to_double_array(arr[i], new_arr);
    }
    free(arr);
    return new_arr;
}