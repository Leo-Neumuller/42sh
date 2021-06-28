/*
** EPITECH PROJECT, 2021
** my_atoi
** File description:
** my_atoi
*/
#include "my.h"

int my_atoi(char *nb)
{
    int result = 0;
    int negative = 0;

    for (int i = 0; nb[i] != '\0'; i++) {
        if (nb[i] == '-')
            negative = 1;
        if (nb[i] >= '0' && nb[i] <= '9') {
            result = (result * 10) + (nb[i] - 48);
        }
    }
    if (negative)
        result = result - (result * 2);
    return result;
}