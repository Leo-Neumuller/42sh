/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** put every upercase letter to lowercase
*/
#include "my.h"
#include <stdlib.h>

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return &str[0];
}