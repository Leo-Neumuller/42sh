/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** add_to_double_arr
*/
#include "my.h"

static char **handle_null_arr(char *str, char **arr)
{
    if (arr == NULL) {
        arr = malloc((sizeof(char *) * 2));
        if (arr == NULL)
            return (NULL);
        arr[1] = NULL;
        arr[0] = malloc(sizeof(char) * my_strlen(str) + 1);
        if (arr[0] == 0)
            return (NULL);
        my_strcpy(arr[0], str);
        return arr;
    }
    return NULL;
}

static char **loop_add_old(char **tmp, char **arr, int size)
{
    for (int i = 0; i < size; i++) {
        tmp[i] = malloc(sizeof(char) * my_strlen(arr[i]) + 1);
        if (tmp[i] == NULL)
            return NULL;
        my_strcpy(tmp[i], arr[i]);
        free(arr[i]);
    }
    return tmp;
}

char **add_to_double_array(char *str, char **arr)
{
    char **tmp = NULL;
    int size = 0;

    if ((tmp = handle_null_arr(str, arr)) != NULL)
        return tmp;
    for (size = 0; arr[size] != NULL; size++);
    tmp = malloc((sizeof(char *) * (size + 2)));
    if (tmp == NULL)
        return (NULL);
    tmp = loop_add_old(tmp, arr, size);
    tmp[size] = malloc(sizeof(char) * my_strlen(str) + 1);
    if (tmp[size] == NULL)
        return NULL;
    my_strcpy(tmp[size], str);
    tmp[size + 1] = NULL;
    free(arr);
    return tmp;
}