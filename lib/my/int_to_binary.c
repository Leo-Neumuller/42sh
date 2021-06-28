/*
** EPITECH PROJECT, 2020
** int_to_binary
** File description:
** int to binary
*/

#include <stdlib.h>
#include "my.h"

char *int_to_binary(unsigned int nb)
{
    char *tmp;
    unsigned int res = nb;

    tmp = malloc(1);
    if (tmp == NULL)
        return NULL;
    tmp[0] = '\0';
    while (res != 0) {
        add_char_to_array((res % 2) + '0', &tmp);
        res /= 2;
    }
    my_revstr(tmp);
    return tmp;
}