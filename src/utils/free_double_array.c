/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** free_double_array
*/
#include "mysh.h"

void free_double_array(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i] == NULL)
            return;
        free(arr[i]);
    }
    free(arr);
}