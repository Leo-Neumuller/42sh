/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-antman-yannis.alouache
** File description:
** put_str_in_list
*/
#include "my.h"
#include <stdlib.h>

static void add_data_to_list(linked_list_str *element, char *data)
{
    element->data = malloc(my_strlen(data) + 1);
    if (element->data == NULL)
        return;
    my_strcpy(element->data, data);
}

void put_str_in_list(linked_list_str **list, char *data)
{
    linked_list_str *element =
    (linked_list_str *) malloc(sizeof(linked_list_str));
    linked_list_str *tmp = *list;

    if (element == NULL)
        return;
    element->next = NULL;
    add_data_to_list(element, data);
    if (*list == NULL) {
        *list = element;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = element;
}