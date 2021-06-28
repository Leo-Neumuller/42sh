/*
** EPITECH PROJECT, 2020
** my_itoa.c
** File description:
** my itoa
*/

#include "my.h"

int find_nbr_len(int nbr)
{
    int len = 0;

    if (nbr < 0)
        len++;
    for (int mod = 10; nbr % mod != nbr; mod *= 10)
        len++;
    return (len);
}

char *my_itoa(int nbr)
{
    long power = 1;
    long mod = 10;
    int len = find_nbr_len(nbr);
    char *result = malloc(sizeof(char) * len + 1);

    result[len + 1] = '\0';
    if (nbr == 0) {
        result[0] = '0';
        return (result);
    }
    if (nbr < 0) {
        result[0] = '-';
        nbr *= -1;
    }
    for (; nbr / power != 0; len--) {
        result[len] = (nbr % mod) / power + 48;
        power *= 10;
        mod *= 10;
    }
    return (result);
}
