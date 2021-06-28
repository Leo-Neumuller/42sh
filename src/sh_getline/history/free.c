/*
** EPITECH PROJECT, 2021
** free.c
** File description:
** free
*/

#include "my.h"

char **free_array(char **array)
{
    for (int i = 0; array != NULL && array[i] != NULL; i++)
        free(array[i]);
    if (array != NULL)
        free(array);
    return (NULL);
}
