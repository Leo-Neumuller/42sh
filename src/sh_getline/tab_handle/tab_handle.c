/*
** EPITECH PROJECT, 2021
** tab_handle.c
** File description:
** source file for tab handle
*/

#include <stdlib.h>
#include <string.h>
#include "sh_getline.h"

int check_command_start(key_list_t *command)
{
    key_list_t *current = command;

    if (current == NULL)
        return (1);
    for (; current != NULL; current = current->next)
        if (current->key != ' ')
            return (0);
    return (1);
}

path_command_t *get_completion_command(key_list_t *command, char **env)
{
    key_list_t *current = command;
    path_command_t *completion = NULL;
    char *command_str;

    for (; current != NULL && current->key == ' '; current = current->next);
    command_str = command_to_str(current);
    if (command_str[0] == '.' && command_str[1] == '/')
        get_completion(&completion, &command_str[2], "./");
    else
        completion = get_full_completion(command_str, env);
    free(command_str);
    return (completion);
}

void transform_command(key_list_t **command, int *pos, char *new_command)
{
    size_t index = get_command_size(*command);

    if (index >= strlen(new_command))
        return;
    for (; new_command[index] != '\0'; index++)
        key_add(command, new_command[index], (int)index + 1);
    *pos = index;
}

int tab_handle(key_list_t **command, char **env, int *pos, int key)
{
    path_command_t *completion;

    if (key != '\t')
        return (0);
    if (check_command_start(*command) == 1)
        return (1);
    completion = get_completion_command(*command, env);
    if (completion == NULL)
        return (1);
    else if (get_completion_size(completion) == 1) {
        transform_command(command, pos, completion->command);
        print_command(*command, *pos);
    }
    free_completion(completion);
    return (1);
}