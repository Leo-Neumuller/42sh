/*
** EPITECH PROJECT, 2021
** path_finding.c
** File description:
** source file for binary path finding
*/

#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "sh_getline.h"

int get_env_pos(char **env)
{
    int index = 0;
    int founded = 0;

    for (; env[index] != NULL && founded == 0; index++) {
        if (strncmp(env[index], "PATH=", 5) == 0)
            founded = 1;
    }
    if (founded == 0)
        return (-1);
    return (index);
}

char *copy_bin_path(char *env, int *env_index, int i)
{
    char *bin_path;
    int path_len = i - *env_index;

    bin_path = malloc(sizeof(char) * ( path_len + 1));
    if (bin_path == NULL)
        return (NULL);
    bin_path = strncpy(bin_path, &env[*env_index], path_len);
    bin_path[path_len] = '\0';
    *env_index = i + 1;
    return (bin_path);
}

void get_completion(path_command_t **completion, char *command, char *bin_path)
{
    DIR *bin_dir = opendir(bin_path);
    struct dirent *dir;

    if (bin_path == NULL || bin_dir == NULL)
        return;
    for (dir = readdir(bin_dir); dir != NULL; dir = readdir(bin_dir)) {
        if (strncmp(dir->d_name, command, strlen(command)) == 0 &&
            dir->d_type != DT_DIR)
            completion_add(completion, dir->d_name);
    }
}

path_command_t *get_full_completion(char *command, char **env)
{
    char *bin_path = NULL;
    path_command_t *completion = NULL;
    int env_pos = get_env_pos(env) - 1;
    int env_index = 5;

    if (env_pos < 0)
        return (NULL);
    for (int i = env_index; env[env_pos][env_index - 1] != '\0';
        i++) {
        if (env[env_pos][i] == '\0' || env[env_pos][i] == ':') {
            bin_path = copy_bin_path(env[env_pos], &env_index, i);
            get_completion(&completion, command, bin_path);
        }
        if (bin_path != NULL) {
            free(bin_path);
            bin_path = NULL;
        }
    }
    get_completion(&completion, command, "./");
    return (completion);
}