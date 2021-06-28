/*
** EPITECH PROJECT, 2021
** key_struct_init.c
** File description:
** source file for key struct init
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "sh_getline.h"

key_list_t *key_init(int key)
{
    key_list_t *command = malloc(sizeof(key_list_t));

    if (command == NULL)
        return (NULL);
    command->key = key;
    command->next = NULL;
    return (command);
}

void key_add(key_list_t **command, int key, int pos)
{
    key_list_t *current = *command;
    key_list_t *next;

    if (*command == NULL) {
        *command = key_init(key);
    } else if (pos != 0) {
        for (int i = 0; current->next != NULL && i < pos - 1; i++)
            current = current->next;
        next = current->next;
        current->next = NULL;
        current->next = key_init(key);
        if (next != NULL && current->next != NULL)
            current->next->next = next;
    } else {
        next = key_init(key);
        if (next != NULL) {
            next->next = *command;
            *command = next;
        }
    }
}

void key_remove(key_list_t **command, int pos)
{
    key_list_t *previous = *command;
    key_list_t *current;

    if (command == NULL)
        return;
    for (int i = 0; previous->next != NULL && i < pos - 1; i++)
        previous = previous->next;
    current = previous->next;
    if (current == NULL) {
        previous->next = NULL;
        free(current);
    } else if (pos != 0) {
        previous->next = current->next;
        free(current);
    } else {
        current = (*command)->next;
        free(*command);
        *command = current;
    }
}

void free_key(key_list_t *command)
{
    key_list_t *current;

    if (command == NULL)
        return;
    for (current = command; command != NULL; command = current) {
        current = current->next;
        free(command);
    }
}

int get_command_size(key_list_t *command)
{
    key_list_t *current = command;
    int size = 0;

    if (command == NULL)
        return (0);
    for (; current != NULL; current = current->next)
        size++;
    return (size);
}
