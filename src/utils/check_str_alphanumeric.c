/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh-mathis.lechopier
** File description:
** check_str_alpha
*/

static int check_numeric(char current)
{
    if (current < '0' || current > '9')
        return 1;
    return 0;
}

static int check_alpha(char current)
{
    if (current < 'a' || current > 'z') {
        if (current < 'A' || current > 'Z') {
            return check_numeric(current);
        }
    }
    return 0;
}

int check_str_alphanumeric(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '_')
            continue;
        if (check_alpha(str[i]))
            return 1;
    }
    return 0;
}