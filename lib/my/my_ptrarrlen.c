/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban-leo.neumuller
** File description:
** my_ptrarrlen
*/

#include "my.h"

int my_ptrarrlen(char **arr)
{
    int i = 0;

    for (i = 0; arr[i] != NULL; i++);
    return i;
}