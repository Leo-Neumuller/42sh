/*
** EPITECH PROJECT, 2021
** history_add.c
** File description:
** history_add
*/

#include "my.h"
#include "mysh.h"
#include "sh_getline.h"

int build_new_line(char **save, char **command, int pos)
{
    int len = 0;
    char *line;

    for (int i = 0; command[i] != NULL; i++)
        len += strlen(command[i]) + 1;
    line = malloc(sizeof(char) * (len));
    if (line == NULL)
        return (error_message("Error: Allocation failed\n"));
    line[0] = '\0';
    for (int i = 0; command[i] != NULL; i++) {
        strcat(line, command[i]);
        if (command[i + 1] != NULL)
            strcat(line, " ");
    }
    save[pos] = line;
    return (0);
}

int add_to_history(history_t *hs, char **command)
{
    int size = count_array(hs->list);
    char **save = malloc(sizeof(char *) * (size + 2));
    int i = 0;

    if (save == NULL)
        return (error_message("Error: Allocation failed\n"));
    for (; hs->list[i] != NULL; i++) {
        save[i] = malloc(sizeof(char) * (strlen(hs->list[i]) + 1));
        if (save[i] == NULL)
            return (error_message("Error: Allocation failed\n"));
        strcpy(save[i], hs->list[i]);
    }
    if (build_new_line(save, command, i) != 0)
        return (84);
    save[++i] = NULL;
    hs->list = free_array(hs->list);
    hs->list = save;
    hs->size++;
    hs->pos = hs->size;
    return (0);
}
