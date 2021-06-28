/*
** EPITECH PROJECT, 2021
** 42sh_getline.c
** File description:
** source file for 42sh getline
*/

#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "sh_getline.h"

char *command_to_str(key_list_t *command)
{
    char *command_str;
    key_list_t *current = command;

    command_str = malloc(sizeof(char) * (get_command_size(command) + 1));
    if (command_str == NULL) {
        return (NULL);
    } else if (command == NULL) {
        command_str[0] = -1;
        return (command_str);
    }
    for (int i = 0; current != NULL; current = current->next) {
        command_str[i] = (char)current->key;
        i++;
    }
    command_str[get_command_size(command)] = '\0';
    return (command_str);
}

char *command_taker(char **env, history_t *hs)
{
    char *command_str;
    int key = 0;
    int pos = 0;
    key_list_t *command = NULL;
    void **arr[2] = {(void **)&hs, (void **)&command};

    while (key != '\n') {
        key = getchar();
        if (key == 4 || key == EOF)
            break;
        key_handle(arr, env, key, &pos);
    }
    command_str = command_to_str(command);
    free_key(command);
    return (command_str);
}

char *sh_getline(char **env, history_t *hs)
{
    struct termios save;
    struct termios new;
    char *command;

    memset(&save, 0, sizeof(struct termios));
    memset(&new, 0, sizeof(struct termios));
    tcgetattr(0, &save);
    new = save;
    new.c_lflag &= ~( ECHO | ICANON);
    tcsetattr(0, TCSANOW, &new);
    write(0, "$> ", 3);
    command = command_taker(env, hs);
    tcsetattr(0, TCSANOW, &save);
    destroy_current(hs);
    return (command);
}
