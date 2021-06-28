/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** print_error
*/
#include "mysh.h"

void pferror(char *str)
{
    write(2, str, my_strlen(str));
}