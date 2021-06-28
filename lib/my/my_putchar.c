/*
** EPITECH PROJECT, 2020
** my_putchar.c
** File description:
** Write the character taken in the parameters
*/
#include "my.h"
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}
