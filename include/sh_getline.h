/*
** EPITECH PROJECT, 2021
** sh_getline.h
** File description:
** source file for upgraded getline
*/

#ifndef SH_GETLINE_H
#define SH_GETLINE_H

#include <sys/ioctl.h>
#include "mysh.h"
#define GET_DIV(pos, size) (((size) != 0 ? (pos) / (size) : 0))
#define GET_MOD(pos, size) (((size) != 0 ? (pos) % (size) : 0))

typedef struct key_structure{
    int key;
    struct key_structure *next;
}key_list_t;

typedef struct path_command_structure{
    char *command;
    struct path_command_structure *next;
}path_command_t;

char **free_array(char **array);
int build_current(history_t *hs, key_list_t **command);
int count_array(char **array);
void history_down(void **history, void **command, int *pos);
void history_up(void **history, void **command, int *pos);
int build_new_line(char **save, char **command, int pos);
int add_to_history(history_t *hs, char **command);
int load_hs_struct(history_t *hs);
int save_history(history_t *hs);
void key_add(key_list_t **command, int key, int pos);
void key_remove(key_list_t **command, int pos);
void free_key(key_list_t *command);
void completion_add(path_command_t **completion, char *command);
void free_completion(path_command_t *completion);
int get_completion_size(path_command_t *completion);
int get_command_size(key_list_t *command);
void move_cursor(void *key);
void move_cursor_right(void **key, void **pos, int *size);
void move_cursor_left(void **key, void **pos, int *size);
void move_handle(void **arr[2], int *key, int size, int *pos);
void reset_cursor(int pos, int actual_pos_x, int actual_pos_y);
void print_command(key_list_t *command, int pos);
char *command_to_str(key_list_t *command);
void get_completion(path_command_t **completion, char *command, char *bin_path);
path_command_t *get_full_completion(char *command, char **env);
int tab_handle(key_list_t **command, char **env, int *pos, int key);
void key_handle(void **arr[2], char **env, int key, int *pos);
char *sh_getline(char **env, history_t *hs);
int error_message(char *msg);
char **handle_arg(char **arg, char **env, app_t *app, history_t *hs);
void sh_loop(app_t *app, history_t *hs);
void str_to_command(key_list_t **command, int *pos, char *command_str);
int make_empty_history(history_t *hs);
void destroy_current(history_t *hs);
void clean_stdin(int pos, int clean, struct winsize size);

#endif //SH_GETLINE_H
