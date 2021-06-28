/*
** EPITECH PROJECT, 2020
** print_non_printable
** File description:
** print number for non printable c
*/

#include "my.h"

static void print_zero(char c)
{
    if (c < 100 && c > 10) {
        my_putchar('0');
    } else if (c < 10) {
        my_putstr("00");
    }
}

void print_non_printable(unsigned char *c)
{
    for (int i = 0; c[i] != 0; i++) {
        if (c[i] < 32 || c[i] >= 127) {
            my_putchar('\\');
            print_zero(c[i]);
            my_put_nbr(c[i]);
        } else {
            my_putchar(c[i]);
        }
    }
}