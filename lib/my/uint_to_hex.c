/*
** EPITECH PROJECT, 2020
** uint_to_hex
** File description:
** uint to hex
*/

#include <stdlib.h>
#include "my.h"

char *uint_to_hex(unsigned int nb)
{
    char *tmp;
    unsigned int res = nb;

    tmp = malloc(1);
    if (tmp == NULL)
        return NULL;
    tmp[0] = '\0';
    while (res != 0) {
        if (res % 16 > 9) {
            add_char_to_array((res % 16) + 55, &tmp);
        } else {
            add_char_to_array((res % 16) + '0', &tmp);
        }
        res /= 16;
    }
    my_revstr(tmp);
    return tmp;
}