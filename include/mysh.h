/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** mysh
*/

#include "my.h"
#include <dirent.h>
#include <sys/types.h>
#include <glob.h>

#ifndef MYSH_H_
#define MYSH_H_

typedef enum
{
    NONE,
    PIPE,
    SEMICOLON,
    REDIRECTION,
    OR,
    AND,
} split_t;

typedef struct
{
    char **env;
    char **arg;
    char **splited_arg;
    int current_in_arr;
    int current_arg;
    int delimiter;
    int count_arg;
    int return_value;
    split_t last_split;
    int is_singlecmd;
    int pipes[2];
    char *saved_path;
    char *buffer;
    char **alias;
    int alias_size;
} app_t;

typedef struct
{
    char **env;
    int i;
    char *str;
} dollar_t;

typedef struct history{
    char **list;
    int size;
    int pos;
    char *current;
}history_t;

void read_prompt(char **env);
void run_bin(char **argv, char **env);
char **handle_cmd(app_t *app);
void check_if_bin_exist(app_t *app);
char **builtins_env(char **argv, char **env, app_t *app);
char **builtins_cd(char **argv, char **env, app_t *app);
void change_pwd(char *fullpath, char **argv, char **env, char *pwd);
char **setenv_builtins(char **argv, char **env, app_t *app);
char **split_buffer(app_t *app, char **arr);
char **builtins_unsetenv(char **argv, char **env, app_t *app);
void free_double_array(char **arr);
char *make_new_pwd(char *fullpath);
char *return_pwd(char **env);
char *return_home(char **env);
void handle_home_arg(app_t *app);
char *return_oldpwd(char **env);
void cd_handle_oldpwd(app_t *app);
char *split_path(char *path, int i, int *lastpos, char **argv);
char **handle_quote(char *str, int i, char **arr, int *lastpos);
char **handle_cut_arg(char *str, int i, char **arr, int *lastpos);
void set_pwd_if_null(app_t *app);
void handle_exit(app_t *app, history_t *hs);
void check_if_pipe(app_t *app);
void split_exec(app_t *app, char ***arr);
void recursive_cmd(app_t *app, char ***arr);
char **check_if_bin_or_builtins(app_t *app, char ***arr);
void pferror(char *str);
void execute_right_cmd(app_t *app);
int check_if_single(app_t *app);
void print_exeption(int status, app_t *app);
char **check_if_builtins(app_t *app);
void corpse_collector(app_t *app);
void exec_pipes(app_t *app, char ***arr);
int handle_semicolons(app_t *app, char ***arr);
void corpse_collector_all_return_value(app_t *app);
int split_pipes(app_t *app, char ***arr);
int add_to_current_arg_pipes(app_t *app, char ***arr);
int add_to_current_arg_redirect(app_t *app, char ***arr);
int handle_redirection(app_t *app, char ***arr);
int handle_simple_r_r(app_t *app, char ***arr, int is_double);
char **split_buffer_redirection(char *str, int *i, char **arr, int *lastpos);
char **check_size_and_add(char *str, char **arr);
void last_split(app_t *app, char ***arr);
int last_is_singlecmd(app_t *app, char ***arr);
void free_matches(linked_list_str **matches);
void init_matches(linked_list_str **matches, char *path, char *str);
void init_globbing(char *str, app_t *app);
int check_for_delimiter(char *str);
int check_str_alphanumeric(char *str);
char *return_path(char **env);
void save_path(app_t *app);
void error_not_found(app_t *app);
void variable_env(app_t *app);
int handle_and(app_t *app, char ***arr);
int handle_or(app_t *app, char ***arr);
void check_if_or(app_t *app);
int check_if_or_and_pipe(app_t *app);
int find_and_pipe(app_t *app);
int check_mult_env(app_t *app, int i);
int check_if_or_and(app_t *app);
int check_mult_env(app_t *app, int i);
int find_and(app_t *app);
int add_to_current_arg_semicolon(app_t *app, char ***arr);
int handle_last_was_pipe(app_t *app, char ***arr);
int check_null(app_t *app);
int find_or(app_t *app);
void parse_home_char(char **str, app_t *app);
void handle_enoexec(app_t *app);
void handle_dollar(char **str, app_t *app);
char *my_getenv(char *str, char **env);
int get_egale_pos(char *str);
char *my_mstrcpy(char *str);
int check_if_is_dir(app_t *app);
int check_for_redir(app_t *app);
int handle_simple_l_r(app_t *app, char ***arr, int is_double);
void handle_double_l_r(app_t *app, char ***arr, char *str);

#endif
