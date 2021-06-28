/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** add_str_to_array
*/
#include <stdlib.h>
#include "my.h"

void add_str_to_array(char *str, char **to)
{
    for (int i = 0; str[i] != '\0'; i++) {
        add_char_to_array(str[i], to);
    }
}