/*
** EPITECH PROJECT, 2020
** add_char_to_array
** File description:
** add a char to an array
*/

#include <stdlib.h>
#include "my.h"

char *add_char_to_array(char expr, char **nb)
{
    char *tmp;

    if (*nb != NULL) {
        tmp = malloc(my_strlen(*nb) + 2);
        if (tmp == NULL)
            return (NULL);
        my_strcpy(tmp, *nb);
        tmp[my_strlen(*nb)] = expr;
        tmp[my_strlen(*nb) + 1] = '\0';
        free(*nb);
    } else {
        tmp = malloc(2);
        if (tmp == NULL)
            return (NULL);
        tmp[1] = '\0';
        tmp[0] = expr;
    }
    *nb = tmp;
    return tmp;
}