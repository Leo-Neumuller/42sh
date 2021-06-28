/*
** EPITECH PROJECT, 2021
** completion_init.c
** File description:
** source file for auto-completion name init.
*/

#include <stdlib.h>
#include <string.h>
#include "sh_getline.h"

path_command_t *completion_init(char *command)
{
    path_command_t *completion = malloc(sizeof(path_command_t));

    if (completion == NULL)
        return (NULL);
    completion->command = strdup(command);
    completion->next = NULL;
    if (completion->command == NULL) {
        free(completion);
        return (NULL);
    }
    return (completion);
}

void completion_add(path_command_t **completion, char *command)
{
    path_command_t *current = *completion;

    if (*completion == NULL) {
        *completion = completion_init(command);
        return;
    }
    for (; current->next != NULL; current = current->next);
    current->next = completion_init(command);
}

void completion_remove(path_command_t **completion, int pos)
{
    path_command_t *current = *completion;
    path_command_t *next;

    if (*completion == NULL)
        return;
    for (int i = 0; current->next != NULL && i < pos - 1; i++)
        current = current->next;
    next = current->next;
    if (next == NULL && pos != 0)
        return;
    if (pos != 0) {
        current->next = next->next;
        free(next);
    } else {
        next = (*completion)->next;
        free(*completion);
        *completion = next;
    }
}

void free_completion(path_command_t *completion)
{
    path_command_t *current;

    if (completion == NULL)
        return;
    for (current = completion; completion != NULL; completion = current) {
        current = current->next;
        free(completion->command);
        free(completion);
    }
}

int get_completion_size(path_command_t *completion)
{
    path_command_t *current = completion;
    int size = 0;

    if (completion == NULL)
        return (0);
    for (; current != NULL; current = current->next)
        size++;
    return (size);
}