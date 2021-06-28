/*
** EPITECH PROJECT, 2021
** read file
** File description:
** read the file
*/
#include "my.h"

char *read_file(char *path)
{
    char *file;
    int size = 0;
    int fd = open(path, O_RDONLY);

    while (read(fd, &(char) {0}, 1) != 0) {
        size++;
    }
    file = malloc(sizeof(char) * size + 1);
    if (file == NULL)
        return NULL;
    close(fd);
    fd = open(path, O_RDONLY);
    read(fd, file, size);
    file[size] = '\0';
    close(fd);
    return &file[0];
}