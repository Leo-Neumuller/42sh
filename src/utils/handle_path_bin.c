/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-leo.neumuller
** File description:
** handle_path_bin
*/
#include "mysh.h"

static void handle_double_dot(int *lastpos, char *path, int i,
char **fullpath)
{
    path[i] = '\0';
    *fullpath = NULL;
    add_str_to_array(&path[*lastpos], fullpath);
    add_char_to_array('/', fullpath);
}

char *split_path(char *path, int i, int *lastpos, char **argv)
{
    char *fullpath;
    char currentchar;
    if (path[i + 1] == '\0') {
        fullpath = NULL;
        add_str_to_array(&path[*lastpos], &fullpath);
        add_char_to_array('/', &fullpath);
        add_str_to_array(argv[0], &fullpath);
        *lastpos = i + 1;
        return fullpath;
    }
    if (path[i] == ':') {
        currentchar = path[i];
        handle_double_dot(lastpos, path, i, &fullpath);
        add_str_to_array(argv[0], &fullpath);
        path[i] = currentchar;
        *lastpos = i + 1;
        return fullpath;
    }
    return NULL;
}