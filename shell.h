#ifndef _SHELL_H_
#define _SHELL_H_
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>

#define END_OF_FILE -2
#define EXIT -3

extern char **environ;
char *name;
int hist;

/**
 * struct list_s - A new
 * @dir: A d
 * @next: A po
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new
 * @name: The na
 * @f: A functi
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - A
 * @name: T
 * @value: Th
 * @next: A point
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

alias_t *aliases;

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
ssize_t get_new_len(char *line);
alias_t *add_alias_end(alias_t **head, char *name, char *value);
list_t *get_path_dir(char *path);
list_t *add_node_end(list_t **head, char *dir);

char **_strtok(char *line, char *delim);
char *get_location(char *command);
char *_itoa(int num);
char *get_args(char *line, int *exe_ret);
char **replace_aliases(char **args);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);
char **_copyenv(void);
char **_getenv(const char *var);
char *_strchr(char *s, char c);
char *get_pid(void);
char *get_env_value(char *beginning, int len);
char *fill_path_dir(char *path);

int execute(char **args, char **front);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int _strlen(const char *s);
int _strspn(char *s, char *accept);
int (*get_builtin(char *command))(char **args, char **front);
int shellby_exit(char **args, char **front);
int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);
int shellby_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_alias(char **args, char __attribute__((__unused__)) **front);
int shellby_help(char **args, char __attribute__((__unused__)) **front);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int handle_args(int *exe_ret);
int check_args(char **args);
int create_error(char **args, int err);
int proc_file_commands(char *file_path, int *exe_ret);
int num_len(int num);
int main(int argc, char *argv[])
int cant_open(char *file_path);
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void handle_line(char **line, ssize_t read);
void free_args(char **args, char **front);
void variable_replacement(char **args, int *exe_ret);
void free_list(list_t *head);
void free_alias_list(alias_t *head);
void free_env(void);
void free_list(list_t *head);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
void logical_ops(char *line, ssize_t *new_len);
void sig_handler(int sig);


void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);

#endif
