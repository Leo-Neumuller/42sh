/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** check_for_delimiter
*/
#include "mysh.h"

int check_for_delimiter(char *str)
{
    if (str == NULL)
        return 1;
    if (my_strcmp(str, "|") == 0)
        return 1;
    if (my_strcmp(str, ";") == 0)
        return 1;
    if (my_strcmp(str, "<") == 0)
        return 1;
    if (my_strcmp(str, "<<") == 0)
        return 1;
    if (my_strcmp(str, ">") == 0)
        return 1;
    if (my_strcmp(str, ">>") == 0)
        return 1;
    return 0;
}