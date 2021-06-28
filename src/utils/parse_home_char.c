/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** parse_home_char
*/
#include "mysh.h"

void parse_home_char(char **str, app_t *app)
{
    char *tmp = NULL;

    if (*str[0] == '~') {
        add_str_to_array(return_home(app->env), &tmp);
        if (my_strlen(*str) > 1)
            add_str_to_array(&(*str)[1], &tmp);
        free(*str);
        *str = tmp;
    }
}