/*
** EPITECH PROJECT, 2020
** long_to_hex
** File description:
** long to hex
*/

#include <stdlib.h>
#include "my.h"

char *long_to_hex(long nb)
{
    char *tmp;
    long res = nb;

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