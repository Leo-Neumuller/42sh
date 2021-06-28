/*
** EPITECH PROJECT, 2020
** my_put_long
** File description:
** print a long
*/
#include "my.h"

void my_put_long(long n)
{
    int mod = 0;
    if (n <= 9 && n >= 0)
        my_putchar(n + 48);
    if (n < 0) {
        my_putchar('-');
        n = n * (-1);
        if (n <= 9 && n >= 0)
            my_put_long(n);
    }
    if (n > 9) {
        mod = n % 10;
        my_put_long(n / 10);
        my_putchar(mod + 48);
    }
}