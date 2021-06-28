/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copy a string into another string
*/
#include "my.h"

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
