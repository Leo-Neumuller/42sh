/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/
#include "mysh.h"

int main(int argc, char **argv, char **env)
{
    (void)argv;
    (void)argc;
    read_prompt(env);
    for (int i = 0; env[i] != 0; i++) {
        if (!env[i])
            free(env[i]);
    }
}