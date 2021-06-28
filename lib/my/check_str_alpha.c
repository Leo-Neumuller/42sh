/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** check_str_alpha
*/

static int check_alpha(char current)
{
    if (current < 'a' || current > 'z') {
        if (current < 'A' || current > 'Z') {
            return 1;
        }
    }
    return 0;
}

int check_str_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_alpha(str[i]))
            return 1;
    }
    return 0;
}