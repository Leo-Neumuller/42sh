/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print a number
*/
#include "my.h"

void my_put_nbr(int n)
{
    int mod = 0;
    if (n <= 9 && n >= 0)
        my_putchar(n + 48);
    if (n < 0) {
        my_putchar('-');
        n = n * (-1);
        if (n <= 9 && n >= 0)
            my_put_nbr(n);
    }
    if (n > 9) {
        mod = n % 10;
        my_put_nbr(n / 10);
        my_putchar(mod + 48);
    }
}
